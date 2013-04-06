#include <cstdio>
#include <cstdlib>

bool solve( int* K_map, int* Q_map )
{
    for( int i = 0; i < 4; i++ )
        if( K_map[ i ] != -1 )
            for( int j = 0; j < 14; j++ )
                if( K_map[ i ] == Q_map[ j ] )
                    K_map[ i ] = -1;

    for( int i = 0; i < 4; i++ )
        if( K_map[ i ] != -1 )
        {
            printf( "Continue\n" );
            return false;
        }

    printf( "Stop\n" );
    return true;
}

bool checkallowed( int m, int* K_map )
{
    for( int i = 0; i < 4; i++ )
        if( m == K_map[ i ] )
            return true;
    return false;
}

bool checkmove( int m, int* Q_map )
{
    for( int i = 0; i < 14; i++ )
        if( m == Q_map[ i ] )
            return false;
    return true;
}

void solvemap( int K, int Q, int* K_map, int* Q_map )
{
    for( int i = 0; i < 4; i++ )
        K_map[ i ] = -1;
    for( int i = 0; i < 14; i++ )
        Q_map[ i ] = -1;

    K_map[ 0 ] = K - 8 >= 0 && K - 8 != Q ? K - 8 : -1;
    K_map[ 1 ] = ( K - 1 ) >= 0 && ( K - 1 ) % 8 != 7 && K - 1 != Q ? K - 1 : -1;
    K_map[ 2 ] = ( K + 1 ) % 8 != 0 && K + 1 != Q ? K + 1 : -1;
    K_map[ 3 ] = K + 8 < 64 && K + 8 != Q ? K + 8 : -1;

    int index = 0, temp = Q;
    while( true )
    {
        temp -= 8;
        if( temp >= 0 && temp != K )
            Q_map[ index++ ] = temp;
        else
            break;
    }

    temp = Q;
    while( true )
    {
        temp--;
        if( temp >= 0 && temp % 8 != 7 && temp != K )
            Q_map[ index++ ] = temp;
        else
            break;
    }

    temp = Q;
    while( true )
    {
        temp++;
        if( temp % 8 != 0 && temp != K )
            Q_map[ index++ ] = temp;
        else
            break;
    }

    temp = Q;
    while( true )
    {
        temp += 8;
        if( temp < 64 && temp != K )
            Q_map[ index++ ] = temp;
        else
            break;
    }

    for( int i = index; i < 14; i++ )
        Q_map[ i ] = -1;
}
int main()
{
    int K,Q,m;
    int K_map[ 4 ], Q_map[ 14 ];

    while( scanf( "%d%d%d", &K,&Q, &m ) != EOF )
    {
        if( K == Q )
        {
            printf( "Illegal state\n" );
            continue;
        }

        solvemap( K, Q, K_map, Q_map );

        if( checkmove( m, Q_map ) )
        {
            printf( "Illegal move\n" );
            continue;
        }

        if( checkallowed( m, K_map ) )
        {
            printf( "Move not allowed\n" );
            continue;
        }

        solvemap( K, m, K_map, Q_map );

        solve( K_map, Q_map );
    }
}
