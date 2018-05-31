/*************************************************************************
Analyseur  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Analyseur> (fichier Analyseur.h) ----------------
#if ! defined ( ANALYSEUR_H )
#define ANALYSEUR_H

//--------------------------------------------------- Interfaces utilisées
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

struct set_compare{
	bool operator()(const Maladie& a,const Maladie& b) const{
		return a.getNom() < b.getNom();
	}
};

//------------------------------------------------------------------------
// Rôle de la classe <Analyseur>
// 
//------------------------------------------------------------------------

class Analyseur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	Analyseur();
	
	Analyseur(ifstream ficRef, ifstream ficConfig);

	virtual ~Analyseur();
	
	void chargerBD(ifstream& ficRef, ifstream& ficConfig);

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	set<Maladie,set_compare> maladies;
	unordered_map<string, string> config;
	int test;

};

//-------------------------------- Autres définitions dépendantes de <Analyseur>

#endif // ANALYSEUR_H
