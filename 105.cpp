#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

std::map< int, int > range_map;
int range[ 10000 + 10 ];
int value[ 10000 + 10 ];

struct building
{
    int front, back, value;
} build[ 5000 + 10 ];

int main()
{
    int num = 0, segment = 0;
    range_map.clear();
    memset( value, 0, sizeof( value ) );

    while( scanf( "%d%d%d", &build[ num ].front, &build[ num ].value, &build[ num ].back ) != EOF )
    {
        range[ num << 1 ] = build[ num ].front;
        range[ num << 1 | 1 ] = build[ num ].back; 
        num++;  
    }

    std::sort( range, range + ( num << 1 ) );

    for( int i = 0; i < num << 1; i++ )
        if( range_map.count( range[ i ] ) == 0 )
        {    
            range[ segment ] = range[ i ];
            range_map[ range[ i ] ] = segment++;
        }

    for( int i = 0;  i < num; i++ )
        for( int j = range_map[ build[ i ].front ]; j < range_map[ build[ i ].back ]; j++ )
            if( value[ j ] < build[ i ].value )
                value[ j ] = build[ i ].value;


    for( int i = 0, temp = -1; i < segment; i++ )
        if( i == 0 )
        {
            printf( "%d %d", range[ i ], value[ i ] );
            temp = value[ i ];
        }
        else if( value[ i ] != temp )
        {
            printf( " %d %d", range[ i ], value[ i ] );
            temp = value[ i ];
        }
    printf( "\n" );

    return 0;
}
