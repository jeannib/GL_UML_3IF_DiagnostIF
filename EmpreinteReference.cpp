/*************************************************************************
EmpreinteReference  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <EmpreinteReference> (fichier EmpreinteReference.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "EmpreinteReference.h"

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


//-------------------------------------------- Constructeurs - destructeur
EmpreinteReference::EmpreinteReference(string attributs, string valeurs, unordered_map<string,string> config) : Empreinte(attributs, valeurs, config)
{
	
	this->maladie = valeurs.substr(valeurs.find_last_of(';')+1,valeurs.length());
} //----- Fin de EmpreinteReference


EmpreinteReference::~EmpreinteReference()
{

} //----- Fin de ~EmpreinteReference


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es
