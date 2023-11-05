#include <fstream>
#include "bibliotheque_cours.hpp"
#include "VilainHeros.hpp"
#include <vector>
using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

using namespace std;


int main()
{
#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
#pragma endregion

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici

	//TODO: Créer d’abord trois vecteurs : un de type Heros, 
	//un autre de type Vilain et le dernier pour y mettre des Personnages.
	vector<Heros> vecteurHeros;
	vector<Vilain> vecteurVilains;
	vector<Personnage> vecteurPersonnages;

	//TODO: Faire la lecture des deux fichiers binaires afin 
	//de placer les héros et les vilains dans les bons vecteurs.
	for (uint16_t i = 0; i < lireUint16(fichierVilains); i++)
	{
		string nom = lireString(fichierVilains);
		string jeu = lireString(fichierVilains);
		string objectif = lireString(fichierVilains);
		vecteurVilains.push_back(Vilain(nom, jeu, objectif));
	}

	fichierVilains.close();

	//TODO: Pour les héros, ajouter chaque allié à l’attribut liste allies d’un héros.
	for (uint16_t i = 0; i < lireUint16(fichierHeros); i++)
	{
		string nom = lireString(fichierHeros);
		string jeu = lireString(fichierHeros);
		string ennemi = lireString(fichierVilains);
		uint8_t nombreAllies = lireUint8(fichierHeros);

		vector<string> vecteurAllies;

		for (uint8_t j = 0; j < nombreAllies; j++)
		{
			string nomAllies = lireString(fichierHeros);
			vecteurAllies.push_back(nomAllies);
		}

		vecteurHeros.push_back(Heros(nom, jeu, ennemi, vecteurAllies));
	}

	fichierHeros.close();

	//TODO: Ensuite, afficher tous vos héros séparés par une ligne 
	//et tous vos vilains séparés par une ligne avec des boucles for 
	//en faisant appel à la méthode afficher, de manière à ce que 
	//l’information s’affiche à la console.
	Heros heros;
	for (auto& heros : vecteurHeros) {
		heros.afficher(cout);
		cout << trait << "\n";
	}

	Vilain vilains;
	for (auto& vilains : vecteurVilains) {
		vilains.afficher(cout);
		cout << trait << "\n";
	}

}