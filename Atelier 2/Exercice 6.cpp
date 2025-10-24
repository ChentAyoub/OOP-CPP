#include <iostream>
using namespace std;
    
void incrementer(int &val)
{
    val++;
}
void permuter(int &val1, int &val2) {
        int temp = val1;
        val1 = val2;
	    val2 = temp;
}

int main()
{
	int val1, val2;
	cout << "donnez deux entiers: ";
	cin >> val1;
	cin >> val2;
	cout << "val1 = " << val1 << ", val2 = " << val2 << endl;
	incrementer(val1);
	cout << "val1 = " << val1 << endl;
	permuter(val1, val2);
	cout << "val1 = " << val1 << ", val2 = " << val2 << endl;



}

