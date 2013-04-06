#include <cstdio>
#include <vector>

int disk, move, current = 0;

std::vector< int > pegs[ 3 ];

void hanoi_show()
{
    if( current > move )
        return;

    for( int index = 0; index < 3; index++ )
    {
        printf( "%c=>", 'A' + index );
        
        if( pegs[ index].size() != 0 )
            printf( "  " );
        
        for( int size = 1; size <= pegs[ index ].size(); size++ )
            printf( " %d", pegs[ index ][ size - 1 ] );

        printf( "\n" );
    }

    printf( "\n" );
}

void hanoi( int disk_id, char A, char B, char C )
{
    if( current >= move )
        return;

    if( disk_id == 1 )
    {
        pegs[ C - 'A' ].push_back( pegs[ A - 'A'][ pegs[ A - 'A' ].size() - 1 ] );
        pegs[ A - 'A' ].pop_back();
        current++;

        hanoi_show();
    }
    else
    {
        hanoi( disk_id - 1, A, C, B );

        pegs[ C - 'A' ].push_back( pegs[ A - 'A'][ pegs[ A - 'A' ].size() - 1 ] );
        pegs[ A - 'A' ].pop_back();
        current++;

        hanoi_show();

        hanoi( disk_id - 1, B, A, C );
    }
}

int main()
{
    int num = 1;

    while( true )
    {
        scanf( "%d%d", &disk, &move );

        if( disk == 0 && move == 0 )
            return 0;

        for( int index = 0; index < 3; index++ )
            pegs[ index ].clear();
        current = 0;

        for( int index = disk; index >=  1; index-- )
            pegs[ 0 ].push_back( index );

        printf( "Problem #%d\n\n", num++ );

        hanoi_show(); 

        hanoi( disk, 'A', 'B', 'C' );
    }
}
