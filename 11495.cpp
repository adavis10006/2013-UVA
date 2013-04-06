/*
 * PCCA Online
 * submission id: 26387
 * user: adavis10006
 * status: Accepted
 * runtime: 0.260
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int map1[ 100000 + 10 ];
int map2[ 100000 + 10 ];


int mergesort( int *out, int *in, int front, int back )
{
	if ( front == back )
        return 0;
	
    int mid = ( front + back ) >> 1;
	
    int L = mergesort( in, out, front, mid );
	int R = mergesort( in, out, mid + 1, back );
	
    int p = front, q = mid + 1, now = front, sum = L + R;
	while ( p <= mid || q <= back )
		if ( q > back || ( p <= mid && in[ p ] <= in[ q ] ) )
			out[ now++ ] = in[ p++ ];
		else
        {
			out[ now++ ] = in[ q++ ];
			sum += mid - p + 1;
		}
    
	return sum;
}



int main()
{
    int num;
    
    while( scanf( "%d", &num ), num )
    {
        for( int i = 0; i < num; i++ )
        {
            scanf( "%d", &map1[ i ] );
            map2[ i ] = map1[ i ];
        }
        
        if ( mergesort( map1, map2, 0, num - 1 ) % 2 )
			printf("Marcelo\n");
		else
            printf("Carlos\n");
    }
    
    return 0;
}
