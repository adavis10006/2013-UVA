#include <iostream>

bool table[ 8 ][ 3 ] = 
{
    false, false, false,
    false, false, true,
    false, true, false,
    false, true, true,
    true, false, false,
    true, false, true,
    true, true, false,
    true, true, true
};


void transform( int identifer, bool automaton[ 8 ] )
{
    for( int num = 0; num < 8; num++ )
    {
        automaton[ num ] = identifer % 2 == 1; 
        identifer /= 2;
    }
}

int modulus( int num, int state_num )
{
    if( num < 0 )
        return ( num + state_num ) % state_num;
    else if( num >= state_num )
        return num % state_num;
    else
        return num;
}

bool check( int num, int now, int state_num, int* transition )
{            
    for( int shift = -1; shift <= 1; shift++ )
        if( transition[ modulus ( now + shift, state_num ) ] != -1 )            
            if( transition[ modulus( now + shift, state_num ) ] != ( table[ num ][ shift + 1 ] == true ? 1: 0 ) )
                return false;
    return true;
}

bool solve( int now, bool automaton[ 8 ], int state_num, bool* state, int* transition )
{
    if( now == state_num - 1 )
        return true;

    for( int num = 0; num < 8; num++ )
        if( automaton[ num ] == state[ now + 1 ] && check( num, now + 1, state_num, transition ) )
        {
            bool change[ 3 ];

            for( int shift = -1; shift <= 1; shift++ )
                if( transition[ modulus( now + 1 + shift, state_num ) ] == -1 )            
                {
                    transition[ modulus( now + 1 + shift, state_num ) ] = table[ num ][ shift + 1 ] == true ? 1: 0; 
                    change[ shift + 1 ] = true;
                }
                else
                    change[ shift + 1 ] = false;

            if( solve( now + 1, automaton, state_num, state, transition ) )
                return true;
    
            for( int shift = -1; shift <= 1; shift++ )
                if( change[ shift + 1 ] )
                    transition[ modulus( now + 1 + shift, state_num ) ] = -1;
        }

    return false;
}

int main()
{
    bool    automaton[ 8 ];
    int     identifer, state_num;
    bool    *state;
    int     *transition;

    while( std::cin >> identifer )
    {
        std::cin >> state_num;

        state       = new bool [ state_num ];
        transition  = new int [ state_num ];
   
        transform( identifer, automaton );

        for( int num = 0; num < state_num; num++ )
        {    
            char boolean;
        
            std::cin >> boolean;
            state[ num ] = boolean == '1'; 
            transition[ num ] = -1;
        }

        if( solve( -1, automaton, state_num, state, transition ) )
            std::cout << "REACHABLE" << std::endl;
        else
            std::cout << "GARDEN OF EDEN" << std::endl;

        delete( state );
        delete( transition );
    }

    return 0;
}
