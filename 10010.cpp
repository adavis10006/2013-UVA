#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>

#define MAXNUM 50

bool check( char map[ MAXNUM + 1 ][ MAXNUM + 1 ], char* cmp, int index, int row, int col, int rid, int cid, int rsh, int csh )
{
    if( rid < 0 || rid >= row || cid < 0 || cid >= col )
        return false;

    if( tolower( ( int ) cmp[ index ] ) != tolower( ( int ) map[ rid ][ cid ] ) )
        return false;

    if( strlen( cmp ) == index + 1 )
        return true;
    
    return check( map, cmp, index + 1, row, col, rid + rsh, cid + csh, rsh, csh );
}

int main()
{
    int num;
    int row, col;
    int test;

    char map[ MAXNUM + 1 ][ MAXNUM + 1 ];
    char cmp[ MAXNUM + 1 ];

    std::cin >> num;

    while( num-- > 0 )
    {
        int ans = 0;

        memset( map, 0x00, sizeof( map ) );
        
        std::cin >> row >> col;

        getchar();
        for( int rid = 0; rid < row; rid++ )
            fgets( map[ rid ], MAXNUM, stdin );

        std::cin >> test;

        getchar();
        for( int tid = 0; tid < test; tid++ )
        {
            fgets( cmp, MAXNUM, stdin );
            cmp[ strlen( cmp ) - 1 ] = '\0';

            for( int rid = 0; rid < row; rid++ )
                for( int cid = 0; cid < col; cid++ )
                {
                    if( check( map, cmp, 0, row, col, rid, cid, 0, 1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, 1, 1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, 1, 0 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, 1, -1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, 0, -1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, -1, -1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, -1, 0 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                    if( check( map, cmp, 0, row, col, rid, cid, -1, 1 ) )
                    {    
                        std::cout << rid + 1 << " " << cid + 1 << std::endl;
                        goto restart;
                    }
                }
restart:
;
        }

        if( num > 0 )
            std::cout << std::endl;
    }

    return 0;
}
