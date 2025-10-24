#include <iostream>
using namespace std;

int multiple2(int n)
{
    return n % 2 == 0;
}
int multiple3(int n)
{
    return n % 3 == 0;
}
int main()
{   
	int n;
	int exiter = 1;
    while (true)
    {
        cout << "donner moi un entier:" << endl;
        cin >> n;
        if (multiple2(n)) {
            cout << n << " est pair" << endl;
        }
        if (multiple3(n))
        {
            if (multiple2(n)) {
                cout << n << " est divisible par 6" << endl;
            }
            cout << n << " est multiple de 3" << endl;

        }
        cout << "----------pour exiter entrer 0 ------------" << endl;
		cin >> exiter;
        if (exiter == 0) {
            break;
        }

    }
    
	return 0;
}

