#include <iostream>
using namespace std;

bool isLeapYear(int year);
enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} ;

const int MONTH_COUNT = 12;
int month_lengths[MONTH_COUNT] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char ** argv)
{
    int firstDayOfMonth = TUESDAY;
    int countOfSundays = 0;
    for (int year=1901; year<2001; ++year)
    {
       for (int month=0; month<MONTH_COUNT; ++month)
       {
           if (firstDayOfMonth == SUNDAY)
             ++countOfSundays;

           //Leptetes:
           //szokoev februarjaban 29 nap van
           if (isLeapYear(year) && month==1)
           {
               firstDayOfMonth+=29;
            firstDayOfMonth%=7;
           }
           //Egyebkent a megadott honap napszamaval leptetes
           else
           {
                firstDayOfMonth+=month_lengths[month];
                firstDayOfMonth%=7;
           }

       }
    }
    cout<<"\n Vasarnapok szama: "<<countOfSundays<<endl;
    return 0;
}

/** Eldonti a megadott evrol, hogy szokoev-e az adott ev */
bool isLeapYear(int year)
{
    if (year%4==0)
    {
        if (year%100==0)
        {
            if (year%400==0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}
