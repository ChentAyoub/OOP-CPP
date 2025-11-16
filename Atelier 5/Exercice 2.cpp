#include <iostream>
#include <stdexcept>

using namespace std;

class Test {
public:
    static int tableau[];
public:
    static int division(int indice, int diviseur) {
        if (diviseur == 0) {
            throw std::runtime_error("Division par zero impossible.");
        }
        if (indice < 0 || indice >= 10) {
            throw std::out_of_range("Indice hors des limites du tableau.");
        }

        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = { 17, 12, 15, 38, 29, 157, 89, -22, 0, 5 };

int main() {
    try {
        int x, y;

        cout << "Entrez l’indice de l’entier à diviser: " << endl;
        cin >> x;
        if (cin.fail()) {
            throw std::runtime_error("Entree non valide (pas un entier).");
        }

        cout << "Entrez le diviseur: " << endl;
        cin >> y;
        if (cin.fail()) {
            throw std::runtime_error("Entree non valide (pas un entier).");
        }

        int resultat = Test::division(x, y);

        cout << "Le résultat de la division est: " << endl;
        cout << resultat << endl;
    }
    catch (const std::exception& e) {
        cerr << "Une erreur est survenue : " << e.what() << endl;
        cerr << "Arrêt du programme." << endl;
        return 1;
    }

    return 0; 
}