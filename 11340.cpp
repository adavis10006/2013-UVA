#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int N, K, M;
    int map[ 256 ];
    scanf( "%d\n", &N );

    for( int i = 0; i < N; i++ )
    {
        char input;
        int ans = 0;
        memset( map, 0, sizeof( map ) );

        scanf( "%d\n", &K );

        for( int j = 0; j < K; j++ )
        {
            scanf( "%c", &input );
            scanf( "%d\n", &map[ ( int )input + 128 ] );
        }

        scanf( "%d\n", &M );

        for( int j = 0; j < M; j++ )
        {
            while( ( input = getchar() ) != '\n' )
            {
                if( input == '\n' )
                    break;

                ans += map[ input + 128 ];
            }
        }
        printf( "%d.%02d$\n", ans / 100, ans % 100 );
    }

    return 0;
}
