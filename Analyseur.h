/*************************************************************************
Analyseur  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Analyseur> (fichier Analyseur.h) ----------------
#if ! defined ( ANALYSEUR_H )
#define ANALYSEUR_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "Maladie.h"
#include "Empreinte.h"
#include "EmpreinteReference.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Analyseur>
// 
//------------------------------------------------------------------------

class Analyseur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	Analyseur();
	
	Analyseur(ifstream ficRef, ifstream ficConfig);

	virtual ~Analyseur();
	
	void chargerBD(ifstream& ficRef, ifstream& ficConfig);
	
	void afficherMaladies(bool caracs);
	
	void afficherHistorique();
	
	Maladie* findMaladie(string mal);
	
	void depistageGeneral(Empreinte emp);
	
	void depistageSpecifique(Empreinte emp, Maladie m);
	
	unordered_map<string,string> getConfig();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	vector<Maladie> maladies;
	unordered_map<string, string> config;

};

//-------------------------------- Autres d�finitions d�pendantes de <Analyseur>

#endif // ANALYSEUR_H
