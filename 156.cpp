/*
 * PCCA Online
 * submission id: 25228
 * user: adavis10006
 * status: Accepted
 * runtime: 0.008
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

char word_map[ 1001 ][ 22 ];
char ans_map[ 1001 ][ 22 ];
bool solve_map[ 1001 ];

void two_word_mark( int a, int b )
{
	if( strlen( word_map[ a ] ) != strlen( word_map[ b ] ) )
		return;

	bool map[ 22 ];

	for( int i = 0; i < strlen( word_map[ b ] ); i++ )
		map[ i ] = true;

	for( int i = 0; i < strlen( word_map[ a ] ); i++ )
	{	
		bool find = false;
		for( int j = 0; j < strlen( word_map[ b ] ); j++ )
		{
			if( map[ j ] && toupper( word_map[ a ][ i ] ) == toupper( word_map[ b ][ j ] ) )
			{
				map[ j ] = false;
				find = true;

				break;
			}
		}

		if( !find )
			return;
	}

	solve_map[ a ] = solve_map[ b ] = true;
}

static int cstring_cmp( const void* a, const void* b ) 
{ 
   return strcmp( *( char** ) a, *( char** ) b );
} 

int main()
{
	int num = 0, ans = 0;
	char temp[ 22 ];

	while( true )
	{
		scanf( "%s", temp );
		
		if( strlen( temp ) == 1 && temp[ 0 ] == '#' )
			break;	
	
		strcpy( word_map[ num++ ], temp );
	}

	for( int i = 0; i < num; i++ )
		solve_map[ i ] = false;

	for( int i = 0; i < num - 1; i++ )
		for( int j = i + 1; j < num; j++ )
			two_word_mark( i, j );

	for( int i = 0; i < num; i++ )
		if( !solve_map[ i ] )
			strcpy( ans_map[ ans++ ], word_map[ i ] );

	//qsort( ans_map, num, sizeof( char* ), cstring_cmp );
 
	for( int i = 0; i < ans - 1; i++ )
		for( int j = i + 1; j < ans; j++ )
			if( strcmp( ans_map[ i ], ans_map[ j ] ) > 0 )
			{
				strcpy( temp, ans_map[ i ] );
				strcpy( ans_map[ i ], ans_map[ j ] );
				strcpy( ans_map[ j ], temp );
			}
		
	for( int i = 0; i < ans; i++ )
		printf( "%s\n", ans_map[ i ] );
	return 0;
}
