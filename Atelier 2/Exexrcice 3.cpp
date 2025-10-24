#include <iostream>
using namespace std;

int max1(){
	int tab[10];
	for (int i = 0;i < 10;i++) {

		cout << "tab[" << i + 1 << "] = ";
		cin >> tab[i];
		cout << endl;
		
	}
	int max = tab[0];
	for (int i = 0; i < 10; i++) {
		if(tab[i]>max){
			max = tab[i];
		}
	}
	return max;
}
int max2(int *tab){
	int max = *tab;
	for (int i = 0; i < 10; i++) {
		cout << "tab[" << i+1<< "] = ";
		cin >> *(tab + i);
		cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		if (*(tab + i) > max) {
			max = *(tab + i);
		}
	}
	return max;
}

int main()
{
	int max;
	cout << "methode 1"<< endl;
	max = max1();
	cout << "le maximum est : " << max << endl;
    std::cout << "--------------------------"<< endl;
	cout << "methode 2" << endl;
	int tab[10];
	int	*ptab = tab;
	max=max2(tab);
	cout << "le maximum est : " << max << endl;
	std::cout << "--------------------------" << endl;

	return 0;
 }

