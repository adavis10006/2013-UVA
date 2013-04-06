#include <cstdio>
#include <cstdlib>
#include <cstring>

bool checkfinish( bool* anser_map, int length )
{
    for( int i = 0; i < length; i++ )
        if( !anser_map[ i ] )
            return false;
    return true;
}

int main()
{
    int  round;
    char anser[ 10000 ], trychar[ 10000 ];
    bool anser_map[ 10000 ], alphe_map[ 26 ];
    char* ptr;

    while( scanf( "%d", &round ) , round != -1 )
    {
        printf( "Round %d\n", round );

        scanf( "%s%s", anser, trychar );

        memset( anser_map, false, strlen( anser ) );
        memset( alphe_map, false, 26 );

        int stroke = 0;
        for( int i = 0; i < strlen( trychar ); i++ )
        {
            if( stroke == 7 )
            {
                printf( "You lose.\n" );
                goto restart;
            }

            if( checkfinish( anser_map, strlen( anser ) ) )
            {
                printf( "You win.\n" );
                goto restart;
            }

            if( alphe_map[ trychar[ i ] - 'a' ] )
                continue;
            alphe_map[ trychar[ i ] - 'a' ] = true;

            ptr = strchr( anser, trychar[ i ] );

            if( ptr == NULL )
                stroke++;
            else
                while( ptr != NULL )
                {
                    anser_map[ ptr - anser ] = true;
                    ptr = strchr( ptr + 1, trychar[ i ] );
                }
        }

        if( stroke == 7 )
            printf( "You lose.\n" );
        else if( checkfinish( anser_map, strlen( anser ) ) )
            printf( "You win.\n" );
        else
            printf( "You chickened out.\n" );
restart:
    ;
    }

    return 0;
}
