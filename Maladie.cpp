/*************************************************************************
Maladie  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Maladie.h"
<<<<<<< HEAD
=======
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

unordered_map<string, pair<double, double>> Maladie::getCaracsDouble()
{
	return histoDoubleRef;
}

unordered_map<string, unordered_map<string, double>> Maladie::getCaracsString()
{
	return histoStringRef;
}

//-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(string nom)
{
	this->nom = nom;

} //----- Fin de Maladie


Maladie::~Maladie()
{

} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

<<<<<<< HEAD
=======
  //----------------------------------------------------- M�thodes prot�g�es
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
