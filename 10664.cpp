#include <cstdio>
#include <cstdlib>
#include <cstring>

#define max( a, b ) ( a ) > ( b ) ? ( a ) : ( b )

int map[ 20 + 5 ];
int dp[ 200 + 5 ][ 20 + 5 ];

int main()
{
    int num;

    scanf( "%d", &num );

    while( num-- )
    {
        char c;
        int index = 1, sum = 0;
        while( scanf( "%d", &map[ index ] ), sum += map[ index++ ], ( c = getchar() ) == ' ' );

        if( sum % 2 != 0 )
            printf( "NO\n" );
        else
        {
            memset ( dp, 0, sizeof( dp ) );

            sum >>= 1;
            for( int i = 0; i <= sum; i++ )
                for( int j = 1; j < index; j++ )
                    if( map[ j ] <= i  )
                        dp[ i ][ j ] = max( dp[ i ][ j - 1 ], dp[ i - map[ j ] ][ j - 1 ] + map[ j ] );

            if( dp[ sum ][ index - 1 ] == sum )
                printf( "YES\n" );
            else
                printf( "NO\n" );
        }
    }

    return 0;
}
