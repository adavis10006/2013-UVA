#include <cstdio>
#include <cstdlib>
#include <cstring>

#define min( a, b ) ( a ) < ( b ) ? ( a ) : ( b )

char    str[ 100 + 10 ][ 100 + 10 ];
bool    used[ 100 + 10 ];
int     map[ 100 + 10 ][ 100 + 10 ];
int     queue[ 100 + 10 ];

int check( int a, int b )
{
    if( a == b )
        return 0;

    int len = min( strlen( str[ a ] ), strlen( str[ b ] ) );

    for( int i = 0; i < len; i++ )
        if( str[ a ][ i ] != str[ b ][ i ] )
            return i;

    return len;
}


int main()
{
    int time;

    scanf( "%d", &time );

    while( time-- )
    {
        int num;

        scanf( "%d", &num );

        for( int i = 0; i < num; i++ )
            scanf( "%s", str[ i ] );

        for( int i = 0; i < num; i++ )
            for( int j = 0; j < num; j++ )
                map[ i ][ j ] = check( i, j );

        memset( used, false, sizeof( used ) );

        int sum = strlen( str[ 0 ] );
        queue[ 0 ] = 0, used[ 0 ] = true;

        for( int i = 1; i < num; i++ )
        {
            int max = -1, min_y;
            for( int j = 0; j < num; j++ )
                if( used[ j ] )
                    continue;
                else if( max <= map[ queue[ i - 1 ] ][ j ] )
                    max = map[ queue[ i - 1 ] ][ j ], min_y = j;

            queue[ i ] = min_y, used[ min_y ] = true, sum += strlen( str[ min_y ] ) - max;
        }

        printf( "%d\n", sum );
        for( int i = 0; i < num; i++ )
            printf( "%s\n", str[ queue[ i ] ] );
    }

    return 0;
}
