#include <iostream>

using namespace std;

//void maxChoice(int x1, int x2);
void function1(int &x, int y, int h = 3);

int main()
{
//  double val1;
//  double val2;
//  cout<<"Enter a value ";
//  cin>>val1;
//  cout<<"Enter another value";
//  cin>>val2;
//  cout<<val1<<" + "<<val2<<" = "<<(val1 + val2)<<endl;
//  cout<<val2<<" * "<<val2<<" = "<<(val1 * val2)<<endl;

//  int A[3] = {1,2,3};
//  cout << "Starting address " << A << " == " << &A[0] << ", " << A+1 << " == size of an int" << sizeof(int) << endl;
//
//
//    struct Address {
//        string add = "wollongong";
//    };

//    struct Cat {
////        int name;
//        double tailLength;
////        short int y;
//            Address addr;
////        float f;
//        string n;
//
//    };


//
//    Cat mycat;
//    Cat mycat2(1.1 , "gdsfdfhgdhf");
//    string name = "cat";
//    cout << "Cat size = " << sizeof(mycat2) << endl;
//        cout << mycat.addr.add << endl;
;

//int one = 50;
//int two = 100;
//
//cout << maxChoice(one, two) << endl;

//char *arr[] = {"study", "at", "uow"};
//char **ptr = arr;
//int i = 15;
//int *pyr1 = &i;
//int **pnt2 = &pyr1;
//int temp;
//temp = *pyr1;
//
//cout << temp << endl;
//
//cout << "Pointer1 = " << *pyr1 << endl;
//    cout << "address of i = " << i << endl;
//cout << "address of i = " << &i << endl;
//    cout << "the address in ptr1 = " << pyr1 << endl;
//    cout << "Address of pointer1 = " << &pyr1 << endl;
//cout << "the address in pointer2 = " << pnt2 << endl;
//    cout << "Address of pointer2 = " << &pnt2 << endl;
//
//    cout << "Pointer in string = "<<*ptr << endl;
//    cout << "Pointer +1 in string = " << *(ptr+1) << endl;
//    cout << "Pointer then pointer +1 in string = " << * (*ptr+1) << endl;


//auto ii = 11111111111111111111;
//    decltype(ii) y;
//
//    cout << "size of ii =" <<  sizeof(ii) << endl;

//
//**pnt2 = 10;
//
//cout << "Can change i via point2 = " << i << endl;
//int krill = 0;
//int *pntr = &krill;
//cout << *pntr << endl;

//int x = 10;
//int &y = x;
//
//cout << &x << "   "<< &y << endl;
//
//char a1[4] = {'C', '+', '+', '\0'};
//
//cout << a1 << endl;

int x= 3;

function1(x, 8);

cout << x << endl;
}
void function1(int &x, int y = 9, int h) {
    cout << x << endl;
    cout << y << endl;
    cout  << h << endl;

    x += 4;
}

//void maxChoice(int x1, int x2) {
//    if (x1 >= x2) :
//        return x1;
//
//    else :
//        return x2;
//
//}