/*
 * PCCA Online
 * submission id: 26552
 * user: adavis10006
 * status: Accepted
 * runtime: 0.020
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000

int map[ MAX + 1 ][ MAX + 1 ], N, M, start, end;
bool visit[ MAX + 1 ][ MAX + 1 ];

void DFS( int now, int seq, int n, int m )
{
	visit[ n ][ m ] = true;
	if( now == seq && n == N - 1 )
		if( end == -1 || end > m )
			end = m;

	int next = now == seq ? 1: now + 1;

	if( n - 1 >= 0 && !visit[ n - 1 ][ m ] && map[ n - 1 ][ m ] == next )
		DFS( next, now == seq ? seq + 1: seq, n - 1, m );
	if( n + 1 < N && !visit[ n + 1 ][ m ] && map[ n + 1 ][ m ] == next )
		DFS( next, now == seq ? seq + 1: seq, n + 1, m );
	if( m - 1 >= 0 && !visit[ n ][ m - 1 ] && map[ n ][ m - 1 ] == next )
		DFS( next, now == seq ? seq + 1: seq, n , m - 1 );
	if( m + 1 < M &&! visit[ n ][ m + 1 ] && map[ n ][ m + 1 ] == next )
		DFS( next, now == seq ? seq + 1: seq, n, m + 1 );
	
	visit[ n ][ m ] = false;
	return;
}

int main()
{
    int T;

	scanf( "%d", &T );

	while( T-- )
	{
		memset( visit, false, sizeof( visit ) );
		end = -1;

		scanf( "%d%d", &N, &M );

		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ )
				scanf( "%d", &map[ i ][ j ] );
	
		for( int i = 0; i < M; i++ )
			if( map[ 0 ][ i ] == 1 )
			{
				DFS( 1, 1, 0, i );
				if( end != -1 )
				{
					printf( "1 %d\n%d %d\n", i + 1, N, end + 1 );
					if( T )
						printf( "\n" );

					break;
				}
			}
	}

    return 0;
}

