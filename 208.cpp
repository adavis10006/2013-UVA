#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

bool map[ 21 + 5 ][ 21 + 5 ], mark[ 21 + 5 ], reach[ 21 + 5 ];
int reachable[ 21 + 5 ], reach_num, ans;
std::vector< int > route;

void show_route()
{
    for( int i = 0; i < route.size(); i++ )
        if( i != 0 )
            printf( " %d", route[ i ] + 1 );
        else
            printf( "%d", route[ 0 ] + 1 );
    printf( "\n" );
}

void DFS_init( int corner )
{
    reach[ corner ] = true;
    reachable[ reach_num++ ] = corner;

    for( int i = 0; i < 21; i++ )
        if( map[ corner ][ i ] && !reach[ i ] )
            DFS_init( i );
}

void DFS( int now, int fire )
{
    route.push_back( now );
    mark[ now ] = true;

    if( now == fire )
    {
        ans++;

        show_route();

        mark[ now ] = false;
        route.pop_back();

        return;
    }

    for( int i = 1; i < reach_num; i++ )
        if( !mark[ reachable[ i ] ] && map[ now ][ reachable[ i ] ] )
            DFS( reachable[ i ], fire );

    mark[ now ] = false;
    route.pop_back();
}

int main()
{
    int num = 1, fire;

    while( scanf( "%d", &fire ) != EOF )
    {
        memset( map, false, sizeof( map ) );
        memset( reach, false, sizeof( reach ) );
        memset( mark, false, sizeof( mark ) );
        memset( reachable, 0, sizeof( reachable ) );
        route.clear();
        reach_num = ans = 0;

        printf( "CASE %d:\n", num++ );

        int from, to;
        while( scanf( "%d%d", &from, &to ), from != 0 && to != 0 )
        {
            map[ from - 1 ][ to - 1 ] = true;
            map[ to - 1 ][ from - 1 ] = true;
        }

        DFS_init( fire - 1 );
        std::sort( reachable, reachable + reach_num );
        DFS( 0, fire - 1 );

        printf( "There are %d routes from the firestation to streetcorner %d.\n", ans, fire );
    }

    return 0;
}
