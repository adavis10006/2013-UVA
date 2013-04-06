/*
 * PCCA Online
 * submission id: 26389
 * user: adavis10006
 * status: Accepted
 * runtime: 0.028
 * memory: 
 */
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[ 100000 + 10 ];

int main()
{
    int num, sum;
    
    while( scanf( "%d", &num ) != EOF )
    {
        for( int i = 0; i < num; i++ )
            scanf( "%d", &map[ i ] );
        
        scanf( "%d", &sum );
        
        std::sort( map, map + num );
        
        int ansa = -1, ansb = -1, a = 0, b = num - 1;
        
        while( a < b )
        {
            int temp_sum = map[ a ] + map[ b ];
            
            if( sum == temp_sum )
            {
                ansa = a;
                ansb = b;
                
                a++;
                b--;
            }
            else if( sum < temp_sum )
                b--;
            else if( sum > temp_sum )
                a++;
        }
        
        printf( "Peter should buy books whose prices are %d and %d.\n\n", map[ ansa ], map [ ansb ] );
        
    }
    
    return 0;
}
