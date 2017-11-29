#include <cstdio>
#include <cstdlib>
#include <cstring>

enum map_num
{
    EMPTY,
    WALL,
    ROOK
};

int num, max, map[ 16 ], ideal[ 16 ];

bool conflict( int index )
{
    if( map[ index ] != EMPTY )
        return false;

    int x = index / num, y = index % num;

    for( int i = x; i >= 0; i-- )
        if( map[ i * num + y ] == ROOK )
            return false;
        else if( map[ i * num + y ] == WALL )
            break;

    for( int i = y; i >= 0; i-- )
        if( map[ x * num + i ] == ROOK )
            return false;
        else if( map[ x * num + i ] == WALL )
            break;

    return true;
}

void dfs( int from, int pick )
{
    if( ideal[ from ] + pick < max )
        return;

    for( int i = from; i < num * num; i++ )
        if( conflict( i ) )
        {
            map[ i ] = ROOK;
            dfs( i + 1, pick + 1 );
            map[ i ] = EMPTY;
        }

    if( pick > max )
        max = pick;
}

int main()
{
    while( scanf( "%d\n", &num ), num )
    {
        char c;
        for( int i = 0; i < num; i++, c = getchar() )
            for( int j = 0; j < num; j++ )
            {
                c = getchar();

                if( c == '.' )
                    map[ i * num + j ] = EMPTY;
                else
                    map[ i * num + j ] = WALL;
            }

        for( int i = num * num - 1, j = 1, wall = 0; i >= 0; i--, j++)
        {
            if( map[ i ] == WALL )
                wall++;

            ideal[ i ] = j - wall;
        }

        max = 0;

        dfs( 0, 0 );

        printf( "%d\n", max );
    }


    return 0;
}
