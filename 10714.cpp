#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int time;

    scanf( "%d", &time );

    while( time-- )
    {
        int length, num, min = 0, max = 0;

        scanf( "%d %d", &length, &num );

        for( int i = 0, input, tmp_min, tmp_max; i < num; i++ )
        {
            scanf( "%d", &input );

            if( input < length - input )
                tmp_min = input, tmp_max = length - input;
            else
                tmp_min = length - input, tmp_max = input;

            if( tmp_min > min )
                min = tmp_min;
            if( tmp_max > max )
                max = tmp_max;
        }

        printf( "%d %d\n", min, max );
    }

    return 0;
}
