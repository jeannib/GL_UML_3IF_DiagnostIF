/*************************************************************************
Analyseur  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Analyseur> (fichier Analyseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Analyseur.h"
<<<<<<< HEAD
=======
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


//-------------------------------------------- Constructeurs - destructeur
Analyseur::Analyseur(ifstream ficRef, ifstream ficConfig)
{
	// Chargement de la configuration
	string line;
	while (getline(ficConfig, line)) {
		string noid = line.substr(0, line.find_first_of(';'));
	}

} //----- Fin de Analyseur


Analyseur::~Analyseur()
{
	maladies.clear();
	config.clear();

} //----- Fin de ~Analyseur


  //------------------------------------------------------------------ PRIVE

<<<<<<< HEAD
=======
  //----------------------------------------------------- M�thodes prot�g�es
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
