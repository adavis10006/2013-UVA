#include <cstdio>
#include <cstdlib>
#include <cstring>

#define task_time 1000000

bool map[ task_time + 10 ];

int main()
{
    int n, m, from, end, interval;

    while( scanf( "%d%d", &n, &m ) )
    {
        if( n == 0 && m == 0 )
            break;

        memset( map, false, sizeof( map ) );

        bool conflict = false;

        for( int i = 0; i < n; i++ )
        {
            scanf( "%d%d", &from, &end );

            for( int i = from; i < end; i++ )
                if( map[ i ] )
                    conflict = true;
                else
                    map[ i ] = true;
        }

        for( int i = 0; i < m; i++ )
        {
            scanf( "%d%d%d", &from, &end, &interval );

            while( true )
            {
                for( int i = from; i < end && i < task_time; i++ )
                    if( map[ i ] )
                        conflict = true;
                    else
                        map[ i ] = true;

                from += interval;
                end +=interval;

                if( from > task_time )
                    break;
            }
        }

        if ( conflict )
            printf ("CONFLICT\n");
		else
            printf ("NO CONFLICT\n");
    }


    return 0;
}
