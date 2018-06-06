/*************************************************************************
Empreinte  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Empreinte.h"

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte(string attributs, string valeurs, unordered_map<string,string> config)
{

	do{
		string key = attributs.substr(0,attributs.find_first_of(';'));
		string value = valeurs.substr(0,valeurs.find_first_of(';'));
		
		attributs.erase(0,attributs.find_first_of(';')+1);
		valeurs.erase(0,valeurs.find_first_of(';')+1);
		
		if(config[key] == "string"){
			attrString[key] = value;
		}else if(config[key] == "double"){
			attrDouble[key] = atof(value.c_str());
		}
		
	}while(attributs.find_first_of(';') != string::npos);
	
} //----- Fin de Empreinte

unordered_map<string, double> Empreinte::getAttrDouble(){
	return this->attrDouble;
}

unordered_map<string, string> Empreinte::getAttrString(){
	return this->attrString;
}


Empreinte::~Empreinte()
{

} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
