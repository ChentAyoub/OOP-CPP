#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element* suivant;
};

class Liste {
private:
    Element* debut;

public:
    Liste() {
        debut = nullptr;
    }

    void ajouterAuDebut(int val) {
        Element* e = new Element;
        e->valeur = val;
        e->suivant = debut;
        debut = e;
    }

    void supprimerAuDebut() {
        if (debut != nullptr) {
            Element* temp = debut;
            debut = debut->suivant;
            delete temp;
        }
    }

    void afficher() {
        Element* courant = debut;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    ~Liste() {
        while (debut != nullptr) {
            Element* temp = debut;
            debut = debut->suivant;
            delete temp;
        }
    }
};

int main() {
    Liste maListe;

    maListe.ajouterAuDebut(0);
    maListe.ajouterAuDebut(11);
    maListe.ajouterAuDebut(47);
    maListe.afficher();
    maListe.supprimerAuDebut();
    maListe.afficher();
    maListe.supprimerAuDebut();
    maListe.supprimerAuDebut();
    maListe.afficher();

    return 0;
}