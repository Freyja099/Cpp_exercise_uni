#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;
string Day(int day);
void ExtraireDate (const string& date)
{
    string jour = { date[0] , date[1] };
    string mois = { date[2] , date[3] };
    string annee = { date[4] , date[5] , date[6] , date[7]};
    string heure = { date[8] , date[9] };
    string minute = { date[10] , date[11] };

    vector <string> mois_vect = { " " , "January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"};

    // * Add st , nd , rd , th for day and check if it's < 30  and month if it's < 12

    int day = stoi(jour);
    int month = stoi(mois);

    if(day > 30 || day == 00)
    {
        cout << "Invalid day number" <<endl;
    }
    if(month > 12 || month == 00)
    {
        cout << "Invalid month number" <<endl;
    }

   /* if ((day - 1 ) % 10 == 0)
    {
        jour = day + "st";
    }
    else if ((day - 2 ) % 10 == 0)
    {
        jour = day + "nd";
    }
    else if ((day - 3 ) % 10 == 0)
    {
        jour = day + "rd";
    }
    else
    jour = day + "th";*/


    cout << day << Day(day) << " " << mois_vect[month] << " " << annee << "  à  " << heure << "h" << minute <<endl;

}

string Day(int day)
{
    string Day_string;
    if (day % 10 == 1 && day != 11)
    return "st";

    else if(day % 10 == 2 && day != 12)
    return "nd";

    else if (day % 10 == 3 && day != 13)
    return "rd";

    else 
    return "th";
}
int main()
{
    string date ;
    cout << "Enter the date (DDMMYYYYHHMM): ";
    cin >> date;
    ExtraireDate(date);

    return 0;
    
}