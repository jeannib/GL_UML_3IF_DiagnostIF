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

	virtual ~Analyseur();
	
	void chargerBD(ifstream& ficRef, ifstream& ficConfig);
	// Description :
	// Charge la configuration dans la map "config"
	// Puis cr�e les maladies grace aux empreintes pr�sentes dans le fichier de reference
	
	void afficherMaladies(bool caracs);
	// Description :
	// Si caracs = false affiche la liste des maladies
	// Si carac = true affiche la liste des maladies et leurs caract�ristiques
	
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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	vector<Maladie> maladies;
	unordered_map<string, string> config;

};

//-------------------------------- Autres d�finitions d�pendantes de <Analyseur>

#endif // ANALYSEUR_H
