#include <iostream>
#include <string>
using namespace std;


class Affichable
{
public:
	virtual void afficher(ostream& sortie) = 0;
	virtual void changerCouleur(const string& couleur) = 0;
	friend ostream& operator<< (ostream& o, const Affichable& affichage);
	virtual ~Affichable() {};
private:
	ostream& sortie_;
	string& couleur_;
};