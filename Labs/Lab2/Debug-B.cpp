#include<iostream>
#include<cmath>

using namespace std;

#define min(a,b) (((a)<(b))? a: b)

int main(int argle, char* argv[])
{
	if ( argle != 3 )
	{
		cerr << "Enter two integers after the program name please!" << endl;
		return 1;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);


	// c is the Lower input of (a, b)
	int c = min(a,b);
	double e  = 2.718;
	
	cout << "log10(10) should be 1 : " << log10(10) << endl;
	cout << "log(e) should be 1    : " << log(exp(1)) << endl;
	cout << "log of lower input is : " << log(c) << endl;


	return 0;
}
