#include <cstdio>
#include <cstdlib>

int num;
int map[ 102 ][ 2 ];

static int cmp( const void* a, const void* b )
{
    int* a_map = ( int* ) a;
    int* b_map = ( int* ) b;

    if( a_map[ 0 ] > b_map[ 0 ] || ( a_map[ 0 ] == b_map[ 0 ] && a_map[ 1 ] > b_map[ 1 ] ) )
        return 1;
    else if( a_map[ 0 ] == b_map[ 0 ] && a_map[ 1 ] == b_map[ 1 ] )
        return 0;
    else
        return -1;
}

int main()
{
	int times = 1;
	while( scanf( "%d", &num ) != EOF )
	{
		char temp[ 256 ];
		int begin = 600, time = 0;

		map[ 0 ][ 0 ] = map[ 0 ][ 1 ] = 10 * 60;
		for( int i = 1; i <= num; i++ )
		{
			int h_s, m_s, h_e, m_e;
			scanf( "%d:%d %d:%d", &h_s, &m_s, &h_e, &m_e );
			fgets( temp, 256, stdin );

			map[ i ][ 0 ] = h_s * 60 + m_s;
			map[ i ][ 1 ] = h_e * 60 + m_e;
		}
		map[ num + 1 ][ 0 ] = 18 * 60;
		map[ num + 1 ][ 1 ] = 18 * 60;

        qsort( map, num + 2, sizeof( int [ 2 ] ), cmp );

		for( int i = 0; i <= num; i++ )
			if( map[ i + 1 ][ 0 ] - map[ i ][ 1 ] > time )
			{
				time = map[ i + 1 ][ 0 ] - map[ i ][ 1 ];
				begin = map[ i ][ 1 ];
			}

		printf( "Day #%d: the longest nap starts at %02d:%02d and will last for", times++, begin /60, begin % 60 );
		if( time / 60 > 0 )
			printf( " %d hours and", time / 60 );
		printf( " %d minutes.\n", time % 60 );
	}
}
