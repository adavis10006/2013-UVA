#include <cstdio>
#include <cstdlib>
#include <map>

std::map< int, int > map, times;

int main()
{
    int input, now = 0;

    while( scanf( "%d", &input ) == 1 )
    {
        if( !times.count( input ) )
            map[ now++ ] = input; 
    
        times[ input ]++;
    }

    for( std::map< int, int >::iterator itr = map.begin(); itr != map.end(); itr++ )
        printf( "%d %d\n", itr->second, times[ itr->second ] );

    return 0;
}


