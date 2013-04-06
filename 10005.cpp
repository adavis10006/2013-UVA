#include <cstdio>
#include <cstdlib>
#include <cmath>

inline double square( double number )
{
    return number * number; 
}

inline double dist( double pointA[ 2 ], double pointB[ 2 ] ) 
{
    return square( pointA[ 0 ] - pointB[ 0 ] ) + square( pointA[ 1 ] - pointB[ 1 ] );
}

inline bool fcmp( double difference )
{
    if( fabs( difference ) < 1E-6 )
        return false;
    else
        return difference < 0;
}
// x < y
inline bool checkdist( double distance, double pointA[ 2 ], double pointB[ 2 ] )
{
    return fcmp( distance * distance - dist( pointA, pointB ) ); 
}

inline bool checkcenter( double R, double pairs[ 100 ][ 2 ], int point_num, double center[ 2 ] )
{
    for( int point = 0; point != point_num; point++ )
        if ( checkdist( R, pairs[ point ], center ) )
            return false;
 
    return true;
}


int main()
{
    int     point_num;
    double  R;
    double  pairs[ 100 ][ 2 ];

    while( true )
    {
restart:   
        scanf( "%d", &point_num );

        if( point_num == 0 )
            return 0;
    
        for( int cur = 0; cur != point_num; cur++ )
            scanf( "%lf %lf", &pairs[ cur ][ 0 ], &pairs[ cur ][ 1 ] );
    
        scanf( "%lf", &R );

        if( point_num == 1 )
        {
            printf( "The polygon can be packed in the circle.\n" );    
            goto restart;
        }                    
        
        double distance = 2 * R;

        for( int point_1 = 0; point_1 != point_num; point_1++ )
            for( int point_2 = 0; point_2 != point_num; point_2++ )
                if( point_1 == point_2 )
                    continue;
                else if( checkdist( distance, pairs[ point_1 ], pairs[ point_2 ] ) )
                {    
                    printf( "There is no way of packing that polygon.\n" );
                    goto restart;
                }
                else
                {
                    double AB_distance = dist( pairs[ point_1 ], pairs[ point_2 ] );
                    double x_shift = sqrt( R * R - 0.25 * AB_distance ) * ( pairs[ point_1 ][ 1 ] - pairs[ point_2 ][ 1 ] ) / sqrt( AB_distance );
                    double y_shift = sqrt( R * R - 0.25 * AB_distance ) * ( pairs[ point_2 ][ 0 ] - pairs[ point_1 ][ 0 ] ) / sqrt( AB_distance );

                    double point_up_shift[ 2 ], point_down_shift[ 2 ];
                    point_up_shift[ 0 ]     = 0.5 * ( pairs[ point_1 ][ 0 ] + pairs[ point_2 ][ 0 ] ) + x_shift;
                    point_up_shift[ 1 ]     = 0.5 * ( pairs[ point_1 ][ 1 ] + pairs[ point_2 ][ 1 ] ) + y_shift;
                    point_down_shift[ 0 ]   = 0.5 * ( pairs[ point_1 ][ 0 ] + pairs[ point_2 ][ 0 ] ) - x_shift;
                    point_down_shift[ 1 ]   = 0.5 * ( pairs[ point_1 ][ 1 ] + pairs[ point_2 ][ 1 ] ) - y_shift;

                    if( checkcenter( R, pairs, point_num, point_up_shift ) || checkcenter( R, pairs, point_num, point_down_shift ) )
                    {    
                        printf( "The polygon can be packed in the circle.\n" );
                        goto restart;
                    }                    
                }

        //printf( "it get through all of check.\n" );
        printf( "There is no way of packing that polygon.\n" ); 
        //printf( "The polygon can be packed in the circle.\n" );
    }
}
