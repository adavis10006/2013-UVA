#include <iostream>
#include <cstdio>
#include <cstdlib>

struct Point
{
    double x, y;
};

inline double cross( Point C, Point A, Point B )
{
    return ( A.x - C.x ) * ( B.y - C.y ) - ( B.x - C.x ) * ( A.y - C.y );
}

inline int compare( const void* a, const void* b )
{
    Point *A = ( Point* ) a, *B = ( Point* ) b;

    if( A->x < B->x || A->x == B->x && A->y < B->y ) 
        return -1;
    return 1;
}

void convex_hull( Point* point, int pairs )
{
    qsort( point, pairs, sizeof( Point ), compare );

    int     done = 0;
    Point*  hull = new Point [ pairs * 2 ];

    for( int cur = 0; cur < pairs; cur++ )
    {
        while( done >= 2 && cross( hull[ done - 2 ], hull[ done - 1 ], point[ cur ] ) <= 0 )
            done--;
        hull[ done++ ] = point[ cur ];
    }

    for( int cur = pairs - 1, half = done + 1; cur >= 0; cur-- )
    {
        while( done >= half && cross( hull[ done - 2 ], hull[ done - 1 ], point[ cur ] ) <= 0 )
            done--;
        hull[ done++ ] = point[ cur ];
    }

    for( int cur = 0; cur < done; cur++ )
        point[ cur ] = hull[ cur ];
}

double calc_area( Point* point, int pairs )
{
    double sum = 0;

    for( int cur = 0; cur < pairs; cur++ )
        sum += ( point[ cur ].x * point[ ( cur + 1 ) % pairs ].y - point[ ( cur + 1 ) % pairs ].x * point[ cur ].y );
    
    return sum / 2;
}

Point calc_center( Point* point, int pairs )
{
    Point center;
    double weight = 6 * calc_area( point, pairs );

    center.x = 0;
    center.y = 0;

    for( int cur = 0; cur < pairs; cur++ )
    {
        int next = ( cur + 1 ) % pairs;
        
        center.x += ( point[ cur ].x + point[ next ].x ) * ( point[ cur ].x * point[ next ].y - point[ next ].x * point[ cur ].y );
        center.y += ( point[ cur ].y + point[ next ].y ) * ( point[ cur ].x * point[ next ].y - point[ next ].x * point[ cur ].y );
    }

    center.x /= weight;
    center.y /= weight;
    
    return center;
}

int main()
{
    while( true )
    {
        int     pairs, x, y;
        
        std::cin >> pairs;

        if( pairs < 3 )
            break;
        
        Point* point = new Point[ pairs ];

        for( int num = 0; num < pairs; num++ )
        {
            std::cin >> x >> y;
            
            point[ num ].x = x;
            point[ num ].y = y;
        }

        convex_hull( point, pairs );

        Point center = calc_center( point, pairs );
       
        printf( "%.3lf %.3lf\n", center.x, center.y );
    }
    
    return 0;
}
