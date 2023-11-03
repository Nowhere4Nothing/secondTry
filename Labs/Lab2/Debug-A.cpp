#include<iostream>
using namespace std;

void countDown(int highest, int lowest);


// Prints integers from highest to lowest, inclusive.

int main()
{
   int high, low, temp;

   cout << "Enter the highest integer: ";
   cin >> high;

   cout << "Enter the lowest integer: ";
   cin >> low;

   if (high < low)
   {
       temp = low;
       high = low;
       low = temp;
   }

   countDown(high, low);

   return 0;
}

void countDown(int highest, int lowest)
{

   for (int i = highest; i >= lowest; i--) {
       if (i <= lowest) {
           cout << i << "." << endl;
       } else {
           cout << i << ", ";
       }
   }

}
