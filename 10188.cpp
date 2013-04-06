#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int num, temp_num, times = 1;

    while( scanf( "%d", &num ) != EOF )
    {
        if( num == 0 )
            return 0;

        int num_check, std_ori_num = 0, std_map_num = 0, team_ori_num = 0, team_map_num = 0;
        char c, std_ori[ 122000 ], std_map[ 122000 ], team_ori[ 122000 ], team_map[ 122000 ];

        c = getchar();
        temp_num = num;
        while( temp_num != 0 )
        {
            c = getchar();

            std_ori[ std_ori_num++ ] = c;

            if( c >= '0' && c <= '9' )
                std_map[ std_map_num++ ] = c;

            if( c == '\n' )
                temp_num--;
        }
        std_ori[ std_ori_num ] = '\0';
        std_map[ std_map_num ] = '\0';

        scanf( "%d", &num_check );

        c = getchar();
        temp_num = num_check;
        while( temp_num != 0 )
        {
            c = getchar();

            team_ori[ team_ori_num++ ] = c;

            if( c >= '0' && c <= '9' )
                team_map[ team_map_num++ ] = c;

            if( c == '\n' )
                temp_num--;
        }
        team_ori[ team_ori_num ] = '\0';
        team_map[ team_map_num ] = '\0';

        if( strcmp( std_ori, team_ori ) == 0 )
            printf( "Run #%d: Accepted\n", times++ );
        else if( strcmp( std_map, team_map ) == 0 )
            printf( "Run #%d: Presentation Error\n", times++ );
        else
            printf( "Run #%d: Wrong Answer\n", times++ );
    }
}
