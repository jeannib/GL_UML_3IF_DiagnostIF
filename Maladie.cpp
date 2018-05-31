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

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


//-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(string nom)
{
	this->nom = nom;

} //----- Fin de Maladie

string Maladie::getNom() const
{
	return this->nom;
}

unordered_map<string, pair<double,double>> Maladie::getCaracsDouble()
{
	return this->histoDoubleRef;
}

unordered_map<string, unordered_map<string, double>> Maladie::getCaracsString()
{
	return this->histoStringRef;
}

void Maladie::displayCaracs()
{
	for(auto elem : this->histoDoubleRef)
	{
	   cout << "Attribut : " << elem.first << " ; Moyenne : " << elem.second.first << " ; Ecart-type : "<< elem.second.second << "\n";
	}
	for(auto elem : this->histoStringRef)
	{
	   cout << "Attribut : " << elem.first;
	   for(auto newElem : elem.second)
	   {
			cout << "; Valeur : " << newElem.first << "; Frequence : " << newElem.second;
		}
		cout<<"\n";
	}
}

void Maladie::ajouterEmpreinte(EmpreinteReference empreinte){
	for(auto attrDouble : empreinte.getAttrDouble()){
		this->histoDoubleRef[attrDouble.first] = make_pair(attrDouble.second,attrDouble.second*2);
	}
	
	this->displayCaracs();
	//this->histoDoubleRef[
}

Maladie::~Maladie()
{

} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es
