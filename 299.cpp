/*
 * PCCA Online
 * submission id: 25557
 * user: adavis10006
 * status: Accepted
 * runtime: 0.008
 * memory: 
 */
#include <cstdio>
#include <cstdlib>


int main()
{
	int N, n;
	int map[ 51 ];
	
	scanf( "%d\n", &N );
	for( int time = 0; time < N; time++ )
	{
		int sum = 0;
		
		scanf( "%d\n", &n );
	
		for( int i = 0; i < n; i++ )
			scanf( "%d", &map[ i ] );

		for( int i = 0; i < n - 1; i++ )
			for( int j = i + 1; j < n; j++ )
			{
				if( map[ i ] > map[ j ] )
				{
					int temp = map[ i ];
					map[ i ] = map[ j ];
					map[ j ] = temp;

					sum++;
				}
			}

		printf( "Optimal train swapping takes %d swaps.\n", sum );
	}
	
	return 0;
}

