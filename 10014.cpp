#include<cstdio>


int main()
{
    int cases;
    
    scanf( "%d", &cases );
    
    while( cases-- > 0 )
    {
        int     num;
        double  a0, an1, c, sum = 0;
        
        scanf( "%d%lf%lf", &num, &a0, &an1 );
        
        for( int index = 0; index < num; index++ )
        {
            scanf( "%lf", &c );
            
            sum += ( num - index ) * c;
        }
        
        printf("%.2lf\n", ( num * a0 + an1 - 2 * sum ) / ( num + 1 ) );
        
        if( cases != 0 )
            printf("\n");
    }
    
    return 0;
}
