/*************************************************************************
Maladie  -  description
-------------------
début                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "Maladie.h"

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


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

void Maladie::displayCaracs() const
{
	if(this->getNom() == ""){
		cout << "Personne saine" << endl;
	}else{
		cout << this->getNom() << endl;
		cout << this->getNom().length() << endl;
	}
	
	
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

void Maladie::ajouterEmpreinte(EmpreinteReference empreinte)
{
	for(auto attrDouble : empreinte.getAttrDouble()){
		pair<double,double> paire(histoDoubleRef[attrDouble.first].first+attrDouble.second,histoDoubleRef[attrDouble.first].second+attrDouble.second*attrDouble.second);
		this->histoDoubleRef[attrDouble.first] = paire;
		//nbAttributs++;
	}
	
	for(auto attrString : empreinte.getAttrString()){
		this->histoStringRef[attrString.first][attrString.second]+=1;
		//nbAttributs++;
	}
	
	this->nbEmpreintes++;
}

void Maladie::finaliser()
{
	for (unordered_map<string,pair<double,double>>::iterator it=this->histoDoubleRef.begin(); it!=this->histoDoubleRef.end(); ++it){
		it->second.first/=this->nbEmpreintes;
		it->second.second=sqrt(it->second.second/this->nbEmpreintes - pow(it->second.first,2));
	}
	
	for (unordered_map<string,unordered_map<string,double>>::iterator it=this->histoStringRef.begin(); it!=this->histoStringRef.end(); ++it){
		for (unordered_map<string,double>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2){
			it2->second/=nbEmpreintes;
		}
	}
}


double Maladie::analyserEmpreinte(EmpreintePatient emp)
{
	double risque=0, somme=0, square=0, puissance=0, ratio=0;
	for (unordered_map<string,pair<double,double>>::iterator it=this->histoDoubleRef.begin(); it!=this->histoDoubleRef.end(); ++it){
		puissance=pow(emp.getAttrDouble()[it->first] - it->second.first,2);
		
		square=sqrt(puissance);
		ratio=square/(3*it->second.second);
		if(ratio>1){
			somme-= abs(1-ratio);
		}
		else{
			somme+= 1-ratio;
		}
		
	
	}
	
	for (unordered_map<string,unordered_map<string,double>>::iterator it=this->histoStringRef.begin(); it!=this->histoStringRef.end(); ++it){
		string value = emp.getAttrString()[it->first];
		for (unordered_map<string,double>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2){
			if(value==it2->first){
				somme+=it2->second;
				break;
			}
		}
	}
	
	nbAttributs = histoDoubleRef.size() + histoStringRef.size();
	risque = (somme>0 ? (somme/ nbAttributs) * 100.0 : 0);
	
	return risque;
}

Maladie::~Maladie()
{

} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
