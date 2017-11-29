#include <cstdio>
#include <cstdlib>
#include <cstring>

#define min(a,b) (((a) < (b)) ? (a) : (b))

struct map_struct
{
    int num, up, down;
}map[ 10000 + 1 ];

struct stack_struct
{
    int top, stack[ 10000 + 1 ];
}up, down;

int b_search( stack_struct stack, int low, int high, int search )
{
    int mid = ( low + high ) >> 1;

    //printf( "in search:%d %d %d %d\n", search, low, high, mid );

    if( low == high )
        return low;
    else if( search > stack.stack[ mid ] )
        return b_search( stack, mid + 1, high, search );
    else if( search < stack.stack[ mid ] )
        return b_search( stack, low, mid - 1, search );
    else
        return mid;
}

int main()
{
    int num;

    while( scanf( "%d", &num ) != EOF )
    {
        for( int i = 0; i < num; i++ )
            scanf( "%d", &map[ i ].num );

        up.top = -1;
        for( int i = 0; i < num; i++ )
        {
            if( up.top == -1 || up.stack[ up.top ] < map[ i ].num )
                up.stack[ ++up.top ] = map[ i ].num;
            else
            {
                int low = 0, high = up.top;
                while ( low <= high )
                {
                    int mid = ( low + high ) >> 1;
                    if ( map[ i ].num > up.stack[ mid ] )
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                up.stack[ low ] = map[ i ].num;
            }

            map[ i ].up = up.top;
        }

        down.top = -1;
        for( int i = num - 1; i >= 0; i-- )
        {
            if( down.top == -1 || down.stack[ down.top ] < map[ i ].num )
                down.stack[ ++down.top ] = map[ i ].num;
            else
            {
                int low = 0, high = down.top;
                while ( low <= high )
                {
                    int mid = ( low + high ) >> 1;
                    if ( map[ i ].num > down.stack[ mid ] )
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                down.stack[ low ] = map[ i ].num;
            }

            map[ i ].down = down.top;
        }

        int ans = 0;
        for( int i = 0; i < num; i++ )
            if( ans < min( map[ i ].up, map[ i ].down ) )
                ans = min( map[ i ].up, map[ i ].down );

        printf( "%d\n", 2 * ans + 1 );
    }

    return 0;
}
