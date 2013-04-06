/*
 * PCCA Online
 * submission id: 25533
 * user: adavis10006
 * status: Accepted
 * runtime: 0.008
 * memory: 
 */
#include <cstdio>
#include <vector>

void solve( int n )
{
    if( n == 1 )
	{
		printf( "Discarded cards:\n" );
		printf( "Remaining card: 1\n" );

	
		return;
	}
	
	std::vector< int > people;

    for( int index = 0; index < n; index++ )
        people.push_back( index + 1 );

	printf( "Discarded cards:" );

    int start = -2;
	bool first = true;
    for( int index = 0; index < n - 1; index++ )
    {
        
		if( first )
		{
			printf( " %d", people[ ( start + 2 ) % ( n - index ) ] );
			first = false;
		}
		else
			printf( ", %d", people[ ( start + 2 ) % ( n - index ) ] );

		people.erase( people.begin() + ( start + 2 ) % ( n - index ) );
        start = ( start + 2 ) % ( n - index ) - 1;
	}

	printf( "\nRemaining card: %d\n", people[ 0 ] );

	/*
	Discarded cards: 1, 3, 5, 7, 4, 2
	Remaining card: 6
	*/
}

int main()
{
    int N;

    while( true )
    {
        scanf( "%d", &N );
        
        if( N == 0 )
            return 0;

        solve( N );
    }
}

