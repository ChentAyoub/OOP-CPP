#include <iostream>
using namespace std;

class Fichier {
private:
    char* P;      
    int longueur; 

public:
    
    Fichier() {
        P = nullptr;
        longueur = 0;
        cout << "Fichier cree" << endl;
    }

    
    void Creation(int taille) {
        longueur = taille;
        P = new char[longueur];
       
    }

    void Remplit() {
        if (!P) {
            cout << "Erorre d'allocation" << endl;
            return;
        }
        for (int i = 0; i < longueur; i++) {
            P[i] = 'A' + i;
        }
        cout << "Zone memoire remplie" << endl;
    }

   
    void Affiche() {
        if (!P) {
            cout << "Vide" << endl;
            return;
        }
        cout << "Contenu du fichier :" << endl;
        for (int i = 0; i < longueur; i++) {
            cout << P[i];
        }
        cout << endl;
    }

  
    ~Fichier() {
        delete[] P;
        cout << "Memoire liberee, Fichier detruit." << endl;
    }
};

int main() {
    Fichier* f = new Fichier();  
    f->Creation(20); 
    f->Remplit();   
    f->Affiche();    

    delete f;        

    
    return 0;
}