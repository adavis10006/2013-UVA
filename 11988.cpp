#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

enum input_type
{
    FRONT,
    BACK
};

char input[ 100005 ];

std::stack< int > front;
std::queue< int > back;


void merge( input_type in_type, int start )
{
    if( strlen( input + start ) > 0 )
    {     
       switch( in_type )
        {
            case FRONT:
                front.push( start );
                break;
            case BACK:
                back.push( start );
                break;
        }
    }
}

int main ()
{
    while( scanf( "%s", input ) != EOF )
    {
        input_type in_type = FRONT;
        int start = 0, len = strlen( input );

        for( int i = 0; i < len; i++ )
        {
            switch( input[ i ] )
            {
                case '[':
                    input[ i ] = '\0';
                    merge( in_type, start );
                    in_type = FRONT;
                    start = i + 1;
                    break;
                case ']':
                    input[ i ] = '\0';
                    merge( in_type, start );
                    in_type = BACK;
                    start = i + 1;
                    break;
            }
        }

        merge( in_type, start );
        
        while( !front.empty() )
        {    
            printf( "%s", input + front.top() );
            front.pop();
        }
        
        while( !back.empty() )
        {    
            printf( "%s", input + back.front() );
            back.pop();
        }

        printf( "\n" );
    }

    return 0;
}

