#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
splay tree  contain int
use heap to implement
*/

int add_map[ 30005 ];
int get_map[ 30005 ];

priority_queue< int, vector<int>, less<int> > min_part;
priority_queue< int, vector<int>, greater<int> > max_part;

int main()
{
    int num;

    scanf( "%d", &num );

    for( int i = 0; i < num; i++ )
    {
        int add, get;

        while( !max_part.empty() )
            max_part.pop();

        while( !min_part.empty() )
            min_part.pop();


        scanf( "%d%d", &add, &get );

        for( int j = 0; j < add; j++ )
            scanf( "%d", &add_map[ j ] );

        for( int j = 0; j < get; j++ )
            scanf( "%d", &get_map[ j ] );

        for( int j = 0; j < get; j++ )
        {
            int len;

			if( get_map[ j ] > min_part.size() + max_part.size() )
                while( len = min_part.size() + max_part.size(), get_map[ j ] != len )
				{
					if( !max_part.empty() && add_map[ len ] > min_part.top() )
						max_part.push( add_map[ len ] );
					else
						min_part.push( add_map[ len ] );
				}

            while( j != min_part.size() )
               if( min_part.size() < j )
				{
					min_part.push( max_part.top() );
					max_part.pop();
				}
				else
				{
					max_part.push( min_part.top() );
					min_part.pop();
				}


            printf( "%d\n", max_part.top() );
        }

        if( i != num - 1 )
            printf( "\n" );
    }

    return 0;
}
