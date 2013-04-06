#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
/*
 (   )
 [   ]
 {   }
 <   >
(*   *)
*/
std::deque< int > map;

char str[ 3000 ];
int len;

int index_type, back_type;

bool checkindex( int& index )
{
    if( index >= len )
    {
        index_type = 0;
        return false;
    }

    if( index + 1 < len && str[ index ] == '(' && str[ index + 1 ] == '*' )
    {
        index_type = 1;
        return false;
    }
    if( index + 1 < len && str[ index ] == '*' && str[ index + 1 ] == ')' )
    {
        index_type = 6;
        return false;
    }
    if( str[ index ] == '(' )
    {
        index_type = 2;
        return false;
    }
    if( str[ index ] == ')' )
    {
        index_type = 7;
        return false;
    }
    if( str[ index ] == '[' )
    {
        index_type = 3;
        return false;
    }
    if( str[ index ] == ']' )
    {
        index_type = 8;
        return false;
    }
    if( str[ index ] == '{' )
    {
        index_type = 4;
        return false;
    }
    if( str[ index ] == '}' )
    {
        index_type = 9;
        return false;
    }
    if( str[ index ] == '<' )
    {
        index_type = 5;
        return false;
    }
    if( str[ index ] == '>' )
    {
        index_type = 10;
        return false;
    }


    index++;
    return true;
}

bool checkback( int& back )
{
    if( back - 1 > 0 && str[ back ] == ')' && str[ back - 1 ] == '*' )
    {
        back_type = 6;
        return false;
    }
    if( back - 1 > 0 && str[ back ] == '*' && str[ back - 1 ] == '(' )
    {
        back_type = 1;
        return false;
    }
    if( str[ back ] == '(' )
    {
        back_type = 2;
        return false;
    }
    if( str[ back ] == ')' )
    {
        back_type = 7;
        return false;
    }
    if( str[ back ] == '[' )
    {
        back_type = 3;
        return false;
    }
    if( str[ back ] == ']' )
    {
        back_type = 8;
        return false;
    }
    if( str[ back ] == '{' )
    {
        back_type = 4;
        return false;
    }
    if( str[ back ] == '}' )
    {
        back_type = 9;
        return false;
    }
    if( str[ back ] == '<' )
    {
        back_type = 5;
        return false;
    }
    if( str[ back ] == '>' )
    {
        back_type = 10;
        return false;
    }

    back--;
    return true;
}

int main()
{
	while( fgets( str, 3000, stdin ) != NULL )
	{
        str[ strlen( str ) - 1 ] = '\0';

        int index = 0;
        int ans = 1;

        len = strlen( str );

        map.clear();

        while( true )
        {
            while( checkindex( index ) )
                ans++;

            if( index_type == 0 )
                if( map.empty() )
                {
                    printf( "YES\n" );
                    goto restart;
                }
                else
                {
                    printf( "NO %d\n", ans );
                    goto restart;
                }

            if( index_type > 5 )
            {
                if( map.empty() )
                {
                    printf( "NO %d\n", ans );
                    goto restart;
                }
                else if( map.back() != index_type - 5 )
                {
                    printf( "NO %d\n", ans );
                    goto restart;
                }
                else
                    map.pop_back();
            }
            else
                map.push_back( index_type );


            if( index_type == 1 || index_type == 6 )
                index += 2;
            else
                index++;
            ans++;
        }
restart:
    ;
	}

    return 0;
}
