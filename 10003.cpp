#include <stdio.h>

int cut[ 50 + 2 ];
int cost[ 50 + 2 ][ 50 + 2 ];

int main()
{
    while( true )
    {
        int len, num;

        scanf( "%d", &len ); 
        if( len == 0 )
            break;

        scanf( "%d", &num );

        cut[ 0 ] = 0;
        for( int cur = 1; cur <= num; cur++ )
            scanf( "%d", &cut[ cur ] );
        cut[ num + 1 ] = len;
    
        for( int from = 0; from <= num + 1; from++ )
            for( int end = 0; end <= num + 1; end++ )
                if( from + 1 == end )
                    cost[ from ][ end ] = 0;
                else
                    cost[ from ][ end ] = -1; 

        for( int cut_num = 1; cut_num <= num + 1; cut_num++ )
            for( int from = 0; from <= num + 1 - cut_num; from++ )
            {
                int end = from + cut_num;

                for( int pass = from + 1; pass < end; pass++ )
                {
                    int temp_cost = cost[ from ][ pass ] + cost[ pass ][ end ] + cut[ end ] - cut[ from ];
                    
                    if( cost[ from ][ end ] == -1 )
                        cost[ from ][ end ] = temp_cost;
                    else
                        cost[ from ][ end ] = cost[ from ][ end ] > temp_cost ? temp_cost : cost[ from ][ end ];
                }
            }
        printf( "The minimum cutting is %d.\n", cost[ 0 ][ num + 1 ] );
    }

    return 0;
}
