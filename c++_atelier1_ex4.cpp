//* Exercise 4 : Atelier 1 : Two players dice game

// TODO RULES: 
//! - The two players can choose to play with one or two dice in each turn
//! - The score is the sum of all the rolls from all the turns of the game
//! - Before rolling the dice each of them have to choose if they want to roll one or two dice
//! - If one of them choose to play with two dice there's two option :
//!     - If the two dice have the same number, the sum of the two dice will be subtracted from his score
//!     - If the two dice have different numbers, the sum of the two dice will be added to his score
//! - The game ends when one of the players reaches a score of 30 or more

// TODO Q1:
//* il existe une fonction rand() qui fait partie de C Standard Library , il faut declaré la bibliotheque <cstdlib> 
//* pour l'utiliser mais l'utilisation de cette fonction seulement va regénéré les meme chiffre execute la premiere fois 
//* puisqu'elle s'agit de ce qu'on appelle un "pseudorandom number generator" donc on a besoin d'une autre fonction srand
//* qui appartient a la meme library et que cette fois si c'est elle la responsable de génerer la série des nombres que rand
//* va choisir un nombre de cette série mais encore si on execute encore une fois les chiffres ne changerons pas, c'est pour 
//* cela on a besoin de la fonction time(0) qui appartient a la library <ctime> pour acceder au systeme time et changer a chaque
//* fois la serie choisi par srand  


//* In order to generate a random number in cpp we're going to use a function called rand() which is accessible through
//* the c-stead lib library #include <cstdlib>, the rand function is going to return an integer when you call it, 
//* that number can vary from system to system but on any standard implementation to be some number from zero to at least 
//* 32767. However there are some issues, let's say if we called ran function 5 times it will generate 5 random numbers but 
//* we run the program multiple times the rand function is going to generate the same 5 numbers over and over again. This is
//* because the rand is actually a "pseudorandom number generator that follows an algorithm for generating a sequence of numbers
//* whose properties approximate the properties of sequences of random numbers; The generated sequence is not truly random because
//* it is completely determined by an initial value called the seed"
//* if we want to be able to generate different numbers we need to be able to change that seed value and we'll do that by using
//* a function named srand() which is also defined in #include <cstdlib>, this function takes as an argument in integer and that
//* integer determines the sequence of numbers that rand can pull from, still this doesn't solve the problem because I'll we have
//* done is change the default seed value to something else if we run the program over and over again with this new seed value we'll 
//* going to see that it generates the new set of numbers over and over again one solution to this problem is to use the system clock
//* to generate a seed value so that each time we run the program we'll get a new seed value to do so we can access the system time 
//* using the time function now the time returns an integer representation of the current time on your computer which we can pass as 
//* an argument; to access the time we have to include the c time library #include <ctime> 
//* here's an example : int t = time(0);     srand(t);       cout<<rand();


//! rand has no parameter, srand takes an usigned integer as the seed to ensure randomness across different runs we should seed it with 
//! a value that changes commonly done using time(0)
//! for time the parameter is optional but usually we use time(0) or time(NULL) to tell the time function that we don't care about storing
//! the time anywhere just return the current time in seconds as a simple integer 

//* To simulate rolling a die we have to use modulus to generate a number one through six at random 
//* the modulus is going to give us the remaindr of integer division, so when we divide any number by 6 there's only six possible remainders
//* from zero to five since we need that six and we don't need 0, that's why we have to add 1 

// TODO Q2: Throw dice

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int throwdice()
{
    return 1+ rand() % 6;
}


// TODO Q3:

int playerturn()
{
    int number1, number2;
    int score = 0;
    int total = 0;
    int dice;
    cout<<"Voulez-vous lancer un ou deux dés ?"<<endl;
    cin>>dice;
    while ( dice != 1 && dice !=2 )
    {
        cout << "Erreur veuillez entrer le numéro 1 ou 2 : " << endl;
        cin>>dice;
    }

    if ( dice == 1 )
    {
        number1 = throwdice();
        cout << " The number you got is : " << number1 <<endl;
        score = number1;
        total += score ;
    }
    else
    {
        number1 = throwdice();
        number2 = throwdice();
        cout << " The first dice got a number of : " << number1 << " , and the second dice got a number of : " << number2 <<endl;
        score = number1 + number2;
        if ( number1 == number2)
        {
            total -= score;
        }
        else 
        {
            total += score;
        }
    }

return total;

}

// TODO Q4:

int main()
{
    int number;
    int score1=0, score2=0;
    int t = time(0);
    srand(t);
    do
    {
        cout << " Player 1 : " << endl;
        score1 += playerturn();
        cout<< "Votre score est : " <<score1<<endl;
        cout << " Player 2 : " << endl;
        score2 += playerturn();
        cout<< "Votre score est : " <<score2<<endl;

    }while(score1 < 30 && score2 < 30);

    if (score1 >= 30 && score2 >= 30)
    {
        cout << " Draw !" << endl;
    }

    if ( score1 >= 30)
    {
        cout<<" Player number 1 is the winner !" << endl;
        cout << " Your score is: " << score1 << endl;
        cout << " Player number 2 has lost " << endl;
        cout << "Your score is : " << score2 << endl;
    }
    else
    {
        cout<<" Player number 2 is the winner !" << endl;
        cout << " Your score is: " << score2 << endl;
        cout << " Player number 1 has lost " << endl;
        cout << "Your score is : " << score1 << endl;
    }
    
    return 0;
}
