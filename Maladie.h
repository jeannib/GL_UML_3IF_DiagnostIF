/*************************************************************************
Maladie  -  description
-------------------
d�but                : 04/05/2018
copyright            : (C) 2018 par COLONGES Vincent
e-mail               : vincent.colonges@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <string>
#include <unordered_map>
#include "EmpreinteReference.h"
#include "EmpreintePatient.h"
#include <math.h>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Maladie>
// 
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(string nom);

	virtual ~Maladie();
	
	string getNom() const;

	unordered_map<string, pair<double,double>> getCaracsDouble();
	
	unordered_map<string, unordered_map<string, double>> getCaracsString();
	
	void displayCaracs() const;
	
	void ajouterEmpreinte(EmpreinteReference empreinte);
	
	void finaliser();
	
	double analyserEmpreinte(EmpreintePatient emp);
	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	string nom;
	unordered_map<string, pair<double,double>> histoDoubleRef;
	unordered_map<string, unordered_map<string, double>> histoStringRef;
	int nbEmpreintes = 0;
	int nbAttributs = 0;

};

//-------------------------------- Autres d�finitions d�pendantes de <Maladie>

#endif // MALADIE_H
