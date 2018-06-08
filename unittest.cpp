#include <iostream>
#include <fstream>
#include "math.h"
#include "Empreinte.h"
#include "EmpreinteReference.h"
#include "Analyseur.h"
int wins=0;
int tot=0;
Analyseur analyseur;
string USER;

void testChargerEmpreinte(){
	tot++;
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
		cout << "testChargerEmpreinte" << endl;
		wins++;
	}
}

void testChargerEmpreinteReference(){
	tot++;
	string attributs = "NoID;A1;A2;Disease";
	string valeurs = "1;True;2.12;M1";
	EmpreinteReference empreinte(attributs,valeurs,analyseur.getConfig());
	if(empreinte.getID() != 1){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : 1" << endl << "	Valeur obtenue : " << empreinte.getID() << endl<<"\033[0m";
	}else if(empreinte.getAttrDouble()["A2"] != 2.12){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : 2.12" << endl << "	Valeur obtenue : " << empreinte.getAttrDouble()["A2"] << endl<<"\033[0m";
	}else if(empreinte.getAttrString()["A1"] != "True"){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : True" << endl << "	Valeur obtenue : " << empreinte.getAttrDouble()["A1"] << endl<<"\033[0m";
	}else if(empreinte.getMaladie() != "M1"){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : M1" << endl << "	Valeur obtenue : " << empreinte.getMaladie() << endl<<"\033[0m";
	}else{
		cout << "testChargerEmpreinteReference" << endl;
		wins++;
	}
}

void testFindMaladieExistante(){
	tot++;
	Maladie m = *analyseur.findMaladie("M1");
	if(m.getNom() != "M1"){
		cerr << "\033[31m"<< "-- Erreur testFindMaladieExistante" << endl << "	Valeur attendue : M1" << endl << "	Valeur obtenue : " << m.getNom() << endl<<"\033[0m";
	}else{
		cout << "testFindMaladieExistante" << endl;
		wins++;
	}
}

void testFindMaladieInexistante(){
	tot++;
	if(analyseur.findMaladie("B")!=nullptr)
	{
		cerr << "\033[31m"<< "-- Erreur testFindMaladieInexistante" << endl << "	Valeur attendue : nullptr" << endl << "	Valeur obtenue : " << analyseur.findMaladie("B")<< endl<<"\033[0m";
	}else{
		cout << "testFindMaladieInexistante" << endl;
		wins++;
	}
}

void testChargerBD(){
	tot++;
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
		cout << "testChargerBD" << endl;
		wins++;
	}
}

void testAnalyserEmpreinteMalade(){
	tot++;
	string attributs = "NoID;A1;A2;";
	string valeurs = "1;True;2.12";
	Empreinte empreinte(attributs,valeurs,analyseur.getConfig());
	Maladie m = *analyseur.findMaladie("M1");
	if(int(m.analyserEmpreinte(empreinte)) < 50){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : > 50" << endl << "	Valeur obtenue : " << m.analyserEmpreinte(empreinte) << endl<<"\033[0m";
	}else{
		cout << "testAnalyserEmpreinteMalade" << endl;
		wins++;
	}
}

void testAnalyserEmpreintePasMalade(){
	tot++;
	string attributs = "NoID;A1;A2;";
	string valeurs = "1;False;15";
	Empreinte empreinte(attributs,valeurs,analyseur.getConfig());
	Maladie m = *analyseur.findMaladie("M1");
	if(int(m.analyserEmpreinte(empreinte)) > 50){
		cerr << "\033[31m"<< "-- Erreur testChargerEmpreinte" << endl << "	Valeur attendue : < 40" << endl << "	Valeur obtenue : " << m.analyserEmpreinte(empreinte) << endl<<"\033[0m";
	}else{
		cout << "testAnalyserEmpreintePasMalade" << endl;
		wins++;
	}
}

void testChargerMaladieNonFinalise(){
	tot++;
	Maladie m("M1");
	string attributs = "NoID;A1;A2;Disease";
	string valeurs = "1;True;2.12;M1";
	EmpreinteReference empreinte(attributs,valeurs,analyseur.getConfig());
	m.ajouterEmpreinte(empreinte);
	if(m.getCaracsDouble()["A2"].first != 2.12){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 2.12" << endl << "	Valeur obtenue : " << m.getCaracsDouble()["A2"].first << endl<<"\033[0m";
	}else if(m.getCaracsDouble()["A2"].second != pow(2.12,2)){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 4.4944" << endl << "	Valeur obtenue : " << m.getCaracsDouble()["A2"].second << endl<<"\033[0m";
	}else if(m.getCaracsString()["A1"]["True"] != 1){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 1" << endl << "	Valeur obtenue : " << m.getCaracsString()["A1"]["True"] << endl<<"\033[0m";
	}else{
		cout << "testChargerMaladieNonFinalise" << endl;
		wins++;
	}
}

void testChargerMaladieFinalise(){
	tot++;
	Maladie m("M1");
	string attributs = "NoID;A1;A2;Disease";
	string valeurs1 = "1;True;2;M1";
	EmpreinteReference empreinte1(attributs,valeurs1,analyseur.getConfig());
	m.ajouterEmpreinte(empreinte1);
	string valeurs2 = "1;False;4;M1";
	EmpreinteReference empreinte2(attributs,valeurs2,analyseur.getConfig());
	m.ajouterEmpreinte(empreinte2);
	m.finaliser();
	if(m.getCaracsDouble()["A2"].first != 3){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 3" << endl << "	Valeur obtenue : " << m.getCaracsDouble()["A2"].first << endl<<"\033[0m";
	}else if(m.getCaracsDouble()["A2"].second != 1){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 0" << endl << "	Valeur obtenue : " << m.getCaracsDouble()["A2"].second << endl<<"\033[0m";
	}else if(m.getCaracsString()["A1"]["True"] != 0.5){
		cerr << "\033[31m"<< "-- Erreur testChargerMaladie" << endl << "	Valeur attendue : 0.5" << endl << "	Valeur obtenue : " << m.getCaracsString()["A1"]["True"] << endl<<"\033[0m";
	}else{
		cout << "testChargerMaladieFinalise" << endl;
		wins++;
	}
}

int main()
{
	testChargerBD();
	testChargerEmpreinte();
	testChargerEmpreinteReference();
	testAnalyserEmpreinteMalade();
	testAnalyserEmpreintePasMalade();
	testChargerMaladieNonFinalise();
	testChargerMaladieFinalise();
	testFindMaladieExistante();
    testFindMaladieInexistante();
	if(wins==tot){
		cout << endl << "\033[32m"<< "Tests reussis : " << wins << "/" << tot << endl << "\033[0m";
	}else{
		cout << endl << "\033[31m"<< "Tests reussis : " << wins << "/" << tot << endl << "\033[0m";
	}
}
