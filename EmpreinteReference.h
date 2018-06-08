/*************************************************************************
EmpreinteReference  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EmpreinteReference> (fichier EmpreinteReference.h) ----------------
#if ! defined ( EMPREINTEREFERENCE_H )
#define EMPREINTEREFERENCE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Empreinte.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmpreinteReference>
// 
//------------------------------------------------------------------------

class EmpreinteReference : public Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	EmpreinteReference(string attributs, string valeurs, unordered_map<string,string> config);
	// Description :
	// Creer une empreinte en creant les map "attrDouble" et "attrString" avec les valeurs fournies en entree
	// grace a la configuration de l'analyseur et les attributs demandés
	// Ajoute en plus la maladie dont est atteinte l'empreinte
	
	string getMaladie();

	virtual ~EmpreinteReference();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string maladie;
};

//-------------------------------- Autres définitions dépendantes de <EmpreinteReference>

#endif // EMPREINTEREFERENCE_H
