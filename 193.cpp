/*
 * PCCA Online
 * submission id: 26559
 * user: adavis10006
 * status: Accepted
 * runtime: 0.024
 * memory: 
 */
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 100 + 5

enum COLOR
{
	UNSET = 0,
	BLACK = 1,
	WHITE = 2
};

bool map[ MAX ][ MAX ];
int num, rule, connection[ MAX ], search_num, sol_num, ans_num, search[ MAX ], sol[ MAX ], ans[ MAX ];

void init()
{
	for( int i = 0; i < num; i++ )
		if( connection[ i ] == 0 )
			sol[ sol_num++ ] = i + 1, search[ i ] =  BLACK, search_num++;
}

void DFS()
{
	if( num - search_num + sol_num <= ans_num ) 
		return;

	if( search_num == num )
	{
		if( sol_num > ans_num )
		{
			ans_num = sol_num;
			for( int i = 0; i < sol_num; i++ )
				ans[ i ] = sol[ i ];
		}

		return;
	}

	for( int i = 0; i < num; i++ )
		if( search[ i ] == UNSET )
		{
			//set this node
			bool can_black = true;
			for( int j = 0; j < num && can_black; j++ )
				if( map[ i ][ j ] && search[ j ] == BLACK )
					can_black = false;
				
			//set as black
			if( can_black )
			{
				sol[ sol_num++ ] = i + 1, search[ i ] = BLACK, search_num++;
				DFS();
				sol_num--, search[ i ] = UNSET, search_num--;
			}
			//set as white
			search[ i ] = WHITE, search_num++;
			DFS();
			search[ i ] = UNSET, search_num--;
			break;
		}
}

int main()
{
	int T;

	scanf( "%d", &T );

	while( T-- )
	{
		memset( map, false, sizeof( map ) );
		memset( search, UNSET, sizeof( search ) );
		memset( connection, 0, sizeof( connection ) );
		
		scanf( "%d%d", &num, &rule );
		
		for( int i = 0, x, y; i < rule; i++ )
		{
			scanf( "%d%d", &x, &y );
			map[ x - 1 ][ y - 1 ] = true;
			map[ y - 1 ][ x - 1 ] = true;

			connection[ x - 1 ]++;
			connection[ y - 1 ]++;
		}

		search_num = sol_num = ans_num = 0;
		
		//if it have to select black
		init();

		DFS();

		std::sort( ans, ans + ans_num );

		printf( "%d\n", ans_num );
		for( int i = 0; i < ans_num; i++ )
			if( i == 0 )
				printf( "%d", ans[ i ] );
			else
				printf( " %d", ans[ i ] );
		printf( "\n" );
	}
	
	return 0;
}

