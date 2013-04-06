/*
 * PCCA Online
 * submission id: 26238
 * user: adavis10006
 * status: Accepted
 * runtime: 0.116
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[ 1025 + 5 ][ 1025 + 5 ];

int min( int number ) 
{
	return number >= 1 ? number : 1;
}

int max( int number ) 
{
	return number <= 1025 ? number : 1025;
}

int main()
{
	int T;

	scanf( "%d", &T );

	while( T-- )
	{
		int d, r;

		scanf( "%d%d", &d, &r );

		memset( map, 0, sizeof( map ) );

		for( int i = 0, x, y, num; i < r; i++ )
		{	
			scanf( "%d%d%d", &x, &y, &num );
#ifdef Debug
			printf( "%d %d %d %d %d\n", min( x - d ), max( x + d ), min( y - d ), max( y + d ), num );
#endif
			for( int j = min( x - d ); j <= max( x + d ); j++ )
				for( int k = min( y - d ); k <= max( y + d ); k++ )
					map[ j ][ k ] += num;
		}

		int ans = -1, ansx = -1, ansy = -1;

		for( int i = 1; i <= 1025; i++ )
			for( int j = 1; j <= 1025; j++ )
				if( map[ i ][ j ] > ans )
				{
					ans = map[ i ][ j ];
					ansx = i;
					ansy = j;
				}

		printf( "%d %d %d\n", ansx, ansy, ans );
	}
	
	return 0;
}
