#include <cstdio>
#include <queue>

enum color_set
{
    none,
    black,
    white
};

int main()
{
    int point_num, connect_num;
    bool map[ 200 ][ 200 ];
    color_set color[ 200 ];
    
    while( true )
    {
restart:        
        scanf( "%d", &point_num );
    
        if( point_num == 0 )
            break;

        for( int row = 0; row < point_num; row++ )
            for( int col = 0; col < point_num; col++ )
                map[ row ][ col ] = false;

        for( int cur = 0; cur < point_num; cur++ )
            color[ cur ] = none;

        scanf( "%d", &connect_num );

        for( int cur = 1; cur <= connect_num; cur++ )
        {
            int from, end;

            scanf( "%d %d", &from, &end );

            map[ from ][ end ] = true;
            map[ end ][ from ] = true;
        }

        std::queue< int > check_queue;

        color[ 0 ] = black;
        check_queue.push( 0 );

        while( check_queue.size() != 0 )
        {
            int         now   = check_queue.front();
            color_set   check = color[ now ];
            
            for( int cur = 0; cur < point_num; cur++ )
                if( now != cur && map[ now ][ cur ] )
                    if( color[ cur ] == none )
                    {
                        color[ cur ] = check == white ? black : white;
                        check_queue.push( cur );
                    }
                    else if( color[ cur ] == check )
                    {
                        printf( "NOT BICOLORABLE.\n" );
                        goto restart;
                    }

            check_queue.pop();
        }

        printf( "BICOLORABLE.\n" );
    }

    return 0;
}
