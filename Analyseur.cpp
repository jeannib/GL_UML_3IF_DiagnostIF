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
	config.clear();

} //----- Fin de ~Analyseur

EmpreintePatient Analyseur::chargerPatient(string line)
{
	
}

void Analyseur::chargerBD(ifstream& ficRef, ifstream& ficConfig)
{
	this->maladies.clear();
	
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
		Maladie m(emp.getMaladie());
		bool exists = false;
		for(vector<Maladie>::iterator it = this->maladies.begin(); it != this->maladies.end(); ++it) {
			if(m.getNom()==it->getNom())
				exists = true;
		}
		if(!exists)
			this->maladies.push_back(m);
		
	}
	
	for(vector<Maladie>::iterator it = this->maladies.begin(); it != this->maladies.end(); ++it) {
		for(EmpreinteReference emp : empreintes){
				if(it->getNom() == emp.getMaladie()){
					it->ajouterEmpreinte(emp);
				}
		}
		it->finaliser();	
	}
	//---
}

void Analyseur::afficherMaladies(){
	for(Maladie m : this->maladies){
		m.displayCaracs();
	}
}

void Analyseur::depistageSpecifique(EmpreintePatient emp, Maladie m){
	double risque = m.analyserEmpreinte(emp);
	cout<<m.getNom()<<" : " <<risque<<"\n";
}

Maladie* Analyseur::findMaladie(string mal)
{
	for(vector<Maladie>::iterator it = this->maladies.begin(); it != this->maladies.end(); ++it) {
		if(it->getNom() == mal)
		{
			return &(*it);
		}
	}
	return nullptr;
}

unordered_map<string, string> Analyseur::getConfig(){
	return this->config;
}


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
