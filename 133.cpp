#include <cstdio>
#include <cstdlib>
#include <vector>

int main()
{
    int N, m, k;
    bool track[ 20 ];

    while( scanf( "%d%d%d", &N, &m, &k ) != EOF )
    {
        if( N == 0 && m == 0 && k == 0 )
            return 0;

        int tempm = N - 1, tempk = 0, time, alive = N;
        for( int i = 0; i < N; i++ )
            track[ i ] = false;

        while( true )
        {
            time = m;
            while( time != 0 )
            {
                tempm = ( tempm + 1 ) % N;
                if( track[ tempm ] )
                    continue;
                time--;
            }

            time = k;
            while( time != 0 )
            {
                tempk = ( tempk + N - 1 ) % N;
                if( track[ tempk ] )
                    continue;
                time--;
            }

            if( tempm == tempk )
            {
                printf( "%3d", tempm + 1 );
                track[ tempm ] = true;
                alive--;
            }
            else
            {
                printf( "%3d%3d", tempm + 1, tempk + 1 );
                track[ tempm ] = true;
                track[ tempk ] = true;
                alive-=2;
            }

            if( alive != 0 )
                printf( "," );
            else
            {
                printf( "\n" );
                break;
            }
        }
    }
}
