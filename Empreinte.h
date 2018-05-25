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
<<<<<<< HEAD
=======

>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
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
	Empreinte(string attributs, string valeurs);

	virtual ~Empreinte();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	unordered_map<string, double> attrDouble;
	unordered_map<string, string> attrString;

};

//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

<<<<<<< HEAD
=======
#endif // EMPREINTE_H
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
