#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int num;

    while( scanf( "%d", &num ), num )
    {
        long long int rest = 0, mov = 0;

        for( int i = 0, input; i < num; i++ )
        {
            scanf( "%d", &input );

            input = input + rest;
            mov += input > 0 ? input: -input;
            rest = input;
        }

        printf( "%lld\n", mov );
    }

    return 0;
}
