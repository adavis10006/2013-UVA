/*
 * PCCA Online
 * submission id: 25239
 * user: adavis10006
 * status: Accepted
 * runtime: 0.008
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

bool check( char* map )
{
	int len = strlen( map );
	for( int i = 0; i < len / 2; i++ )
		if( map[ i ] != map[ len - 1 - i ] )
			return false;
	
	return true;
}

int main()
{
	char c;
	char map[ 10000 ];
	char ori[ 10000 ];
	int num = 0, ori_num = 0;
	while( ( c = getchar() ) != EOF )
		if( c == '\n' )
		{
			map[ num ] = '\0';
			ori[ num ] = '\0';
			if( strcmp( "DONE", ori ) == 0 )
				return 0;

			printf( "%s", check( map ) ? "You won't be eaten!\n" : "Uh oh..\n" );
			num = ori_num = 0;
		}
		else
		{
			if( c >= 'A' && c <= 'Z' )
				map[ num++ ] = c;  
			if( c >= 'a' && c <= 'z' )
				map[ num++ ] = c - 'a' + 'A';
			ori[ ori_num++ ] = c;
		}
}
