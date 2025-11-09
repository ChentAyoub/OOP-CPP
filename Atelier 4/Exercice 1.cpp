#include <iostream>
#include <string>
#include <vector>

class Ressource {
protected:
    int id;
    std::string titre;
    std::string auteur;
    int annee;

public:
    Ressource(int id, std::string t, std::string a, int an)
        : id(id), titre(t), auteur(a), annee(an) {
    }

    virtual ~Ressource() {}

    virtual void afficherInfos() {
        std::cout << "ID: " << id << ", Titre: " << titre
            << ", Auteur: " << auteur << ", Annee: " << annee;
    }

    virtual void telecharger() {
        std::cout << "Telechargement generique de la RESSOURCE..." << std::endl;
    }

    bool operator==(const Ressource& other) const {
        return this->id == other.id;
    }

    std::string getTitre() const { return titre; }
    std::string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }
};

class Telechargeable {
public:
    virtual ~Telechargeable() {}

    void telecharger() {
        std::cout << "Telechargement via interface TELECHARGEABLE..." << std::endl;
    }

    void afficherMessage() {
        std::cout << "-> Ce contenu est telechargeable." << std::endl;
    }
};

class Livre : public Ressource, public Telechargeable {
private:
    std::string isbn;

public:
    Livre(int id, std::string t, std::string a, int an, std::string i)
        : Ressource(id, t, a, an), isbn(i) {
    }

    void afficherInfos() override {
        std::cout << "[LIVRE] ";
        Ressource::afficherInfos();
        std::cout << ", ISBN: " << isbn << std::endl;
    }

    void telecharger() override {
        std::cout << "Telechargement du LIVRE (ISBN: " << isbn << ")..." << std::endl;
        Telechargeable::afficherMessage();
    }
};

class Magazine : public Ressource, public Telechargeable {
private:
    int numeroEdition;

public:
    Magazine(int id, std::string t, std::string a, int an, int num)
        : Ressource(id, t, a, an), numeroEdition(num) {
    }

    void afficherInfos() override {
        std::cout << "[MAGAZINE] ";
        Ressource::afficherInfos();
        std::cout << ", Edition: " << numeroEdition << std::endl;
    }

    void telecharger() override {
        std::cout << "Telechargement du MAGAZINE (Edition: " << numeroEdition << ")..." << std::endl;
    }
};

class Video : public Ressource, public Telechargeable {
private:
    int dureeMinutes;

public:
    Video(int id, std::string t, std::string a, int an, int duree)
        : Ressource(id, t, a, an), dureeMinutes(duree) {
    }

    void afficherInfos() override {
        std::cout << "[VIDEO] ";
        Ressource::afficherInfos();
        std::cout << ", Duree: " << dureeMinutes << " min" << std::endl;
    }

    void telecharger() override {
        std::cout << "Telechargement de la VIDEO (Duree: " << dureeMinutes << " min)..." << std::endl;
    }
};

class Mediatheque {
private:
    std::vector<Ressource*> ressources;

public:
    ~Mediatheque() {
        for (Ressource* res : ressources) {
            delete res;
        }
    }

    void ajouter(Ressource* res) {
        ressources.push_back(res);
        std::cout << "Ressource '" << res->getTitre() << "' ajoutee." << std::endl;
    }

    void afficher() {
        std::cout << "\n--- Contenu de la Mediatheque ---" << std::endl;
        if (ressources.empty()) {
            std::cout << "Mediatheque vide." << std::endl;
            return;
        }
        for (Ressource* res : ressources) {
            res->afficherInfos();
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    void rechercher(std::string titre) {
        std::cout << "\nRecherche par titre '" << titre << "':" << std::endl;
        bool trouve = false;
        for (Ressource* res : ressources) {
            if (res->getTitre() == titre) {
                res->afficherInfos();
                trouve = true;
            }
        }
        if (!trouve) std::cout << "Aucune ressource trouvee." << std::endl;
    }

    void rechercher(int annee) {
        std::cout << "\nRecherche par annee '" << annee << "':" << std::endl;
        bool trouve = false;
        for (Ressource* res : ressources) {
            if (res->getAnnee() == annee) {
                res->afficherInfos();
                trouve = true;
            }
        }
        if (!trouve) std::cout << "Aucune ressource trouvee." << std::endl;
    }

    void rechercher(std::string auteur, int annee) {
        std::cout << "\nRecherche par auteur '" << auteur << "' et annee '" << annee << "':" << std::endl;
        bool trouve = false;
        for (Ressource* res : ressources) {
            if (res->getAuteur() == auteur && res->getAnnee() == annee) {
                res->afficherInfos();
                trouve = true;
            }
        }
        if (!trouve) std::cout << "Aucune ressource trouvee." << std::endl;
    }
};

int main() {
    Livre* livre1 = new Livre(1, "Rihlat Al-Sahra", "Ahmed Bennani", 1965, "978-0441172719");
    Magazine* mag1 = new Magazine(2, "Majalla Al-Tabi'a", "Mukhtalifun", 2024, 11);
    Video* video1 = new Video(3, "Madkhal C++", "Prof Hassan", 2023, 45);
    Livre* livre2 = new Livre(4, "Rihlat Al-Sahra Al-Thaniya", "Ahmed Bennani", 1969, "978-0441172696");

    Mediatheque maBiblio;
    maBiblio.ajouter(livre1);
    maBiblio.ajouter(mag1);
    maBiblio.ajouter(video1);
    maBiblio.ajouter(livre2);

    maBiblio.afficher();

    maBiblio.rechercher("Rihlat Al-Sahra");
    maBiblio.rechercher(2023);
    maBiblio.rechercher("Ahmed Bennani", 1969);

    std::cout << "\n--- Test Telechargement ---" << std::endl;

    std::cout << "Appel normal: ";
    livre1->telecharger();

    std::cout << "Appel qualifie (Ressource): ";
    livre1->Ressource::telecharger();

    std::cout << "Appel qualifie (Telechargeable): ";
    livre1->Telechargeable::telecharger();

    std::cout << "\n--- Test Comparaison (ID) ---" << std::endl;
    Livre livreCompare(1, "Test Darija", "Fatima Al-Zahra", 2000, "123");

    if (*livre1 == *video1) {
        std::cout << "livre1 et video1 ont le meme ID (Erreur)" << std::endl;
    }
    else {
        std::cout << "livre1 et video1 ont des ID differents (Correct)" << std::endl;
    }

    if (*livre1 == livreCompare) {
        std::cout << "livre1 et livreCompare ont le meme ID (Correct)" << std::endl;
    }

    return 0;
}
