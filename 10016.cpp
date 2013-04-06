#include <cstdio>
#include <vector>

void UpDown( int map[ 101 ][ 101 ], int range, int ring )
{
    for( int rid = ring; rid <= range / 2 + range % 2; rid++ )
        if( rid == ring )
            for( int cid = ring; cid <= range - ring + 1; cid++ )
            {
                int temp = map[ rid ][ cid ];
                
                map[ rid ][ cid ] = map[ range - ring + 1 ][ cid ];
                map[ range - ring + 1 ][ cid ] = temp;
            }
        else
        {
            int temp;
            
            temp = map[ rid ][ ring ];
            map[ rid ][ ring ] = map[ range - rid + 1 ][ ring ];
            map[ range - rid + 1 ][ ring ] = temp;
            
            temp = map[ rid ][ range - ring + 1 ];
            map[ rid ][ range - ring + 1 ] = map[ range - rid + 1 ][ range - ring + 1 ];
            map[ range - rid + 1 ][ range - ring + 1 ] = temp;
        }
}

void LeftRight( int map[ 101 ][ 101 ], int range, int ring )
{
    for( int cid = ring; cid <= range / 2 + range % 2; cid++ )
        if( cid == ring )
            for( int rid = ring; rid <= range - ring + 1; rid++ )
            {
                int temp = map[ rid ][ cid ];                
                
                map[ rid ][ cid ] = map[ rid ][ range - ring + 1 ];
                map[ rid ][ range - ring + 1 ] = temp;
            }
        else
        {
            int temp;
            
            temp = map[ ring ][ cid ];
            map[ ring ][ cid ] = map[ ring ][ range - cid + 1 ];
            map[ ring ][ range - cid + 1 ] = temp;
            
            temp = map[ range - ring + 1 ][ cid ];
            map[ range - ring + 1 ][ cid ] = map[ range - ring + 1 ][ range - cid + 1 ];
            map[ range - ring + 1 ][ range - cid + 1 ] = temp;
        }
}

void InverseDiagonal( int map[ 101 ][ 101 ], int range, int ring )
{
    for( int rid = ring; rid <= range - ring + 1; rid++ )
    {
        int temp = map[ rid ][ ring ];
        
        map[ rid ][ ring ] = map[ range - ring + 1 ][ range - rid + 1 ];
       map[ range - ring + 1 ][ range - rid + 1 ] = temp;
    }

    for( int cid = ring + 1; cid <= range - ring + 1; cid++ )
    {
        int temp = map[ ring ][ cid ];
        
        map[ ring ][ cid ] = map[ range - cid + 1 ][ range - ring + 1 ];
        map[ range - cid + 1 ][ range - ring + 1 ] = temp;
    }
}

void Diagonal( int map[ 101 ][ 101 ], int range, int ring )
{
    for( int rid = ring; rid <= range - ring + 1; rid++ )
    {
        int temp = map[ rid ][ ring ];
        
        map[ rid ][ ring ] = map[ ring ][ rid ];
        map[ ring ][ rid ] = temp;
    }
    
    for( int cid = ring + 1; cid <= range - ring + 1; cid++ )
    {
        int temp = map[ range - ring + 1 ][ cid ];
        
        map[ range - ring + 1 ][ cid ] = map[ cid ][ range - ring + 1 ];
        map[ cid ][ range - ring + 1 ] = temp;
    }
}

int main()
{
    int map[ 101 ][ 101 ];
    
    int cases;
    
    scanf( "%d", &cases );
    
    while( cases-- > 0 )
    {
        int range;
        
        scanf( "%d", &range );
        
        for( int rid = 1; rid <= range; rid++ )
            for( int cid = 1; cid <= range; cid++ )
                scanf( "%d", &map[ rid ][ cid ] );
        
        for( int index = 1; index <= range / 2 + range % 2; index++ )
        {
            int digit, number = 0;
            
            scanf( "%d", &digit );
            
            while( digit-- > 0 )
            {
                int num;
                scanf( "%d", &num );
              
                switch( num )
                {
                    case 1:
                        UpDown( map, range, index );
                        break;
                    case 2:
                        LeftRight( map, range, index );
                        break;
                    case 3:
                        Diagonal( map, range, index );
                        break;
                    case 4:
                        InverseDiagonal( map, range, index );
                        break;
                }
            }
        }
        
        for( int rid = 1; rid <= range; rid++ )
        {
            printf( "%d", map[ rid ][ 1 ] );
            
            for( int cid = 2; cid <= range; cid++ )
                printf( " %d", map[ rid ][ cid ] );
            
            printf( "\n" );
        }
    }
    
    return 0;
}
