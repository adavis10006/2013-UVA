#include <cstdio>
#include <cstdlib>
#include <vector>

#define alpha_num 26

std::vector< int > wake;

bool map[ alpha_num ][ alpha_num ];
int counter[ alpha_num ];


int BFS( int num )
{

    for( int i = 0; i < alpha_num; i++ )
        if( counter[ i ] == -1 )
            for( int j = 0; j < alpha_num; j++ )
                if( map[ i ][ j ] && counter[ j ] != -1 )
                    counter[ j ]++;


    int done = 0;
    bool counter_change = false;

    for( int i = 0; i < alpha_num; i++ )
        if( counter[ i ] == -1 )
            done++;
        else if( counter[ i ] >= 3 )
        {
            counter_change = true;
            counter[ i ] = -1;
            done++;
        }
        else
            counter[ i ] = 0;

    if( done == num )
        return 1;

    if( !counter_change )
        return 2;


    return 0;
}


int main()
{
    int num;
    int connect;
    char stimulation[ 4 ];

    while( scanf( "%d%d%s", &num, &connect, stimulation ) != EOF )
    {
        for( int i = 0; i < alpha_num; i++ )
        {
            for( int j = 0; j < alpha_num; j++ )
                map[ i ][ j ] = false;

            counter[ i ] = 0;
        }

        for( int i = 0; i < 3; i++ )
            counter[ stimulation[ i ] - 'A' ] = -1;

        char connection[ 3 ];

        for( int i = 0; i < connect; i++ )
        {
            scanf( "%s", connection );

            map[ connection[ 0 ] - 'A' ][ connection[ 1 ] - 'A' ] = true;
            map[ connection[ 1 ] - 'A' ][ connection[ 0 ] - 'A' ] = true;
        }

        if( num == 3 )
        {
            printf( "WAKE UP IN, 0, YEARS\n" );
            continue;
        }

        int BFS_state, day = 0;

        while( ++day )
            if( ( BFS_state = BFS( num ) ) != 0 )
                break;

        if( BFS_state == 1 )
            printf( "WAKE UP IN, %d, YEARS\n", day );
        if( BFS_state == 2 )
            printf( "THIS BRAIN NEVER WAKES UP\n" );
    }


    return 0;
}
