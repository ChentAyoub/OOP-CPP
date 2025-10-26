#include <iostream>
#include <cmath>

using namespace std;

class vecteur3d {
public:
    int x, y, z;

    vecteur3d(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

    void afficher() {
        cout << "x: " << x << " y: " << y << " z: " << z << endl;
    }

    void somme(vecteur3d v1, vecteur3d v2) {
        x = v1.x + v2.x;
        y = v1.y + v2.y;
        z = v1.z + v2.z;
    }

    void produit_scalaire(vecteur3d v1, vecteur3d v2) {
        int produit = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        cout << "Produit scalaire: " << produit << endl;
    }

    void coincidence(vecteur3d v1, vecteur3d v2) {
        if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
            cout << "Les vecteurs sont coincidents." << endl;
        else
            cout << "Les vecteurs ne sont pas coincidents." << endl;
    }

    double norme() {
        return sqrt(x * x + y * y + z * z);
    }

    void normax(vecteur3d v1, vecteur3d v2) {
        double n1 = v1.norme();
        double n2 = v2.norme();
        if (n1 > n2)
            cout << "Le vecteur 1 a la plus grande norme." << endl;
        else if (n2 > n1)
            cout << "Le vecteur 2 a la plus grande norme." << endl;
        else
            cout << "Les deux vecteurs ont la même norme." << endl;
    }
};

int main() {
    
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(4, 0, 5);
    cout << "Vecteur 1 : "; v1.afficher();
    cout << "Vecteur 2 : "; v2.afficher();
    vecteur3d sommeV;
    sommeV.somme(v1, v2);
    cout << "Somme : "; sommeV.afficher();
    sommeV.produit_scalaire(v1, v2);
    sommeV.coincidence(v1, v2);
    cout << "Norme v1 : " << v1.norme() << endl;
    cout << "Norme v2 : " << v2.norme() << endl;
    sommeV.normax(v1, v2);

    return 0;
}
