#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define pirate_num 1024000
#define command_num 1000

int map[ pirate_num + 10 ];
int range[ command_num * 2 + 20 ];
int range_map[ pirate_num + 10 ];
int num[ command_num * 2 + 20 ];

struct Command
{
    char type;
    int from, end;
}command[ command_num + 10 ];

int count( int from, int end )
{
    int ans = 0;
    
    for( int i = from; i < end; i++ )
        ans += map[ i ];
    
    return ans;
}

int search( int num, int size )
{
    for( int i = 0; i < size; i++ )
        if( range[ i ] == num )
            return i;
}

int main()
{
    int ncase, initial, times, instruction;;
    char input[ 55 ], type;

    scanf( "%d", &ncase );

    for( int i = 0; i < ncase; i++ )
    {
        map[ 0 ] = '\0';

        printf( "Case %d:\n", i + 1 );

        scanf( "%d", &initial );

        int N = 0;
        
        for( int j = 0; j < initial; j++ )
        {
            scanf( "%d%s", &times, input );

            for( int k = 0; k < times; k++ )
                for( int l = 0; input[ l ]; l++, N++ )
                    map[ N ] = input[ l ] - '0';
        }

        scanf( "%d", &instruction );

        for( int j = 0; j < instruction; j++ )
        {
            scanf( "\n%c%d%d", &command[ j ].type, &command[ j ].from, &command[ j ].end );
            range[ j << 1 ] = command[ j ].from;
            range[ j << 1 | 1 ] = ++command[ j ].end;
        }

        std::sort( range, range + ( instruction << 1 ) );

        int segment = 0;

        range_map[ range[ 0 ] ] = segment;

        for( int j = 1; j < instruction << 1; j++ )
            if( range[ j ] != range[ segment ] )
            {
                num[ segment ] = count( range[ segment ], range[ j ] );
                range[ ++segment ] = range[ j ];
                range_map[ range[ j ] ] = segment;
            }
        segment++;

        int question = 1;
        
        for( int j = 0, from, end; j < instruction; j++ )
        {
            from = range_map[ command[ j ].from ];
            end = range_map[ command[ j ].end ];

            switch( command[ j ].type )
            {
                case 'F':
                    for( int k = from; k < end; k++ )
                        num[ k ] = range[ k + 1 ] - range[ k ];

                    break;
                case 'E':
                    for( int k = from; k < end; k++ )
                        num[ k ] = 0;

                    break;
                case 'I':
                    for( int k = from; k < end; k++ )
                        num[ k ] = range[ k + 1 ] - range[ k ] - num[ k ];

                    break;
                case 'S':
                    int ans = 0;
                    
                    for( int k = from; k < end; k++ )
                            ans += num[ k ];

                    printf( "Q%d: %d\n", question++, ans );

                break;
            }
#ifdef DEBUG            
        for( int j = 1; j < segment; j++ )   
            printf( "%d %d %d\n", range[ j - 1 ], range[ j ], num[ j - 1 ] );
        printf( "\n" );
#endif
        }
    }
    return 0;
}
