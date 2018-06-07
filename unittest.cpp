#include <iostream>
#include <fstream>
#include "Empreinte.h"
#include "EmpreintePatient.h"
#include "EmpreinteReference.h"
#include "Analyseur.h"
int wins=0;
int tot=0;
Analyseur analyseur;
string USER;

void testChargerEmpreinte(){
	tot++;
	cout << "testChargerEmpreinte" << endl;
	string attributs = "NoID;A1;A2;";
	string valeurs = "1;True;2.12";
	Empreinte empreinte(attributs,valeurs,analyseur.getConfig());
	if(empreinte.getID() != 1){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : 1" << endl << "	Valeur obtenue : " << empreinte.getID() << endl<<"\033[0m";
	}else if(empreinte.getAttrDouble()["A2"] != 2.12){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : 2.12" << endl << "	Valeur obtenue : " << empreinte.getAttrDouble()["A2"] << endl<<"\033[0m";
	}else if(empreinte.getAttrString()["A1"] != "True"){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : True" << endl << "	Valeur obtenue : " << empreinte.getAttrDouble()["A1"] << endl<<"\033[0m";
	}else{
		wins++;
	}
}

void testChargerEmpreinteReference(){
	tot++;
	cout << "testChargerEmpreinteReference" << endl;
	//TODO
}

void testFindMaladie(){
	tot++;
	cout << "testFindMaladie" << endl;
	//TODO
}

void testChargerBD(){
	tot++;
	cout << "testChargerBD" << endl;
	ifstream config;
	config.open("tests/conf");
	ifstream refs;
	refs.open("tests/refs");
	analyseur.chargerBD(refs,config);
	
	if(analyseur.getConfig()["A1"] != "string"){
		cerr << "\033[31m"<< "-- Erreur testChargerBD" << endl << "	Valeur attendue : string" << endl << "	Valeur obtenue : " << analyseur.getConfig()["A1"] << endl<<"\033[0m";
	}else if(analyseur.getConfig()["A2"] != "double"){
		cerr << "\033[31m"<< "-- Erreur testChargerBD" << endl << "	Valeur attendue : double" << endl << "	Valeur obtenue : " << analyseur.getConfig()["A2"] << endl<<"\033[0m";
	}else if(analyseur.getConfig()["NoID"] != "ID"){
		cerr << "\033[31m" << "-- Erreur testChargerBD" << endl << "	Valeur attendue : ID" << endl << "	Valeur obtenue : " << analyseur.getConfig()["NoID"] << endl <<"\033[0m";	
	}else{
		wins++;
	}
}

void testAnalyserEmpreinteMalade(){
	tot++;
	cout << "testAnalyserEmpreinteMalade" << endl;
	string attributs = "NoID;A1;A2;";
	string valeurs = "1;True;2.12";
	EmpreintePatient empreinte(attributs,valeurs,analyseur.getConfig());
	Maladie m = *analyseur.findMaladie("M1");
	if(int(m.analyserEmpreinte(empreinte)) < 50){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : > 50" << endl << "	Valeur obtenue : " << m.analyserEmpreinte(empreinte) << endl<<"\033[0m";
	}else{
		wins++;
	}
}

void testAnalyserEmpreintePasMalade(){
	tot++;
	cout << "testAnalyserEmpreintePasMalade" << endl;
	string attributs = "NoID;A1;A2;";
	string valeurs = "1;False;15";
	EmpreintePatient empreinte(attributs,valeurs,analyseur.getConfig());
	Maladie m = *analyseur.findMaladie("M1");
	if(int(m.analyserEmpreinte(empreinte)) > 50){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : < 40" << endl << "	Valeur obtenue : " << m.analyserEmpreinte(empreinte) << endl<<"\033[0m";
	}else{
		wins++;
	}
}

void testChargerMaladie(){
	tot++;
	cout << "testChargerMaladie" << endl;
	//TODO
}

int main()
{
	testChargerBD();
	testChargerEmpreinte();
	testChargerEmpreinteReference();
	testAnalyserEmpreinteMalade();
	testAnalyserEmpreintePasMalade();
	testChargerMaladie();
	cout << endl << "\033[32m"<< "Tests reussis : " << wins << "/" << tot << endl << "\033[0m";
}
