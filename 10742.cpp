/*
 * PCCA Online
 * submission id: 26549
 * user: adavis10006
 * status: Accepted
 * runtime: 0.264
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000000

int prime[ 100000 ], prime_num = 0;

void init()
{
	for( int i = 2; i <= MAX; i++ )
	{
		bool is_prime = true;
		for( int j = 0; j < prime_num && prime[ j ] * prime[ j ] <= i; j++ )
			if( i % prime[ j ] == 0 )
			{	
				is_prime = false;
				break;
			}

		if( is_prime )
			prime[ prime_num++ ] = i;
	}


}

int b_search( int from, int end, int num )
{
	if( from == end )
		return from;

	int mid = ( from + end ) >> 1;

	if( prime[ mid ] == num )
		return mid + 1;
	else if( prime[ mid ] > num )
		return b_search( 0, mid, num );
	else if( prime[ mid ] < num )
		return b_search( mid + 1, end, num );
}

int main()
{
    init();

	int T = 0, num;

	while( scanf( "%d", &num ), num )
	{
		int ans = 0;

		int max_prime = b_search( 0, prime_num, num - 2 );

		for( int i = 1; i < max_prime; i++ )
			ans += b_search( 0, i, num - prime[ i ] );
		printf( "Case %d: %d\n", ++T, ans );
	}

    return 0;
}

