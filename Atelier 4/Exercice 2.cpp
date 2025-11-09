#include <iostream>
#include <string>
#include <vector>

class AgentBancaire;
class Banque;

class Client {
private:
    int idClient;
    std::string nom;
    std::string cin;

public:
    Client(int id, std::string n, std::string c)
        : idClient(id), nom(n), cin(c) {
    }

    std::string getNom() const { return nom; }
    std::string getCin() const { return cin; }
    int getId() const { return idClient; }

    void afficher() const {
        std::cout << "  - Client ID: " << idClient << ", Nom: " << nom << ", CIN: " << cin << std::endl;
    }

    friend class AgentBancaire;
};

class CompteBancaire {
private:
    int numCompte;
    double solde;
    int codeSecret;
    Client& proprietaire;

public:
    CompteBancaire(int num, double s, int code, Client& prop)
        : numCompte(num), solde(s), codeSecret(code), proprietaire(prop) {
    }

    int getNumCompte() const { return numCompte; }
    Client& getProprietaire() const { return proprietaire; }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            std::cout << "Depot de " << montant << " effectue. Nouveau solde: " << solde << std::endl;
        }
    }

    bool retirer(double montant, int code) {
        if (code == codeSecret) {
            if (montant <= solde) {
                solde -= montant;
                std::cout << "Retrait de " << montant << " effectue. Nouveau solde: " << solde << std::endl;
                return true;
            }
            else {
                std::cout << "Solde insuffisant." << std::endl;
                return false;
            }
        }
        else {
            std::cout << "Code secret incorrect." << std::endl;
            return false;
        }
    }

    friend class AgentBancaire;
    friend class Banque;
};

class AgentBancaire {
public:
    void consulterCodeSecret(const CompteBancaire& compte) {
        std::cout << "[AGENT] Le code secret du compte " << compte.numCompte
            << " est: " << compte.codeSecret << std::endl;
    }

    bool transfertInterne(CompteBancaire& source, CompteBancaire& dest, double montant) {
        std::cout << "[AGENT] Tentative de transfert de " << montant
            << " du compte " << source.numCompte << " vers " << dest.numCompte << std::endl;

        if (source.solde >= montant) {
            source.solde -= montant;
            dest.solde += montant;
            std::cout << "[AGENT] Transfert reussi." << std::endl;
            return true;
        }
        else {
            std::cout << "[AGENT] Echec, solde source insuffisant." << std::endl;
            return false;
        }
    }
};

class Banque {
private:
    std::vector<Client*> clients;
    std::vector<CompteBancaire*> comptes;

public:
    ~Banque() {
        for (CompteBancaire* c : comptes) delete c;
        for (Client* cl : clients) delete cl;
    }

    void ajouterClient(Client* client) {
        clients.push_back(client);
    }

    void ajouterCompte(CompteBancaire* compte) {
        comptes.push_back(compte);
    }

    void rapportAuditInterne() {
        std::cout << "\n--- RAPPORT D'AUDIT INTERNE (CONFIDENTIEL) ---" << std::endl;
        for (CompteBancaire* compte : comptes) {
            std::cout << "Compte: " << compte->numCompte
                << ", Proprietaire: " << compte->proprietaire.getNom()
                << ", Solde (prive): " << compte->solde
                << ", Code (prive): " << compte->codeSecret
                << std::endl;
        }
        std::cout << "----------------------------------------------\n" << std::endl;
    }
};

int main() {
    Client* client1 = new Client(101, "Yassine Alaoui", "A123");
    Client* client2 = new Client(102, "Fatima Zahra", "B456");

    CompteBancaire* compte1 = new CompteBancaire(1001, 5000.0, 1234, *client1);
    CompteBancaire* compte2 = new CompteBancaire(1002, 2000.0, 9876, *client2);

    Banque maBanque;
    maBanque.ajouterClient(client1);
    maBanque.ajouterClient(client2);
    maBanque.ajouterCompte(compte1);
    maBanque.ajouterCompte(compte2);

    std::cout << "--- Operations Client ---" << std::endl;
    compte1->deposer(500);
    compte1->retirer(1000, 1234);
    compte1->retirer(500, 0000);

    std::cout << "\n--- Operations Agent ---" << std::endl;
    AgentBancaire agent;
    agent.consulterCodeSecret(*compte2);
    agent.transfertInterne(*compte1, *compte2, 1500);

    maBanque.rapportAuditInterne();

    return 0;
}
