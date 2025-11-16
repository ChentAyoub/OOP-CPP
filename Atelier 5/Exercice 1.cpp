#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <iterator>
using namespace std;

bool rechercherDansSet(const set<int>& s, int valeur) {
   
    return s.find(valeur) != s.end();
}
bool rechercherAvecIterateursSet(set<int>::const_iterator debut, set<int>::const_iterator fin, int valeur) {
    for (auto it = debut; it != fin; ++it) {
        if (*it == valeur) {
            return true;
        }
    }
    return false;
}
template <typename InputIterator, typename T>
bool rechercherGenerique(InputIterator debut, InputIterator fin, const T& valeur) {
    for (auto it = debut; it != fin; ++it) {
        if (*it == valeur) {
            return true;
        }
    }
    return false;
}


int main() {
    
    cout << boolalpha;
    set<int> monSet;
    for (int i = 1; i <= 100; ++i) {
        monSet.insert(i);
    }
    cout << "--- Test Fonction 2 (sur Set) ---" << endl;
    cout << "Recherche 50 : " << rechercherDansSet(monSet, 50) << endl;
    cout << "Recherche 150 : " << rechercherDansSet(monSet, 150) << endl;
    cout << "\n--- Test Fonction 3 (sur Itérateurs Set) ---" << endl;
    cout << "Recherche 75 : " << rechercherAvecIterateursSet(monSet.cbegin(), monSet.cend(), 75) << endl;
    cout << "Recherche 200 : " << rechercherAvecIterateursSet(monSet.cbegin(), monSet.cend(), 200) << endl;
    cout << "---- Test Fonction 4 (Template) ---" << endl;
    vector<string> vecStr = { "bonjour", "monde", "!", "test" };
    cout << "Vecteur de string :" << endl;
    cout << "Recherche 'monde' : " << rechercherGenerique(vecStr.begin(), vecStr.end(), string("monde")) << endl;
    cout << "Recherche 'allo' : " << rechercherGenerique(vecStr.begin(), vecStr.end(), string("allo")) << endl;
    list<int> listInt = { 10, 20, 30, 40 };
    cout << "Liste d'entiers :" << endl;
    cout << "Recherche 30 : " << rechercherGenerique(listInt.begin(), listInt.end(), 30) << endl;
    cout << "Recherche 5 : " << rechercherGenerique(listInt.begin(), listInt.end(), 5) << endl;
    float tabFloat[] = { 1.1f, 2.2f, 3.3f, 4.4f };
    cout << "Tableau de float :" << endl;
    cout << "Recherche 3.3 : " << rechercherGenerique(std::begin(tabFloat), std::end(tabFloat), 3.3f) << endl;
    cout << "Recherche 9.9 : " << rechercherGenerique(std::begin(tabFloat), std::end(tabFloat), 9.9f) << endl;

    return 0;
}