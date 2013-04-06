/*
xxxxxxxxx498765321
xxxxxxxxx512346789
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int main()
{
    char map[ 60 ];

    while( fgets( map, 55, stdin ) != NULL )
    {
        if( map[ 0 ] == '#' )
            return 0;

        int len = strlen( map );

        map[ --len ] = '\0';

        if( len == 0 )
        {
            printf( "No Successor\n" );
            continue;
        }

        for( int index = len - 1; index >= 0; index-- )
        {
            if( index == 0 )
            {
                printf( "No Successor\n" );
                break;
            }

            if( map[ index ] > map[ index - 1 ] )
            {
                for( int index_swap = len - 1; index_swap >= index; index_swap-- )
                    if( map[ index_swap ] > map[ index - 1 ] )
                    {
                        std::swap( map[ index_swap ], map[ index - 1 ] );
                        std::sort( map + index, map + len );
                        printf( "%s\n", map );
                        break;
                    }

                break;
            }
        }
    }
}
