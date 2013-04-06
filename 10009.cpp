#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXBUFFER 1000
#define ALPHA_NUM 26

void solve( int map[ ALPHA_NUM ][ ALPHA_NUM ], int pre[ ALPHA_NUM ][ ALPHA_NUM ] )
{
    for( int pid = 0; pid < ALPHA_NUM; pid++ )
        for( int fid = 0; fid < ALPHA_NUM; fid++ )
            if( fid != pid )
                for( int eid = 0; eid < ALPHA_NUM; eid++ )
                    if( eid != fid && eid != pid )
                        if( map[ fid ][ pid ] > 0 && map[ pid ][ eid ] > 0 )
                            if( map[ fid ][ eid ] == -1 || map[ fid ][ pid ] + map[ pid ][ eid ] < map[ fid ][ eid ] )
                            {
                                map[ fid ][ eid ] = map[ fid ][ pid ] + map[ pid ][ eid ];
                                pre[ fid ][ eid ] = pid;

                                map[ eid ][ fid ] = map[ fid ][ eid ];
                                pre[ eid ][ fid ] = pid;
                            }
}       

void shortest_path( int fid, int eid, int pre[ ALPHA_NUM ][ ALPHA_NUM ] )
{
    if( pre[ fid ][ eid ] == -1 )
        printf( "%c", 'A' + fid );
    else
    {
        shortest_path( fid, pre[ fid ][ eid ], pre );
        shortest_path( pre[ fid ][ eid ], eid, pre );
    }
}

int main()
{
    int     num;
    int     node, test;
    char    from[ MAXBUFFER ], end[ MAXBUFFER ];
    int     map[ ALPHA_NUM ][ ALPHA_NUM ], pre[ ALPHA_NUM ][ ALPHA_NUM ];

    std::cin >> num;

    while( --num >= 0 )
    {
        memset( map, 0xff, sizeof( map ) );
        memset( pre, 0xff, sizeof( pre ) );

        std::cin >> node >> test;

        for( int index = 0, fid, eid; index < node; index++ )
        {    
            std::cin >> from >> end;
            
            fid = from[ 0 ] - 'A';
            eid = end[ 0 ] - 'A';
            
            map[ fid ][ eid ] = 1;
            map[ eid ][ fid ] = 1;
        }

        solve( map, pre );

        for( int index = 0, fid, eid; index < test; index++ )
        {
            std::cin >> from >>  end;

            fid = from[ 0 ] - 'A';
            eid = end[ 0 ] - 'A';
            
            shortest_path( fid, eid, pre );
            printf( "%c\n", end[ 0 ] );
        }

        if( num > 0 )
            printf( "\n" );
    }

    return 0;
}
