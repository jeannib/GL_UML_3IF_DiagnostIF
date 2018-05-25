/*************************************************************************
Maladie  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <unordered_map>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maladie>
// 
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	unordered_map<string, unordered_map<string, double>> getCaracsString();
	unordered_map<string, pair<double, double>> getCaracsDouble();


	//-------------------------------------------- Constructeurs - destructeur
	Maladie(string nom);

	virtual ~Maladie();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nom;
	unordered_map<string, pair<double, double>> histoDoubleRef;
	unordered_map<string, unordered_map<string, double>> histoStringRef;

};

//-------------------------------- Autres définitions dépendantes de <Maladie>

#endif // MALADIE_H
