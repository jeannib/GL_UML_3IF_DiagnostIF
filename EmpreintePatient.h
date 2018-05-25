/*************************************************************************
EmpreintePatient  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EmpreintePatient> (fichier EmpreintePatient.h) ----------------
#if ! defined ( EMPREINTEPATIENT_H )
#define EMPREINTEPATIENT_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
#include "Empreinte.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmpreintePatient>
// 
//------------------------------------------------------------------------

class EmpreintePatient : public Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	EmpreintePatient(string attributs, string valeurs, unordered_map<string,string> config);

	virtual ~EmpreintePatient();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	unordered_map<string, double> maladiesPossibles;
};

//-------------------------------- Autres définitions dépendantes de <EmpreintePatient>

#endif // EMPREINTEPATIENT_H
