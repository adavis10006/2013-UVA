#include <cstdio>
#include <cstdlib>

/*
Aquarius	    January, 21	        February, 19
Pisces	        February, 20	    March, 20
Aries	        March, 21	        April, 20
Taurus	        April, 21	        May, 21
Gemini	        May, 22	            June, 21
Cancer	        June, 22	        July, 22
Leo	            July, 23	        August, 21
Virgo	        August, 22	        September, 23
Libra	        September, 24	    October, 23
Scorpio	        October, 24	        November, 22
Sagittarius	    November, 23	    December, 22
Capricorn	    December, 23	    January, 20
*/

char* sign[ 13 ] = { "capricorn","aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn" };
int sign_map[ 13 ][ 2 ] =
{
     101,  120,
     121,  219,
     220,  320,
     321,  420,
     421,  521,
     522,  621,
     622,  722,
     723,  821,
     822,  923,
     924, 1023,
    1024, 1122,
    1123, 1222,
    1223, 1231
};

int no_leap_during[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap_during[ 12 ] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void input( char* date, int& month, int& day, int& year )
{
    month = ( date[ 0 ] - '0' ) * 10 + date[ 1 ] - '0';
    day = ( date[ 2 ] - '0' ) * 10 + date[ 3 ] - '0';
    year = ( date[ 4 ] - '0' ) * 1000 + ( date[ 5 ] - '0' ) * 100 + ( date[ 6 ] - '0' ) * 10 + date[ 7 ] - '0';
}

bool checkleap( int year )
{
    if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) )
        return true;

    return false;
}

int checksign( int month, int day )
{
    int temp = 100 * month + day;

    for( int i = 0; i < 13; i++ )
        if( temp >= sign_map[ i ][ 0 ] && temp <= sign_map[ i ][ 1 ] )
            return i;
}

void dateadd( int times, int month, int day, int year, int less )
{
    if( less == 0 )
    {
        printf( "%d %02d/%02d/%04d %s\n", times, month, day, year, sign[ checksign( month, day ) ] );
        return;
    }

    int* yearptr;

    if( checkleap( year ) )
        yearptr = leap_during;
    else
        yearptr = no_leap_during;

    if( less >= yearptr[ month - 1 ] - day + 1 )
        if( month == 12 )
            dateadd( times, 1, 1, year + 1, less - ( yearptr[ month - 1 ] - day + 1 ) );
        else
            dateadd( times, month + 1, 1, year, less - ( yearptr[ month - 1 ] - day + 1 ) );
    else
        dateadd( times, month, day + less, year, 0 );
}

int main()
{
    int num, month, day, year;

    scanf( "%d", &num );

    for( int i = 1; i <= num; i++ )
    {
        char date[ 9 ];
        scanf( "%s", date );

        input( date, month, day, year );

        dateadd( i, month, day, year, 280 );
    }
    return 0;
}
