/*
 * PCCA Online
 * submission id: 25885
 * user: adavis10006
 * status: Accepted
 * runtime: 0.016
 * memory: 
 */
#include <cstdio>
#include <cstdlib>

int weight[] = { 2, 3, 5, 7 }; 
int priority[ 4 ] = { 0, 0, 0, 0 };
int map[ 5843 ];
int now = 1;

void solve()
{
	map[ now++ ] = 1;

	while( now != 5843 )
	{
		int min = -1;
		for( int i = 0; i < 4; i++ )
		{
			while( map[ priority[ i ] ]  <= map[ now - 1 ] / weight[ i ] )
				priority[ i ]++;

			if( min == -1 || min > map[ priority[ i ] ] * weight[ i ] )
				min = map[ priority[ i ] ] * weight[ i ];
		}
		
		map[ now++ ] = min;
	}
}

int main()
{
	int n;
	
	solve();
	
	while( scanf( "%d", &n ), n != 0 )
	{
		if( n % 100 == 11 || n % 100 == 12 || n % 100 == 13 )
			printf( "The %dth humble number is %d.\n", n, map[ n ] );
		else if( n % 10 == 1 )	
			printf( "The %dst humble number is %d.\n", n, map[ n ] );
		else if( n % 10 == 2 )	
			printf( "The %dnd humble number is %d.\n", n, map[ n ] );
		else if( n % 10 == 3 )	
			printf( "The %drd humble number is %d.\n", n, map[ n ] );
		else
			printf( "The %dth humble number is %d.\n", n, map[ n ] );
	}

	return 0;
}
