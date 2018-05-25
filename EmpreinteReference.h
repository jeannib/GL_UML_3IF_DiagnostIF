/*************************************************************************
EmpreinteReference  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EmpreinteReference> (fichier EmpreinteReference.h) ----------------
#if ! defined ( EMPREINTEREFERENCE_H )
#define EMPREINTEREFERENCE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include "Empreinte.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <EmpreinteReference>
// 
//------------------------------------------------------------------------

class EmpreinteReference : public Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	EmpreinteReference(string attributs, string valeurs);

	virtual ~EmpreinteReference();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	string maladie;
};

//-------------------------------- Autres d�finitions d�pendantes de <EmpreinteReference>

#endif // EMPREINTEREFERENCE_H