#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int num, map[ 20 ];
double from, end, ans;
double count( double number )
{
	double temp_IRR = 1, anser = 0;
	for( int i = num; i >= 0; i--, temp_IRR *= number + 1 )
	{
		anser += map[ i ] * temp_IRR;
		//printf( "count %.02f %d %.02f\n", anser, map[ i ], temp_IRR );
	}
	return anser;
}

bool b_search()
{
	double mid = ( from + end ) / 2;

	if( from <= end && from + 0.001 >= end )
	{
		ans = mid;
		return true;
	}

	double from_ans = count( from ), mid_ans = count( mid ),  end_ans = count( end );

	//printf( "bsera %.02f %.02f\n", from_ans, end_ans );

	if( from_ans == 0 )
	{
		ans = from;
		return true;
	}
	else if( end_ans == 0 )
	{
		ans = end;
		return true;
	}
	else if( mid_ans == 0 )
	{
		ans = mid;
		return true;
	}
	else if( from_ans > 0 && end_ans > 0 )
		from = end, end = end * 2;
	else if( mid_ans > 0 )
		from = mid;
	else
		end = mid;

	return false;
}
int main()
{
	while( scanf( "%d", &num ), num != 0 )
	{
		scanf( "%d", &map[ 0 ] );
		for( int i = 0; i < num; i++ )
			scanf( "%d", &map[ i + 1 ] );
	/*
		for( int i = 0; i <= num; i++ )
			printf( "%d ", map[ i ] );
		printf( "\n" );
	*/
		from = -1, end = 1;
		while( !b_search() );

		printf( "%.02f\n", ans );
	}

	return 0;
}
