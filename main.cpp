#include <iostream>
#include <string>
#include <fstream>
#include "Analyseur.h"

using namespace std;

void menu();

int main()
{
	/*ifstream ficConfig("config.txt");
	string line;
	while (getline(ficConfig, line)) {
		string noid = line.substr(0, line.find_first_of(';'));
		cout << noid << endl;
	}*/

	string id, mdp;
	cout << "Identifiant  :" << endl;
	cin >> id;
	ifstream user("users/" + id);
	if (user.is_open())
	{
		cout << "Mot de passe :" << endl;
		cin >> mdp;
		string line;
		getline(user, line);
		if(line == mdp)
		{
			cout << "Connecte" << endl;
			menu();
		}
		else
		{
			cout << "Mot de passe invalide" << endl;
		}
	}
	else
	{
		cout << "Utilisateur inexistant." << endl;
	}
    return 0;
}

void menu() {
	int choix;
	Analyseur analyseur;
	do {
		cout << "1 -  Charger un fichier de référence" << endl;
		cout << "2 -  Dépistage général d'empreinte(s)" << endl;
		cout << "3 -  Dépistage spécifique d'empreinte(s)" << endl;
		cout << "4 -  Afficher la liste des maladies" << endl;
		cout << "5 -  Afficher l'historique" << endl;
		cout << "6 -  Se déconnecter" << endl;
		cin >> choix;
		switch (choix) {
		case 1 :
		{
			string strRef;
			string strConf;
			cout << "Fichier de référence" << endl;
			cin >> strRef;
			ifstream ficRef(strRef);
			if (ficRef.is_open())
			{
				cout << "Fichier de configuration" << endl;
				cin >> strConf;
				ifstream ficConf(strConf);
				if (ficConf.is_open())
				{
					analyseur.chargerBD(ficRef, ficConf);
				}
			}
		}
			break;
		case 2:
			cout << "2" << endl;
			break;
		}
	} while (choix != 6);
}

