#include <cstdio>

//n != k * ( p * p )
bool checkPrime( const int num )
{
    for( int cur = 2; cur * cur <= num; cur++ )
        if( num % cur == 0 )
            return false;
    
    return true;
}


bool checkCarmichael( const int num )
{
    int number = num;

    for( int cur = 2, squ= cur * cur; cur < num; cur++, squ = cur * cur )
        if( squ > num )
            break;
        else if( num % squ == 0 )
            return false;

    int prime = 2;
    while( prime <= number )
    {
        if( number % prime == 0 )
        {    
            if( ( num - 1 ) % ( prime - 1 ) != 0 )
                return false;
            
            number /= prime;
            continue;
        }
        prime++;
    }

    return true;
}

int main()
{
    int num;

    while( true )
    {
        scanf( "%d", &num );
     
        if( num == 0 )
            return 0;
    
        if( !checkPrime( num ) && checkCarmichael( num ) )
            printf( "The number %d is a Carmichael number.\n", num );
        else        
            printf( "%d is normal.\n", num );
           
    }
}
