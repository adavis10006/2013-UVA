/*
 * PCCA Online
 * submission id: 26172
 * user: adavis10006
 * status: Accepted
 * runtime: 0.640
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#define N 100005

std::map< std::string, int > map;
int header[ N ], friends[ N ];

void initial()
{
    for( int i = 0; i < N; i++ )
        header[ i ] = i;
}

int head( int pos )
{
    int father = pos;
    while( father != header[ father ] )
        father = header[ father ];

    while( pos != father )
    {
        int temp = pos;
        pos = header[ pos ];
        header[ temp ] = father;
    }

    return father;
}

int friendship( int map1, int map2 )
{
    int header1 = head( map1 ), header2 = head( map2 );
    if( header1 != header2 )
    {
        header[ header1 ] = header2;
        friends[ header2 ] += friends[ header1 ];
    }

    return friends[ head( header1 ) ];
}

int main()
{
    int num;

    scanf( "%d", &num );

    for( int i = 0; i < num; i++ )
    {
        map.clear();
        initial();


        int times;
        char namec1[ 22 ],namec2[ 22 ];

        scanf( "%d", &times );

        int pos = 1;

        for( int i = 0; i < times; i++ )
        {
            scanf( "%s %s", namec1, namec2 );

            int map1, map2;
            std::string name1(namec1), name2(namec2);

            if( ( map1 = map[ name1 ] ) == 0 )
            {
                map1 = map[ name1 ] = pos++;
                friends[ pos - 1 ] = 1;
            }

            if( ( map2 = map[ name2 ] ) == 0 )
            {
                map2 = map[ name2 ] = pos++;
                friends[ pos - 1 ] = 1;
            }

            printf( "%d\n", friendship( map1, map2 ) );
        }
    }

    return 0;
}

