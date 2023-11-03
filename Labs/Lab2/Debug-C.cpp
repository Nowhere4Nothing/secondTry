#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   int bookId;
   string name;
   double price;  

   const string note1 = "Enter ID, name, and price";
   const string note2 = "Enter end-of-file key combination (Ctrl-d) to end ";

      cout << note1 << endl;
      cin >> bookId >> name >> price;


   ofstream outFile;
   outFile.open("library.txt");

   if (!outFile)
      {
         cout << "File could not be opened" << endl;
         return 1;
      }

   
   while ( cin >> bookId >> name >> price )
   {
      outFile << bookId << " " << name << " " << price << endl;
      cout << bookId << endl << name << price << endl;
   }

   outFile.close();

   return 0;
}
