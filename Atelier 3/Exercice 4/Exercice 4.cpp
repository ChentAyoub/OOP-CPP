#include <iostream>
#include <string>
using namespace std;


class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    
    Client() {
        id = 0;
        nom = "";
        prenom = "";
    }

    
    Client(int i, string n, string p) {
        id = i;
        nom = n;
        prenom = p;
    }

    
    Client(const Client& autre) {
        id = autre.id;
        nom = autre.nom;
        prenom = autre.prenom;
    }

    
    ~Client() {
       
    }

    
    void afficher() const {
        cout << "Client: " << id << " - " << nom << " " << prenom << endl;
    }
};


class Compte {
private:
    int numero;
    float solde;
    Client* client;

    static int totalComptes;

public:
    
    Compte() {
        numero = 0;
        solde = 0.0;
        client = nullptr;
        totalComptes++;
    }

    
    Compte(int num, float s, Client* c) {
        numero = num;
        solde = s;
        if (c) {
            client = new Client(*c); 
        }
        else {
            client = nullptr;
        }
        totalComptes++;
    }

    
    Compte(const Compte& autre) {
        numero = autre.numero;
        solde = autre.solde;
        if (autre.client)
            client = new Client(*autre.client);
        else
            client = nullptr;
        totalComptes++;
    }

    
    ~Compte() {
        if (client)
            delete client;
        totalComptes--;
    }

    void afficher() const {
        cout << "Compte n" << numero << " - Solde: " << solde << endl;
        if (client)
            client->afficher();
        else
            cout << "Pas de client associe." << endl;
    }

    static void afficherTotal() {
        cout << "Nombre total de comptes: " << totalComptes << endl;
    }

    float getSolde() const {
        return solde;
    }

    void setSolde(float s) {
        solde = s;
    }
};


int Compte::totalComptes = 0;


inline float calculInteret(float solde, float taux) {
    return solde + solde * taux;
}


int main() {
    
    Client c1(1, "Chentouf", "Ayoub");
    Client c2(2, "Chentouf", "Ayoub");
    Compte* compte1 = new Compte(1001, 1000.0, &c1);
    Compte* compte2 = new Compte(1002, 2000.0, &c2);
    Compte::afficherTotal();
    Compte* compte3 = new Compte(*compte1);
    Compte::afficherTotal();
    compte1->afficher();
    compte2->afficher();
    compte3->afficher();
    float nouveauSolde = calculInteret(compte1->getSolde(), 0.08);
    compte1->setSolde(nouveauSolde);
    cout << "apres interes" << endl;
    compte1->afficher();
    delete compte2;
    Compte::afficherTotal();
    delete compte1;
    delete compte3;
    Compte::afficherTotal();

    return 0;
}
 /* 1) difference entre copie superficielle et copie profonde
 copie superficielle : on copie juste le pointeur vers le client, si un compte est detruit l'autre plante
 copie profonde : on cree un vrai nouveau client pour chaque compte, pas de probleme

 2) pourquoi le compteur de comptes doit etre static
 parce que c'est pour tous les comptes en meme temps, pas un compteur par compte

 3) difference entre methode statique et normale
 statique : tu peux l'appeler sans objet, juste Compte::afficherTotal()
 normale : tu dois appeler sur un objet, peut acceder aux membres de cet objet

 4) quand mettre une fonction inline
 quand c'est petit et utilise souvent, ca evite le surcout d'appel de fonction

 5) que se passe si on oublie delete dans le destructeur
 fuite memoire, le programme garde la memoire meme apres la fin des objets, ca peut ralentir ou planter */

