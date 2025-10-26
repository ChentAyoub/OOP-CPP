#include <iostream>
class voiture {
	public:
		std::string marque;
		std::string modele;
		int annee;
		float kilometrage;
		float vitesse;
	voiture() {
		marque = "Buick";
		modele = "GNX";
		annee = 1987;
		kilometrage = 159325.06;
		vitesse = 0;
	}
	voiture(std::string mar, std::string mod, int ann, float km, float vts) {
		marque = mar;
		modele = mod;
		annee = ann;
		kilometrage = km;
		vitesse = vts;
	}
	void accelerer(float x){
		vitesse += x;
	}
	void freiner(float y) {
		vitesse -= y;
		if (vitesse < 0) {
			vitesse = 0;
		}
	}
	void afficherinfo(){
		std::cout << "Marque: " << marque << std::endl;
		std::cout << "Modele: " << modele << std::endl;
		std::cout << "Annee: " << annee << std::endl;
		std::cout << "Kilometrage: " << kilometrage << std::endl;
		std::cout << "Vitesse: " << vitesse << std::endl;
	}
	void avancer(float z) {
		kilometrage += z;
	}
	~voiture() {
		std::cout << "La voiture " << marque << " " << modele << " a ete detruite." << std::endl;
	}

};


int main()
{
	voiture voiture1;
	voiture1.afficherinfo();
	voiture1.accelerer(200);
	voiture1.afficherinfo();
	voiture voiture2("BMW", "M3 G80", 2020, 50524, 0);
	voiture voiture3("Ford", "Mustang", 1969, 126782, 0);
	voiture2.afficherinfo();
	voiture3.afficherinfo();
	return 0;
}