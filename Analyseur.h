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
#include <unordered_map>
#include <fstream>
#include "Maladie.h"
#include "stdafx.h"
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
	Analyseur(ifstream ficRef, ifstream ficConfig);

	virtual ~Analyseur();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	set<Maladie> maladies;
	unordered_map<string, string> config;

};

//-------------------------------- Autres d�finitions d�pendantes de <Analyseur>

#endif // ANALYSEUR_H
