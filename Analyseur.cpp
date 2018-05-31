/*************************************************************************
Analyseur  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analyseur> (fichier Analyseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Analyseur.h"

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Analyseur::Analyseur()
{

} //----- Fin de Analyseur

Analyseur::Analyseur(ifstream ficRef, ifstream ficConfig)
{
	// Chargement de la configuration
	
} //----- Fin de Analyseur


Analyseur::~Analyseur()
{
	maladies.clear();
	config.clear();

} //----- Fin de ~Analyseur

void Analyseur::chargerBD(ifstream& ficRef, ifstream& ficConfig)
{
	//-- Configuration
	string line;
	getline(ficConfig, line); //skip 1st line
	while (getline(ficConfig, line)) {
		string key = line.substr(0, line.find_first_of(';'));
		string value = line.substr(line.find_first_of(';')+1);
		config[key] = value;
	}
	//---
	
	//-- Maladies
	vector<EmpreinteReference> empreintes;
	getline(ficRef, line);
	string attributs = line;
	while (getline(ficRef, line)) {
		EmpreinteReference empreinte(attributs,line,this->config); 
		empreintes.push_back(empreinte);
	}
	for(EmpreinteReference emp : empreintes){
		//Maladie* m = new Maladie(emp.getMaladie());
		Maladie m(emp.getMaladie());
		this->maladies.insert(m);
	}
	
	for(Maladie m : this->maladies){
		for(EmpreinteReference emp : empreintes){
				if(strcmp(m.getNom().c_str(),emp.getMaladie().c_str())==0){
					cout << m.getNom() << endl;
					m.ajouterEmpreinte(emp);
				}
		}
		
	}
	//---
	
	
	
	/*for(auto elem : config)
	{
	   cout << elem.first << " : " << elem.second << "\n";
	}*/
}


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
