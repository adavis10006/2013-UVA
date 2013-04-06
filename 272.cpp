#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    char now[2] ={ '`', '\'' };
    int time = 0;

    while( scanf( "%c", &c ) != EOF )
    {
        if( c == '"' )
		{
            printf( "%c%c", now[ time % 2 ], now[ time % 2 ] );
            time++;
        }
        else
            printf( "%c", c );
    }
}
