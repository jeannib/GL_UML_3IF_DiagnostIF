<<<<<<< HEAD
// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void menu();

int main()
{
	/*ifstream ficConfig("config.txt");
=======
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void menu();

int main()
{
	/*ifstream ficConfig("config.txt");
>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
	string line;
	while (getline(ficConfig, line)) {
		string noid = line.substr(0, line.find_first_of(';'));
		cout << noid << endl;
<<<<<<< HEAD
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
	
	
	cout << "fin";
	int test;
	cin >> test;
    return 0;
}

void menu() {
	int choix;
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
			break;
		case 2:
			break;
		}
	} while (choix != 6);
}

=======
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
	
	
	cout << "fin";
	int test;
	cin >> test;
    return 0;
}

void menu() {
	int choix;
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
			break;
		case 2:
			break;
		}
	} while (choix != 6);
}

>>>>>>> a5bd894fe8e3c6bc2f55a2947aef60f4e44e1b54
