#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[ 100 + 5 ][ 100 + 5 ], sum[ 100 + 5 ][ 100 + 5 ];

int main()
{
    int num;

    scanf( "%d", &num );
    memset( sum, 0, sizeof( sum ) );

    for( int i = 1; i <= num; i++ )
        for( int j = 1; j <= num; j++ )
            scanf( "%d", &map[ i ][ j ] );

    for( int i = 1; i <= num; i++ )
        for( int j = 1; j <= num; j++ )
             for( int ii = 1; ii <= i; ii++ )
                for( int jj = 1; jj <= j; jj++ )
                    sum[ i ][ j ] += map[ ii ][ jj ];

    int ans = sum[ 0 ][ 0 ];
    for( int i = 1; i <= num; i++ )
        for( int j = 1; j <= num; j++ )
            for( int ii = i; ii <= num; ii++ )
                for( int jj = j; jj <= num; jj++ )
                {
                    int temp = sum[ ii ][ jj ] - sum[ i - 1 ][ jj ] - sum[ ii ][ j - 1 ] + sum[ i - 1 ][ j - 1 ];
                    if( temp > ans )
                        ans = temp;
                }

    printf( "%d\n", ans );

    return 0;
}
