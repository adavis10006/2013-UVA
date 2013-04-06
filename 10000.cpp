#include <iostream>

class problem_setting
{
public:
    problem_setting()
    {
        node_num = -1;
    }
    
    ~problem_setting()
    {
        if( node_num == -1 )
            return;
        
        for( int row = 0; row <= node_num; row++ )
            delete( map[ row ] );
        delete( map );
    }
    
    void initial( int num, int from )
    {
        length      = -1;
        node_num    = num;
        start       = from;

        map = new int *[ node_num + 1 ];
        for( int row = 0; row <= node_num; row++ )
        {
            map[ row ] = new int [ node_num + 1 ];
            for( int col = 0; col <= node_num; col++ )
                map[ row ][ col ] = -1;
        }
    }

    void set_map( int from, int end )
    {
        map[ from ][ end ] = 1;
    }

    void solve( int time )
    {
        for( int pass = 1; pass <= node_num; pass++ )
            for( int row = 1; row <= node_num; row++ )
            {
                if( map[ row ][ pass ] == -1 )
                    continue;
                for( int col = 1; col <= node_num; col++ )
                {   
                    if( map[ pass ][ col ] == -1 )
                        continue;
                    map[ row ][ col ] = map[ row ][ col ] < map[ row ][ pass ] + map[ pass ][ col ] ? map[ row ][ pass ] + map[ pass ][ col ] : map[ row ][ col ];
                }
            }
                        
        for( int end = 1; end <= node_num; end++ )
        { 
            if( length < map[ start ][ end ] )
            {
                length = map[ start ][ end ];
                finish = end;
            }
            if( length == map[ start ][ end ] && finish > end )
                finish = end;
        }
        //Case %d: The longest path from %d has length %d, finishing at %d.
        std::cout << "Case " << time << ": The longest path from " << start << " has length " << length << ", finishing at " << finish << "." << std::endl << std::endl;
    }
private:
    int                             node_num, start;
    int                             length, finish;
    int                             **map;
};

int main()
{
    int time = 0;

    while( true )
    {
        int             node_num, start, from, end;
        problem_setting problem;
        
        std::cin >> node_num;
        if( node_num == 0 )
            break;
        std::cin >> start;
        
        problem.initial( node_num, start );
            
        while( true )
        {
            std::cin >> from >> end;
            if( from == 0 && end == 0 )
                break;
            problem.set_map( from, end );
        }

        problem.solve( ++time );
    }

    return 0;
}
