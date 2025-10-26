#include <iostream>
#include <cmath>
using namespace std;

class Complexe {
private:
    double reel;
    double imaginaire;

public:
    Complexe(double r = 0, double i = 0) : reel(r), imaginaire(i) {}

    void afficher() const {
        cout << reel;
        if (imaginaire >= 0) cout << " + ";
        else cout << " - ";
        cout << abs(imaginaire) << "i" << endl;
    }

    Complexe addition(const Complexe& c) const {
        return Complexe(reel + c.reel, imaginaire + c.imaginaire);
    }

    Complexe soustraction(const Complexe& c) const {
        return Complexe(reel - c.reel, imaginaire - c.imaginaire);
    }

    Complexe multiplication(const Complexe& c) const {
        double r = reel * c.reel - imaginaire * c.imaginaire;
        double i = reel * c.imaginaire + imaginaire * c.reel;
        return Complexe(r, i);
    }

    Complexe division(const Complexe& c) const {
        double denom = c.reel * c.reel + c.imaginaire * c.imaginaire;
        if (denom == 0) return Complexe(0, 0);
        double r = (reel * c.reel + imaginaire * c.imaginaire) / denom;
        double i = (imaginaire * c.reel - reel * c.imaginaire) / denom;
        return Complexe(r, i);
    }

    bool egal(const Complexe& c) const {
        return reel == c.reel && imaginaire == c.imaginaire;
    }
};

int main() {
    double r1, i1, r2, i2;
    cin >> r1 >> i1 >> r2 >> i2;
    Complexe c1(r1, i1), c2(r2, i2);
    int choix;
    cin >> choix;
    switch (choix) {
    case 1: c1.addition(c2).afficher(); break;
    case 2: c1.soustraction(c2).afficher(); break;
    case 3: c1.multiplication(c2).afficher(); break;
    case 4: c1.division(c2).afficher(); break;
    case 5: cout << (c1.egal(c2) ? "Oui" : "Non") << endl; break;
    }
    return 0;
}
