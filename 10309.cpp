#include <cstdio>
#include <cstdlib>
#include <cstring>

#define min( a, b ) ( a ) < ( b ) ? ( a ): ( b )
#define max( a, b ) ( a ) > ( b ) ? ( a ): ( b )

bool map[ 10 ][ 10 ], set[ 10 ][ 10 ];
int ans;

void press( int i, int j )
{
    for( int ii = max( 0, i - 1 ), end = min( 9, i + 1 ); ii <= end; ii++ )
        set[ ii ][ j ] = !set[ ii ][ j ];
    for( int jj = max( 0, j - 1 ), end = min( 9, j + 1 ); jj <= end; jj++ )
        set[ i ][ jj ] = !set[ i ][ jj ];
    set[ i ][ j ] = !set[ i ][ j ];
}

int main()
{
    char name[ 10000 ], input[ 15 ];
    
    while( scanf( "%s", name ), strcmp( name, "end" ) != 0 )
    {
        ans = -1;
        for( int i = 0; i < 10; i++ )
        {
            scanf( "%s", input );
            for( int j = 0; j < 10; j++ )
                if( input[ j ] == '#' )
                    map[ i ][ j ] = false;
                else
                    map[ i ][ j ] = true;
        }
        
        for( int i = 0; i < 1024; i++ )
        {
            int temp_ans = 0;
            memcpy( set, map, sizeof( set ) );
            
            for( int jj = 0; jj < 10; jj++ )
                if( ( i >> jj ) & 1 )
                    press( 0, jj ), temp_ans++;
        
            for( int ii = 1; ii < 10; ii++ )
                for( int jj = 0; jj < 10; jj++ )
                    if( set[ ii - 1 ][ jj ] )
                        press( ii, jj ), temp_ans++;
            
            bool all_off = true;
            for( int ii = 0; ii < 10; ii++ )
                if( set[ 9 ][ ii ] )
                {
                    all_off = false;
                    break;
                }
            
            if( all_off && temp_ans <= 100 && ( ans == -1 || temp_ans < ans ) )
                ans = temp_ans;
        }
        
        printf( "%s %d\n", name, ans );
    }
    return 0;
}
