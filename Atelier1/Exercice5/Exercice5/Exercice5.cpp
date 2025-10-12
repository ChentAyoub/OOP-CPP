#include <iostream>
using namespace std;

void remplir(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {  
        cout << "arr[" << i+1 << "] = ";
        cin >> *(arr + i);
    }
}
void afficher(int* arr, int n) {
  for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
  cout << endl;

}
int& trouverMax(int* arr, int n){
    int indxmax = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) > *(arr + indxmax))
        {
            indxmax = i;
        }
	}
	return *(arr +indxmax);
    
}
void inverser(int* arr, int n){
	int i, j, temp;
    for(i=0, j=n-1;i<n/2;i++,j--){
        temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
	}
	}




int main()
{
    int choix, n;
    cout << "donner la taille du tableau: ";
    cin >> n;
    int* arr = new int[n];
    remplir(arr, n);
    while (true) {
        cout << "pour afficher le tableau taper 1" << endl << "pour trouver le maximum de tableau taper 2" << endl << "pour inverser le tableau taper 3 " << endl << "Quitter? taper 0";
		cout << endl << "votre choix: ";
        cin >> choix;


        switch (choix)
        {

        case 1:
            afficher(arr, n);
            break;
        case 2:
            cout << "le maximum est: " << trouverMax(arr, n) << endl;
            break;
        case 3:
            inverser(arr, n);
            cout << "le tableau apres inversion est: "<< endl;
            afficher(arr, n);
            break;
        case 0:
            cout << "au revoir!" << endl;
            delete[] arr;
            return 0;
        default:
            cout << "choix invalide" << endl;
            break;
        }
    }
}