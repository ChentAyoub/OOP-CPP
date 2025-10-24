
#include <iostream>
using namespace std;

int main()
{
    int a = 123;
	int* p_a = a;
    int &ref_a = a;

	cout << "Value of a: " << a << endl;
	cout << "Value of a using pointer: " << *p_a << endl;
	cout << "Value of a using reference: " << ref_a << endl;
	return 0;
}
