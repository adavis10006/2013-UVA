#include <cstdio>
#include <cstdlib>
#include <vector>

int main()
{
    while( true )
    {
        std::vector< int > player[ 2 ], buffer;

        player[ 0 ].clear();
        player[ 1 ].clear();

        char input[ 2 ];

        for( int i = 0; i < 26; i++ )
            for( int j = 0; j < 2; j++ )
            {
                scanf( "%s", input );

                if( input[ 0 ] == '#' )
                    return 0;

                if( input[ 1 ] == 'A' )
                    player[ j ].push_back( 1 );
                else if( input[ 1 ] == 'T' )
                    player[ j ].push_back( 10 );
                else if( input[ 1 ] == 'J' )
                    player[ j ].push_back( 11 );
                else if( input[ 1 ] == 'Q' )
                    player[ j ].push_back( 12 );
                else if( input[ 1 ] == 'K' )
                    player[ j ].push_back( 13 );
                else
                    player[ j ].push_back( input[ 1 ] - '0' );
            }

        int player_turn = 0;
        bool face_occur = false;
        int try_time = 0;
        buffer.clear();
        while( player[ player_turn ].size() != 0 )
        {
            if( !face_occur )
                if( player[ player_turn ].back() > 10 || player[ player_turn ].back() == 1 )
                {
                    if( player[ player_turn ].back() == 1 )
                        try_time = 4;
                    else
                        try_time = player[ player_turn ].back() - 10;
                    buffer.push_back( player[ player_turn ].back() );
                    player[ player_turn ].pop_back();
                    face_occur = true;
                    player_turn = player_turn == 1? 0: 1;
                }
                else
                {
                    buffer.push_back( player[ player_turn ].back() );
                    player[ player_turn ].pop_back();
                    player_turn = player_turn == 1? 0: 1;
                }
            else
            {
                if( player[ player_turn ].back() > 10 || player[ player_turn ].back() == 1 )
                {
                    if( player[ player_turn ].back() == 1 )
                        try_time = 4;
                    else
                        try_time = player[ player_turn ].back() - 10;
                    buffer.push_back( player[ player_turn ].back() );
                    player[ player_turn ].pop_back();
                    face_occur = true;
                    player_turn = player_turn == 1? 0: 1;
                }
                else
                {
                    buffer.push_back( player[ player_turn ].back() );
                    player[ player_turn ].pop_back();
                    try_time--;
                }
            }

            if( face_occur && try_time == 0 )
            {
                face_occur = false;
                player_turn = player_turn == 1? 0: 1;

                for( std::vector <int>::iterator i = buffer.begin(); i != buffer.end(); i++ )
                    player[ player_turn ].insert( player[ player_turn ].begin(), *i );
                buffer.clear();
            }
        }

        if( player[ 0 ]. size() == 0 )
            printf( "1%3d\n", player[ 1 ].size() );
        else
            printf( "2%3d\n", player[ 0 ].size() );

    }
}
