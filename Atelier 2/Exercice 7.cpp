#include <iostream>
using namespace std;


void echanger(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permuter(char chaine[], int debut, int fin) {
    if (debut == fin) {
       
        for (int i = 0; i <= fin; i++) {
            cout << chaine[i];
        }
        cout << endl;
    }
    else {
        for (int i = debut; i <= fin; i++) {
           
            echanger(&chaine[debut], &chaine[i]);
            permuter(chaine, debut + 1, fin);
            echanger(&chaine[debut], &chaine[i]);
        }
    }
}

int main() {
    char chaine[20]; 
    cout << "Entrez une chaine de caracteres : ";
    cin >> chaine;
    int lgt = 0;
    while (chaine[lgt] != '\0') {
        lgt++;
    }
    permuter(chaine, 0, lgt - 1);
    return 0;
}