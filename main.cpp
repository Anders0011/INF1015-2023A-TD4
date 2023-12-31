﻿/*
Fichier : main.cpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier  main.cpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/



#include <fstream>
#include "VilainHeros.hpp"
#include "bibliotheque_cours.hpp"
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
	vector<shared_ptr<Personnage>> vecteurPersonnages;
	//vector<Personnage> vecteurPersonnages;

	//TODO: Faire la lecture des deux fichiers binaires afin 
	//de placer les héros dans les bons vecteurs.
	if (fichierHeros.is_open()) {
		UInt16 nombreHeros = lireUint16(fichierHeros);
		for (UInt16 i = 0; i < nombreHeros; i++) {
			string nom = lireString(fichierHeros);
			string titreJeu = lireString(fichierHeros);
			string ennemi = lireString(fichierHeros);

			//TODO: Pour les héros, ajouter chaque allié à l’attribut liste allies d’un héros.
			vector<string> vecteurAllies;
			UInt8 nombreAllies = lireUint8(fichierHeros);
			for (UInt8 j = 0; j < nombreAllies; j++) {
				string Allie = lireString(fichierHeros);
				vecteurAllies.push_back(Allie);
			}

			Heros hero(nom, titreJeu, ennemi, vecteurAllies);
			vecteurHeros.push_back(hero);
		}

		fichierHeros.close();
	}

	//TODO: Faire la lecture des deux fichiers binaires afin 
	//de placer les vilains dans les bons vecteurs.

	if (fichierVilains.is_open()) {
		UInt16 nombreVilains = lireUint16(fichierVilains);
		for (UInt16 i = 0; i < nombreVilains; i++) {
			string nom = lireString(fichierVilains);
			string titreJeu = lireString(fichierVilains);
			string objectif = lireString(fichierVilains);

			Vilain vilain(nom, titreJeu, objectif);
			vecteurVilains.push_back(vilain);
		}

		fichierVilains.close();
	}


	//TODO: Ensuite, afficher tous vos héros séparés par une ligne 
	//et tous vos vilains séparés par une ligne avec des boucles for 
	//en faisant appel à la méthode afficher, de manière à ce que 
	//l’information s’affiche à la console.
	//TODO: Afficher les informations des héros d’une couleur différente de celles des vilains.
	//Par exemple en bleu pour les héros, en rouge pour les vilains.
	// Affichage des héros en bleu
	cout << "Liste des heros : \n\n";
	for (Heros& heros : vecteurHeros) {
		heros.changerCouleur(cout, "Bleu");
		heros.afficher(cout);
		heros.changerCouleur(cout, "");
		cout << trait << "\n";
	}

	cout << "Liste des vilains : \n\n";
	for (Vilain& vilains : vecteurVilains) {
		vilains.changerCouleur(cout, "Rouge");
		vilains.afficher(cout);
		vilains.changerCouleur(cout, "");
		cout << trait << "\n";
	}

	//TODO:Placer tous les héros et vilains dans le vecteur de personnages. 
	// Le polymorphisme nous permet une telle opération car les héros et les vilains sont des personnages.
	for (const Heros& heros : vecteurHeros)
	{
		shared_ptr hero = make_shared<Heros>(heros.getNom(), heros.getTitre(), heros.getEnnemi(), heros.getListeAllies());
		vecteurPersonnages.push_back(hero);
	}

	for (const Vilain& vilains : vecteurVilains)
	{
		shared_ptr vilain = make_shared<Vilain>(vilains.getNom(), vilains.getTitre(), vilains.getObjectif());
		vecteurPersonnages.push_back(vilain);
	}

	//TODO: Afficher ensuite chaque personnage du vecteur de personnages toujours en faisant appel à la méthode
	// afficher, encore avec les héros et vilains de couleurs différentes.	 
	cout << "Liste des personnages (Heros et Vilains) : \n" << endl;
	for (auto&& personnage : vecteurPersonnages) {
		shared_ptr<Heros> heros = dynamic_pointer_cast<Heros>(personnage);
		shared_ptr<Vilain> vilain = dynamic_pointer_cast<Vilain>(personnage);
		if (heros)
			heros->changerCouleur(cout, "Bleu");
		else if (vilain)
			vilain->changerCouleur(cout, "Rouge");
		personnage->afficher(cout);
		personnage->changerCouleur(cout, "");
		cout << trait << endl;
	}

	//TODO: Finalement, créer un VilainHeros en passant à son constructeur un vilain et héros de votre choix,
	//venant des vecteurs de vilains et héros, en autant que le vilain n’est pas l’ennemi du héros ! 
	//Afficher-le à l’écran avec une troisième couleur, par exemple en mauve. L’ajouter aussi au vecteur de 
	//personnages pour voir si l’affichage du vecteur fonctionne correctement pour tous nos types de personnages
	//(les héros, vilains et vilains héros sont affichés correctement avec toutes leurs informations, et des couleurs différentes).
	
	cout << "VilainHeros exemplaire : \n\n";
	VilainHeros vilainHeros(vecteurVilains[0], vecteurHeros[2]);
	vilainHeros.changerCouleur(cout, "Magenta");
	vilainHeros.afficher(cout);
	vilainHeros.changerCouleur(cout, "");
	cout << trait << endl;

	shared_ptr vilainHero = make_shared<VilainHeros>(vecteurVilains[0], vecteurHeros[2]);
	vecteurPersonnages.push_back(vilainHero);

	cout << "Liste des personnages de tous les types: \n" << endl;
	for (auto&& personnage : vecteurPersonnages) {
		shared_ptr<VilainHeros> vilainHeros = dynamic_pointer_cast<VilainHeros>(personnage);
		shared_ptr<Heros> heros = dynamic_pointer_cast<Heros>(personnage);
		shared_ptr<Vilain> vilain = dynamic_pointer_cast<Vilain>(personnage);
		if (vilainHeros)
			vilainHeros->changerCouleur(cout, "Vert");
		else if (heros)
			heros->changerCouleur(cout, "Bleu");
		else if (vilain)
			vilain->changerCouleur(cout, "Rouge");
		personnage->afficher(cout);
		personnage->changerCouleur(cout, "");
		cout << trait << endl;
	}
}