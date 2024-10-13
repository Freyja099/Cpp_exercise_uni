



// * We should first use the library fstream
// * to write output to a file we use ofstream ( output file stream ) it's like cout 
// * to read input from a file we use ifstream (input file stream ) it's like cin 

// * to open a file for writing : ofstream file_name("file.txt");
// *                                file_name << "...." ;
// *                                file_name.close();

// * to read data from a file : ifstream file_name("file.txt");
// *                            (int/string...) data ; 
// *                            file_name >> data;
// *                            file_name.close();

// * if we want to show the data in screen we can add cout << data ;
// * to ensure that a file is open or not we use file_name.is_open() ; the keyword here is .is_open

// * I used a separate ofstream object (file2) to write to the file, since we can't use the same object for both reading and writing.


#include <iostream>
#include <fstream>
using namespace std;

void compter()
{
    int n = 0;
    ifstream file("name_file.txt");
    if (file.is_open())
    {
        file >> n;
        file.close();
    }
    
    n++;
    
    ofstream file2("name_file.txt");
    file2 << n ;
    file2.close();
    cout << "appel numero : "<<n;
    
}
int main()
{
    compter();
    return 0;

}
// * I added a check to see if the file is open before trying to read from it. 