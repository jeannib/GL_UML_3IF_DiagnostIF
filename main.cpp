#include <iostream>
#include <string>
#include <fstream>
#include "Analyseur.h"
#include <sstream>

using namespace std;

void menu();

int main()
{
	bool connection = false;
	string id, mdp;
	cout << "Bienvenue sur l'application Diagnost'IF !" << endl;
	
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
				cout << "Connecte avec succes" << endl;
				menu();
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

int getInt()
{
    int x=0;
    bool loop=true;
    while(loop)
    {
        std::string s;
        std::getline(std::cin, s);

        std::stringstream stream(s);
        if(stream >> x)
        {
            loop=false;
            continue;
        }
        std::cout << "Invalid!" << std::endl;
    }
    return x;
}

void menu() {
	int choix;
	Analyseur analyseur;
	ifstream ficConf;
	do {
		cout << "1 -  Charger un fichier de référence" << endl;
		cout << "2 -  Dépistage général d'empreinte(s)" << endl;
		cout << "3 -  Dépistage spécifique d'empreinte(s)" << endl;
		cout << "4 -  Afficher la liste des maladies" << endl;
		cout << "5 -  Afficher l'historique" << endl;
		cout << "6 -  Se déconnecter" << endl;
		choix = getInt();
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
				ficConf.open(strConf);
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
		case 3:
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
					
					//m.displayCaracs();
					//analyseur.depistageSpecifique(empreinte, m);
				}else{
					cout << "Maladie introuvable dans nos données" << endl;
				}
			}
			
		}
			break;
			
		case 4:
			analyseur.afficherMaladies();
			break;
		case 6 :
			break;
		default : 
			cout<<"Entrez une valeur entre 1 et 6 !"<<endl;
            break;
		}
	} while (choix != 6);
}


