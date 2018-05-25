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
	EmpreinteReference(string attributs, string valeurs);

	virtual ~EmpreinteReference();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string maladie;
};

//-------------------------------- Autres définitions dépendantes de <EmpreinteReference>

#endif // EMPREINTEREFERENCE_H