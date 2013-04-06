#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
	int x, y, tempx, tempy;

	while( true )
	{
		scanf("%d", &number );

		if( number == 0 )
			return 0;

		scanf( "%d%d", &x, &y );

		for( int i = 0; i < number; i++ )
		{
			scanf( "%d%d", &tempx, &tempy );

			if( tempx == x || tempy == y )
				printf("divisa\n");
			if( tempx > x && tempy > y )
				printf("NE\n");
			if( tempx > x && tempy < y )
				printf("SE\n");
			if( tempx < x && tempy > y )
				printf("NO\n");
			if( tempx < x && tempy < y )
				printf("SO\n");
		}
	}
}
