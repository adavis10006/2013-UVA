/*
 * PCCA Online
 * submission id: 26302
 * user: adavis10006
 * status: Accepted
 * runtime: 0.016
 * memory: 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int MAX = ( 1 << 16 ) - 1;

int y_board[ 12 + 5 ], n_board[ 12 + 5 ], y_select, n_select, number;

void init()
{
    memset( y_board, 0, sizeof( y_board ) );
    memset( n_board, 0, sizeof( n_board ) );
    y_select = n_select = number = 0;
}

bool DFS( int index )
{
	if( number == index )
		return true;
	
	if( y_board[ index ] & y_select || n_board[ index ] & n_select )
		return DFS( index + 1 );

	int place;
	
	place = ( n_board[ index ] ^ n_select ) & ~y_select & n_board[ index ]; 

	while( place )
	{
		int select = place & -place;
	
		n_select ^= select; 
		
		if( DFS( index + 1 ) )
			return true;
		else
			n_select ^= select; 
		
		place ^= select;
	}

	place = ( y_board[ index ] ^ y_select ) & ~n_select & y_board[ index ]; 

	while( place )
	{
		int select = place & -place;
	
		y_select ^= select; 
		
		if( DFS( index + 1 ) )
			return true;
		else
			y_select ^= select; 
		
		place ^= select;
	}

	return false;
}

int main()
{
    init();

    char input[ 100 ];

    while( scanf( "%s", input ) != EOF )
    {
        bool satisfy = false;
        if( input[ 0 ] == '.' )
        {
			if( DFS( 0 ) )
			{
                printf( "Toppings: " );
                for( int i = 0; i < 16; i++, y_select >>= 1 )
                    if( y_select & 1 )
                        printf( "%c", 'A' + i );
                printf( "\n" );
            }
			else
				printf( "No pizza can satisfy these requests.\n" );

            init();
        }
        else
        {
            for( int i = 0; i < strlen( input ); i += 2 )
                switch( input[ i ] )
                {
                case '+':
                    y_board[ number ] |= 1 << input[ i + 1 ] - 'A';
                    break;
                case '-':
                    n_board[ number ] |= 1 << input[ i + 1 ] - 'A';
                    break;
                }

            number++;
        }
    }
    return 0;
}

