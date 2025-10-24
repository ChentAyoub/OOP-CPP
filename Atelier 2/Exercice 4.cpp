#include <iostream>
using namespace std;

int main()
{
    int n;
	cout << "Entrez la taille du tableau: ";
	cin >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Entrez l'element " << i + 1 << ": ";
		cin >> *(tab+i);
	}
	int* tab2 = new int[n];
	for(int i = 0; i<n ; i++)
	{
		*(tab2 + i) = *(tab + i);
	}
	cout << "Le tableau copie est: ";
	for(int i=0; i<n; i++)
	{
		cout << *(tab2 + i) << " ";
	}
	delete[] tab;
	delete[] tab2;
	return 0;
}