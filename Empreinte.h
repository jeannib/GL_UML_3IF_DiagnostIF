/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilis�es
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Empreinte>
// 
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(string attributs, string valeurs, unordered_map<string,string> config);
	// Description :
	// Creer une empreinte en creant les map "attrDouble" et "attrString" avec les valeurs fournies en entree
	// grace a la configuration de l'analyseur et les attributs demand�s
	
	unordered_map<string, double> getAttrDouble();
	
	unordered_map<string, string> getAttrString();
	
	int getID();

	virtual ~Empreinte();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	unordered_map<string, double> attrDouble;
	unordered_map<string, string> attrString;
	int id;

};

//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

#endif // EMPREINTE_H
