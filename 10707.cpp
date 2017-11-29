#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAX_W   100
#define MAX_H   100

enum map_state
{
    EMPTY,
    BLACK,
    SELECT,
    USED
};

int map[ 2 ][ MAX_W + 1 ][ MAX_H + 1 ];
int W, H, num;
int Left, Right, Top, Bottom;

class Component
{
public:
    Component( int index )
    {
        w = Right - Left + 1, h = Top - Bottom + 1;
        
        component = new bool [ w * h ];
        
        for( int i = 0; i < w; i++ )
            for( int j = 0; j < h; j++ )
                component[ j * w + i ] = map[ index ][ Left + i ][ Bottom + j ] == SELECT ? true : false;
    }
        
    bool compare( Component B )
    {
        bool is_same;
        
        //printf( "%d %d %d %d\n", w, h, B.w, B.h );
        
        if( !( ( w == B.w && h == B.h ) || ( w == B.h && h == B.w ) ) )
            return false;
        else
        {
            if( w == B.w && h == B.h )
            {
                is_same = true;
                for( int i = 0; i < h; i++ )
                    for( int j = 0; j < w; j++ )
                        if( component[ w * i + j ] != B.component[ w * i + j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < h; i++ )
                    for( int j = 0; j < w; j++ )
                        if( component[ w * i + j ] != B.component[ w * i + ( w - 1 ) - j  ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < h; i++ )
                    for( int j = 0; j < w; j++ )
                        if( component[ w * i + j ] != B.component[ w * ( ( h - 1 ) - i ) + j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < h; i++ )
                    for( int j = 0; j < w; j++ )
                        if( component[ w * i + j ] != B.component[ w * ( ( h - 1 ) - i ) + ( w - 1 ) - j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
            }
            /*
            for( int i = 0; i < w; i++, printf( "\n") )
                for( int j = 0; j < h; j++ )
                    printf( "%c", component[ w * j + i ] ? 'O': '*' );
            printf( "\n" );
        
            for( int i = 0; i < w; i++, printf( "\n") )
                for( int j = 0; j < h; j++ )
                    printf( "%c", B.component[ h * i + j ] ? 'O': '*' );
            printf( "\n" );
            */

            if( w == B.h && h == B.w )
            {
                is_same = true;
                for( int i = 0; i < w; i++ )
                    for( int j = 0; j < h; j++ )
                        if( component[ w * j + i ] != B.component[ h * i + j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < w; i++ )
                    for( int j = 0; j < h; j++ )
                        if( component[ w * j + i ] != B.component[ h * i + ( h - 1 ) - j  ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < w; i++ )
                    for( int j = 0; j < h; j++ )
                        if( component[ w * j + i ] != B.component[ h * ( ( w - 1 ) - i ) + j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
                is_same = true;
                for( int i = 0; i < w; i++ )
                    for( int j = 0; j < h; j++ )
                        if( component[ w * j + i ] != B.component[ h * ( ( w - 1 ) - i ) + ( h - 1 ) - j ] )
                        {
                            is_same = false;
                            break;
                        }
                if( is_same )
                    return true;
            }
            
            return false;
        }
    }
    
    void clear()
    {
        if( component != NULL )
            delete component;
    }
private:
    int w, h;
    bool *component;
};

class Board
{
public:
    void addcomponent( int index )
    {
        component.push_back( new Component( index ) );
    }
    
    bool operator == ( const Board &b )
    {
        std::vector< Component* > A = this->component, B = b.component;
    
        if( A.size() != B.size() )
            return false;
        
        for( int i = 0; i < A.size(); i++ )
        {
            bool have_same = false;
            for( int j = 0; j < B.size(); j++ )
                if( A[ i ]->compare( *B[ j ] ) )
                {
                    B.erase( B.begin() + j );
                    have_same = true;
                    break;
                }
            
            if( !have_same )
                return false;
        }
        return true;
    }
    
    void clear()
    {
        while( !component.empty() )
        {
            component[ 0 ]->clear();
            component.erase( component.begin() );
        }
    }
private:
    std::vector< Component* > component;
};

void DFS_mark( int index, int w, int h )
{
    map[ index ][ w ][ h ] = SELECT;
    
    if( w + 1 < W && map[ index ][ w + 1 ][ h ] == BLACK )
    {
        if( w + 1 > Right )
            Right = w + 1;
        DFS_mark( index, w + 1, h );
    }
    if( w - 1 >= 0 && map[ index ][ w - 1 ][ h ] == BLACK )
    {
        if( w - 1 < Left )
            Left = w - 1;
        DFS_mark( index, w - 1, h );
    }
    if( h + 1 < H && map[ index ][ w ][ h + 1 ] == BLACK )
    {
        if( h + 1 > Top )
            Top = h + 1;
        DFS_mark( index, w, h + 1 );
    }
    if( h - 1 >= 0 && map[ index ][ w ][ h - 1 ] == BLACK )
    {
        if( h -  1 < Bottom )
            Bottom = h - 1;
        DFS_mark( index, w, h - 1 );
    }
}

int main()
{
    int T;
    Board board[ 2 ];
    
    scanf( "%d", &T );
    
    while( T-- )
    {
        board[ 0 ].clear(), board[ 1 ].clear();
        memset( map, EMPTY, sizeof( map ) );
        
        scanf( "%d%d%d", &W, &H, &num );
        
        for( int i = 0, x, y; i < 2; i++ )
        {
            for( int j = 0; j < num; j++ )
            {
                scanf( "%d%d", &x, &y );
                map[ i ][ x ][ y ] = BLACK;
            }
            
            for( int j = 0; j < W; j++ )
                for( int k = 0; k < H; k++ )
                    if( map[ i ][ j ][ k ] == BLACK )
                    {
                        Left = Right = j, Bottom = Top = k;
                        
                        DFS_mark( i, j, k );
                
                        board[ i ].addcomponent( i );
                        
                        for( int jj = Left; jj <= Right; jj++ )
                            for( int kk = Bottom; kk <= Top; kk++ )
                                if( map[ i ][ jj ][ kk ] == SELECT )
                                    map[ i ][ jj ][ kk ] = USED;
                    }
        }
        
        if( board[ 0 ] == board[ 1 ] )
            printf( "YES\n" );
        else
            printf( "NO\n" );
    }
    
    return 0;
}

               