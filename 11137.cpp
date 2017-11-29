#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max( a, b ) ( a ) > ( b ) ? ( a ) : ( b )

int map[ 21 + 1 ];
unsigned long long int dp[ 10000 ][ 21 + 1 ];

int triple( int num )
{
    return num * num * num;
}

int main()
{
    memset( dp, 0, sizeof( dp ) );

    for( int i = 1, temp; i <= 21; i++ )
        map[ i ] = triple( i );

    dp[ 0 ][ 0 ] = 1;

    for( int i = 0; i < 10000; i++ )
        for( int j = 1; j <= 21; j++ )
            if( map[ j ] <= i )
                dp[ i ][ j ] = dp[ i ][ j - 1 ] + dp[ i - map[ j ] ][ j ];
            else
                dp[ i ][ j ] = dp[ i ][ j - 1 ];

    int num;
    while( scanf( "%d", &num ) != EOF )
        printf( "%lld\n", dp[ num ][ 21 ] );

    return 0;
}
