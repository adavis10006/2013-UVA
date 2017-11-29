#include <cstdio>
#include <cstdlib>
#include <cstring>

#define range 5000000 + 2

int map[ range ];
int deprime[ range ];
bool prime[ range ];

void init()
{
    prime[ 0 ] = prime[ 1 ] = false;
    for( int i = 2; i < range; i++ )
    {
        if( prime[ i ] )
            for( int ii = i; ii < range; ii += i )
            {
                if( ii != i )
                    prime[ ii ] = false;
                map[ ii ] += i;
            }

        if( prime[ map[ i ] ] )
            deprime[ i ] = deprime[ i - 1 ] + 1;
        else
            deprime[ i ] = deprime[ i - 1 ];
    }
}


int main()
{
    memset( map, 0, sizeof( map ) );
    memset( deprime, 0, sizeof( deprime ) );
    memset( prime, true, sizeof( prime ) );

    init();

    int from, end;

    while( scanf( "%d", &from ), from != 0 )
    {
        scanf( "%d", &end );
        printf( "%d\n", deprime[ end ] - deprime[ from - 1 ] );
    }

    return 0;
}
