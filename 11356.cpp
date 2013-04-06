#include <cstdio>
#include <cstdlib>
#include <cstring>

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

char *month_map[ 14 ] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int no_leap_during[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap_during[ 12 ] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void input( char* date, int& month, int& day, int& year )
{
    int sum, year_end, month_end, day_end;
    char str_month[ 20 ];

    sum = 0, year_end = 0;
    while( date[ year_end ] != '-' )
        sum = sum * 10 + date[ year_end++ ] - '0';

    year = sum;

    month_end = year_end;
    while( date[ ++month_end ] != '-' );

    strncpy( str_month, date + year_end + 1, month_end - year_end );
    str_month[ month_end - year_end - 1 ] = '\0';

    for( int i = 1; i < 13; i++ )
        if( strcmp( str_month, month_map[ i ] ) == 0 )
        {
            month = i;
            break;
        }

    sum = 0, day_end = month_end;
    while( date[ ++day_end ] != '\0' )
        sum = sum * 10 + date[ day_end ] - '0';

    day = sum;
}

bool checkleap( int year )
{
    if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) )
        return true;

    return false;
}

void dateadd( int times, int month, int day, int year, int less )
{
    if( less == 0 )
    {
        printf( "Case %d: %d-%s-%02d\n", times, year, month_map[ month ], day );
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
    char str_date[ 20 ];
	int num, month, day, year, shift;
    scanf( "%d", &num );

    for( int i = 1; i <= num; i++ )
    {
        char date[ 9 ];
        scanf( "%s%d", str_date, &shift );

        input( str_date, month, day, year );

        dateadd( i, month, day, year, shift );
    }
    return 0;
}
