#include <cstdio>
#include <cstdlib>

int prime[ 3501 ];

void set_prime()
{
    int index = 0, now = 2;

    do
    {
        for( int i = 2; i * i <= now; i++ )
            if( now % i == 0 )
                goto restart;
        
        prime[ index++ ] = now;
restart:
        now++;
    }
    while( index != 3501 );
}

int solve( int num )
{
    int n = 2, a = 0;

    while( n <= num )
    {
        a += prime[ num - n ] % n;
        a = a % n;    
        n++;
    }

    return a + 1;
}

int main()
{
    int num;

    set_prime();

    while( scanf( "%d", &num ), num != 0 )
        printf( "%d\n", solve( num ) );
    
    return 0;
}
