#include <iostream>
#include <string>
#include <fstream>
#include "Analyseur.h"
#include <algorithm>

using namespace std;

string USER=""; 

void menu(Analyseur a);

bool handleCinFails();

void chargerFichierRef(Analyseur * a);

int main()
{
	bool connection = false;
	string id, mdp;
	
	char esc_char = 27; // the decimal code for escape character is 27

	cout << "\r\nBienvenue sur l'application"<<esc_char << "[1;31m" << " Diagnost'IF !\r\n" << esc_char << "[0m"  << endl;
	
	while(connection!=true){
		cout << "Identifiant" << endl;
		cin >> id;
		ifstream user("users/" + id);
		if (user.is_open())
		{
			cout << "Mot de passe" << endl;
			cin >> mdp;
			string line;
			getline(user, line);
			if(line == mdp)
			{
				connection=true;
				cout << "Connecte avec succes\r\n" << endl;
				USER = id;
				Analyseur analyseur;
				chargerFichierRef(&analyseur);
				menu(analyseur);
			}
			else
			{
				cout << "Connexion echouee (mot de passe invalide), veuillez reessayer" << endl;
			}
		}
		else
		{
			cout << "Connexion echouee (identifiant non reconnu), veuillez reessayer" << endl;
		}
	}
	return 0;
}

bool handleCinFails()
// Algorithme :
// Si on cin autre chose qu'un int, gère l'erreur pour eviter une boucle infinie
{
    if(cin.fail()){
        cout << "Entrez un nombre !\r\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
} //----- Fin de HandleCinFails

void chargerFichierRef(Analyseur * analyseur)
{
	ifstream ficConf;
	string strRef;
	string strConf;
	cout << "Fichier de reference" << endl;
	cin >> strRef;
	ifstream ficRef(strRef);
	if (ficRef.is_open())
	{
		cout << "Fichier de configuration" << endl;
		cin >> strConf;
		ficConf.open(strConf);
		if (ficConf.is_open())
		{
			analyseur->chargerBD(ficRef, ficConf);
		}
	}
}
void menu(Analyseur a) {
	int choix=0;
	
	Analyseur analyseur = a;
	cout << "\r\nVous utilisez le logiciel Diagnost'IF \r\n\r\nSelectionnez l'action que vous souhaitez effectuer puis tapez sur entree pour valider votre choix!"<<endl;
	do {

		cout << "\r\n1 -  Depistage general d'empreinte(s)" << endl;
		cout << "2 -  Depistage specifique d'empreinte(s)" << endl;
		cout << "3 -  Afficher la liste des maladies" << endl;
		cout<< "4 -  Afficher les caracteristiques d'une maladie" << endl;
		cout << "5 -  Afficher l'historique" << endl;
		cout << "6 -  Charger un fichier de reference" << endl;
		cout << "7 -  Se deconnecter" << endl;
		
		while(choix<1 || choix>7)
		{
			do{
				cin >> choix;
			}while(handleCinFails());
			if(choix<1 || choix>7) 
			{
				cout<<"Entrez une valeur entre 1 et 7 !"<<endl;
			}
		}
		
		cout << endl;
		
		switch (choix) {
		
		case 1:
			cout << "1" << endl;
			break;
		case 2:
		{
			string emp;
			string mal;
			cout << "Empreinte a analyser" <<endl;
			cin>> emp;
			ifstream ficEmp(emp);
			if(ficEmp.is_open())
			{
				cout << "Maladie a analyser" <<endl;
				cin>> mal;
				if(analyseur.findMaladie(mal) != nullptr){
					Maladie m = *analyseur.findMaladie(mal);
					string line, attr;
					getline(ficEmp, attr);
					while(getline(ficEmp, line)){
						EmpreintePatient empreinte(attr, line, analyseur.getConfig());
						analyseur.depistageSpecifique(empreinte, m);
					}
				}else{
					cout << "Maladie introuvable dans nos donnees" << endl;
				}
			}else{
				cout<< "Empreinte introuvable\r\n"<<endl;
			}
		}
			break;
			
		case 3:
			analyseur.afficherMaladies();
			break;
		case 6 :
			chargerFichierRef(&analyseur);
			break;
		default :
			break;
		}
		if(choix!=7){
			choix=0;
		}
	} while (choix != 7);
	
}


