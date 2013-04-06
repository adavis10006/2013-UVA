#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>

std::set< std::string > set;

int main()
{
    char input;
    std::string string = "";

    while( ( input = getchar() ) != EOF )
        if( ( input >= 'a' && input <= 'z' ) || ( input >= 'A' && input <= 'Z' ) )
            string += tolower( input );
        else if( string.length() != 0 && set.count( string ) == 0 )
        {             
                set.insert( string );
                string = "";
        }
        else
            string = "";
    
    for( std::set< std::string >::iterator itr = set.begin(); itr != set.end(); itr++ )
        printf( "%s\n", itr->c_str() );

    return 0;
}
