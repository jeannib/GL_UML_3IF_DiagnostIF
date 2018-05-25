/*************************************************************************
EmpreintePatient  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EmpreintePatient> (fichier EmpreintePatient.h) ----------------
#if ! defined ( EMPREINTEPATIENT_H )
#define EMPREINTEPATIENT_H

//--------------------------------------------------- Interfaces utilis�es
#include <unordered_map>
#include <string>
#include "Empreinte.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <EmpreintePatient>
// 
//------------------------------------------------------------------------

class EmpreintePatient : public Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	EmpreintePatient(string attributs, string valeurs, unordered_map<string,string> config);

	virtual ~EmpreintePatient();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	unordered_map<string, double> maladiesPossibles;
};

//-------------------------------- Autres d�finitions d�pendantes de <EmpreintePatient>

#endif // EMPREINTEPATIENT_H
