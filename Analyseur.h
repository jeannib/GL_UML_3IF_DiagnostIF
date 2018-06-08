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

	virtual ~Analyseur();
	
	void chargerBD(ifstream& ficRef, ifstream& ficConfig);
	// Description :
	// Charge la configuration dans la map "config"
	// Puis crée les maladies grace aux empreintes présentes dans le fichier de reference
	
	void afficherMaladies(bool caracs);
	// Description :
	// Si caracs = false affiche la liste des maladies
	// Si carac = true affiche la liste des maladies et leurs caractéristiques
	
	void afficherHistorique();
	// Description :
	// Affiche l'historique de l'utilisateur courant
	
	Maladie* findMaladie(string mal);
	// Description :
	// Recherche une maladie dans la liste de maladies
	
	void depistageGeneral(Empreinte emp);
	// Description :
	// Lance un depistage de chaque maladie pour l'empreinte emp
	
	void depistageSpecifique(Empreinte emp, Maladie m);
	// Description :
	// Lance un depistage de la maladie m pour l'empreinte emp
	
	unordered_map<string,string> getConfig();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	vector<Maladie> maladies;
	unordered_map<string, string> config;

};

//-------------------------------- Autres définitions dépendantes de <Analyseur>

#endif // ANALYSEUR_H
