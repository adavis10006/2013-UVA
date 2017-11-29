#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX( x, y ) ( x ) > ( y ) ? ( x ) : ( y )

char string_a[ 105 ], string_b[ 105 ];

int lcd[ 105 ][ 105 ];

int main()
{
	int problem = 1;
	while( scanf( "%s", string_a ), strcmp( string_a, "#" ) != 0 )
	{
		memset( lcd, 0, sizeof( lcd ) );

		scanf( "%s", string_b );

		for( int i = 0; i < strlen( string_a ); i++ )
			for( int j = 0; j < strlen( string_b ); j++ )
				if( string_a[ i ] == string_b[ j ] )
					lcd[ i + 1 ][ j + 1 ] = lcd[ i ][ j ] + 1;
				else
					lcd[ i + 1 ][ j + 1 ] = MAX( lcd[ i ][ j + 1 ], lcd[ i + 1 ][ j ] );
	
		printf("Case #%d: you can visit at most %d cities.\n", problem++, lcd[ strlen( string_a ) ][ strlen( string_b ) ] );
	}

	return 0;
}