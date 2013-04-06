/*
 * PCCA Online
 * submission id: 26218
 * user: adavis10006
 * status: Accepted
 * runtime: 0.012
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

char dice[ 2 ][ 10 ];
	
void right_shift( char *shift_dice )
{
	char tmp[ 10 ];
	strcpy( tmp, shift_dice );
	
	shift_dice[ 0 ] = tmp[ 0 ];
	shift_dice[ 1 ] = tmp[ 1 ];
	shift_dice[ 2 ] = tmp[ 3 ];
	shift_dice[ 3 ] = tmp[ 4 ];
	shift_dice[ 4 ] = tmp[ 5 ];
	shift_dice[ 5 ] = tmp[ 2 ];
}

void up_down( char *shift_dice )
{
	char tmp[ 10 ];
	strcpy( tmp, shift_dice );
	
	shift_dice[ 0 ] = tmp[ 1 ];
	shift_dice[ 1 ] = tmp[ 0 ];
	shift_dice[ 2 ] = tmp[ 4 ];
	shift_dice[ 3 ] = tmp[ 3 ];
	shift_dice[ 4 ] = tmp[ 2 ];
	shift_dice[ 5 ] = tmp[ 5 ];
}

void _0totop( char *shift_dice )
{
	strcpy( shift_dice, dice[ 0 ] );
}

void _1totop( char *shift_dice )
{
	_0totop( shift_dice );
	up_down( shift_dice );
}

void _2totop( char *shift_dice )
{
	strcpy( shift_dice, dice[ 0 ] );
	
	char tmp[ 10 ];
	strcpy( tmp, shift_dice );
	
	shift_dice[ 0 ] = tmp[ 2 ];
	shift_dice[ 1 ] = tmp[ 4 ];
	shift_dice[ 2 ] = tmp[ 1 ];
	shift_dice[ 3 ] = tmp[ 3 ];
	shift_dice[ 4 ] = tmp[ 0 ];
	shift_dice[ 5 ] = tmp[ 5 ];
}

void _3totop( char *shift_dice )
{
	strcpy( shift_dice, dice[ 0 ] );
	
	char tmp[ 10 ];
	strcpy( tmp, shift_dice );
	
	shift_dice[ 0 ] = tmp[ 3 ];
	shift_dice[ 1 ] = tmp[ 5 ];
	shift_dice[ 2 ] = tmp[ 2 ];
	shift_dice[ 3 ] = tmp[ 1 ];
	shift_dice[ 4 ] = tmp[ 4 ];
	shift_dice[ 5 ] = tmp[ 0 ];
}

void _4totop( char *shift_dice )
{
	_2totop( shift_dice );
	up_down( shift_dice );
}

void _5totop( char *shift_dice )
{
	_3totop( shift_dice );
	up_down( shift_dice );
}

void generate( char shift_dice[ 6 ][ 4 ][ 10 ] )
{
	_0totop( shift_dice[ 0 ][ 0 ] );
	_1totop( shift_dice[ 1 ][ 0 ] );
	_2totop( shift_dice[ 2 ][ 0 ] );
	_3totop( shift_dice[ 3 ][ 0 ] );
	_4totop( shift_dice[ 4 ][ 0 ] );
	_5totop( shift_dice[ 5 ][ 0 ] );

	for( int i = 0; i < 6; i++ )
		for( int j = 1; j < 4; j++ )
			switch( j )
			{
				case 1:
					strcpy( shift_dice[ i ][ j ], shift_dice[ i ][ 0 ] );
					right_shift( shift_dice[ i ][ j ] );
					break;
				case 2:
					strcpy( shift_dice[ i ][ j ], shift_dice[ i ][ 1 ] );
					right_shift( shift_dice[ i ][ j ] );
					break;
				case 3:
					strcpy( shift_dice[ i ][ j ], shift_dice[ i ][ 2 ] );
					right_shift( shift_dice[ i ][ j ] );
					break;
			}
}

bool check()
{
	char shift_dice[ 6 ][ 4 ][ 10 ]; 

	generate( shift_dice );

#ifdef Debug
	for( int i = 0; i < 6; i++ )
		for( int j = 0; j < 4; j++ )
			printf( "%d %s\n", i, shift_dice[ i ][ j ] );
#endif

	for( int i = 0; i < 6; i++ )
		for( int j = 0; j < 4; j++ )
			if( strcmp( shift_dice[ i ][ j ], dice[ 1 ] ) == 0 )
				return true;

	return false;
}

int main()
{
	int T;

	scanf( "%d", &T );

	while( T-- )
	{
		scanf( "%s%s", dice[ 0 ], dice[ 1 ] );

		printf( "%s", check() ? "Equal\n" : "Not Equal\n" );
	}

	return 0;
}
