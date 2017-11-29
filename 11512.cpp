#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_CASE 100
#define MAX_LENGTH 1000

char input[ MAX_LENGTH ];

int array_index[ MAX_LENGTH ];
int lcp[ MAX_LENGTH ]; //length
int max_index, repeat_time;

int compare_string( const void* a, const void* b )
{
	return strcmp( input + *( int* ) a, input + *( int* )b );
}

void quick_sort( int length )
{
	qsort( array_index, length, sizeof( int ), compare_string ); 
}

void count_lcp( int length )
{
	lcp[ array_index[ 0 ] ] = 0;

	for( int i = 1; i < length; i++ )
	{
		int lcp_length = 0;
		
		while( input[ array_index[ i - 1 ] + lcp_length ] == input[ array_index[ i ] + lcp_length ]  && array_index[ i ] + lcp_length < length )
			lcp_length++;

		lcp[ array_index[ i ] ] = lcp_length;
	}
}

bool suffix_array()
{
	int length = strlen( input );

	for( int i = 0; i < length; i++ )
			array_index[ i ] = i;

	quick_sort( length );

	count_lcp( length );

	max_index = array_index[ 0 ];
	repeat_time = 0;

	for( int i = 0; i < length; i++ )
		if( lcp[ array_index[ i ] ] > lcp[ max_index ] || ( lcp[ array_index[ i ] ] == lcp[ max_index ] && strncmp( input + array_index[ i ], input + max_index, lcp[ max_index ] ) < 0 ) )
			max_index = array_index[ i ];
	
	if( max_index == array_index[ 0 ] )
		return false;

	for( int i = 0; i < length; i++ )
		if( i + lcp[ max_index ] <= length && strncmp( input + max_index, input + i, lcp[ max_index ] ) == 0 )
			repeat_time++;

	for( int i = 0; i < lcp[ max_index ]; i++ )
		printf( "%c", input[ max_index + i ] );
	printf( " %d\n", repeat_time );

	return true;
}

int main()
{
	int case_num;

	scanf( "%d", &case_num );

	for( int i = 0; i < case_num; i++ )
	{
		scanf( "%s", input );

		if( !suffix_array() )
			printf( "No repetitions found!\n" ); 
	}

	return 0;
}