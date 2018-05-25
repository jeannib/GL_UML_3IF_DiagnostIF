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
<<<<<<< HEAD
=======

>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
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
	EmpreintePatient(string attributs, string valeurs);

	virtual ~EmpreintePatient();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	unordered_map<string, double> maladiesPossibles;
};

//-------------------------------- Autres d�finitions d�pendantes de <EmpreintePatient>

<<<<<<< HEAD
=======
#endif // EMPREINTEPATIENT_H
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
