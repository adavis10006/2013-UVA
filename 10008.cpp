#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MAXLINE 10000

struct Alpha
{
    char alpha;
    int  frequency;
};

inline int cmp( const void* a, const void* b )
{
    Alpha *A = ( Alpha* ) a, *B = ( Alpha* ) b;

    if( A->frequency > B->frequency || A->frequency == B->frequency && A->alpha < B->alpha ) 
        return -1;
    return 1;
}

int main()
{
    int num;

    Alpha alpha_set[ 26 ];

    for( int index = 0; index < 26; index++ )
    {
        alpha_set[ index ].alpha        = 'A' + index;
        alpha_set[ index ].frequency    = 0;
    }

    scanf( "%d", &num );
    getchar();

    for( int cur = 0; cur < num; cur++ )
    {
        char *line = NULL;
        size_t linecap = 0;
        ssize_t linelen =  getline( &line, &linecap, stdin );
        
        for( int index = 0; index < linelen; index++ )
            if( line[ index ] >= 'a' && line[ index ] <= 'z' )
                alpha_set[ line[ index ] - 'a' ].frequency++;
            else if( line[ index ] >= 'A' && line[ index ] <= 'Z' )
                alpha_set[ line[ index ] - 'A' ].frequency++;
    }

    qsort( alpha_set, 26, sizeof( Alpha ), cmp );
    
    for( int index = 0; index < 26; index++ )
        if( alpha_set[ index ].frequency == 0 )
            break;
        else
            printf( "%c %d\n", alpha_set[ index ].alpha, alpha_set[ index ].frequency );

    return 0;
}
