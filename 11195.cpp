#include <cstdio>
#include <cstdlib>

/*
1 can	put
0 cant	put

*/

int board[ 14 + 5 ];
int num;

void DFS( int n, int index, int vertical, int right_slash, int left_slash )
{
	if( n == index )
	{
		num++;
		return;
	}

	int putqueen = board[ index ] & vertical & right_slash & left_slash;

	while( putqueen )
	{
		int put = putqueen & -putqueen;

		DFS( n, index + 1, vertical ^ put, ( ( right_slash ^ put ) >> 1 ) ^ ( 1 << n - 1 ), ( ( left_slash ^ put ) << 1 ) ^ 1 );
	
		putqueen ^= put;
	}
}


int main()
{
	int n, Case = 1;

	while( scanf( "%d", &n ), n !=0 )
	{
		num = 0;

		for( int i = 0; i < n; i++ )
		{
			board[ i ] = ( 1 << n ) - 1;
	
			char input[ 14 + 5 ];

			scanf( "%s", input );
		
			for( int j = 0; j < n; j++ )
				if( input[ j ] == '*' )
					board[ i ] ^= 1 << j; 
		}
	
		DFS( n, 0, ( 1 << n ) - 1, ( 1 << n ) - 1,  ( 1 << n ) - 1 );
	
		printf( "Case %d: %d\n", Case++, num );
	}

	return 0;
}