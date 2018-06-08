#include <iostream>
#include <string>
#include <fstream>
#include "Analyseur.h"
#include <algorithm>

using namespace std;

string USER=""; 

char esc_char = 27; // the decimal code for escape character is 27

void menu(Analyseur a);

bool handleCinFails();

void chargerFichierRef(Analyseur * a);

void ajouterAHistorique(int,string action);

int main()
{
	bool connection = false;
	string id, mdp;
	
	

	cout << "\r\nBienvenue sur l'application"<<esc_char << "[1;34m" << " Diagnost'IF !\r\n" << esc_char << "[0m"  << endl;
	
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
    bool fichiersValides=false;
	ifstream ficConf;
	string strRef;
	string strConf;
    
    while(!fichiersValides){
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
                ajouterAHistorique(5, "Fichier reference " + strRef + "\r\nFichier configuration " +strConf );
                analyseur->chargerBD(ficRef, ficConf);
                fichiersValides=true;
            }else{
                cout<< "Fichier de configuration introuvable, veuillez reessayer" <<endl;
            }
        } else {
            cout<< "Fichier de reference introuvable, veuillez reessayer"<<endl;
        }
    }
}

void ajouterAHistorique(int action, string info){
    string actionS;
    ofstream historic("historic/"+USER , ios::out | ios::app);
	historic << esc_char << "[1;34m";
    
    switch(action){
        case 1 :
            actionS= "Depistage General\r\nEmpreinte " +info+"\r\n" ;
            break;
        case 2 :
            actionS= "Depistage Specifique\r\n" +info+"\r\n" ;
            break;
        case 3 :
            actionS= "Affichage des maladies\r\n" ;
            break;
         case 4 :
            actionS= "Affichage historique\r\n" ;
            break;
        case 5 :
            actionS= "Chargement d'un fichier de reference\r\n" +info+"\r\n" ;
            break;
       
            
    }
    
	historic << actionS << esc_char << "[0m" << "\r\n";
	historic.close();
}


void menu(Analyseur a) {
	int choix=0;
	
	Analyseur analyseur = a;
	cout << "\r\nVous utilisez le logiciel " << esc_char << "[1;34m" << " Diagnost'IF !" << esc_char << "[0m" 
    <<"\r\n\r\nSelectionnez l'action que vous souhaitez effectuer puis tapez sur entree pour valider votre choix!"<<endl;
    
	do {

		cout << "\r\n1 -  Depistage general d'empreinte(s)" << endl;
		cout << "2 -  Depistage specifique d'empreinte(s)" << endl;
		cout << "3 -  Afficher la liste des maladies" << endl;
		cout << "4 -  Afficher l'historique" << endl;
		cout << "5 -  Charger un fichier de reference" << endl;
		cout << "6 -  Se deconnecter" << endl;
		
		while(choix<1 || choix>6)
		{
			do{
				cin >> choix;
			}while(handleCinFails());
			if(choix<1 || choix>6) 
			{
				cout<<"Entrez une valeur entre 1 et 6 !"<<endl;
			}
		}
		
		cout << endl;
		
		switch (choix) {
		
		case 1:
			{
			string emp;
			cout << "Empreinte a analyser" <<endl;
			cin>> emp;
			ifstream ficEmp(emp);
			if(ficEmp.is_open())
			{
				ajouterAHistorique(1, emp);	
                string line, attr;
                getline(ficEmp, attr);
                while(getline(ficEmp, line)){
                    Empreinte empreinte(attr, line, analyseur.getConfig());
                    analyseur.depistageGeneral(empreinte);
                    cout<<"\r\n"<<endl;
                }
					
			}else{
				cout<< "Empreinte introuvable\r\n"<<endl;
			}
		}
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
                cout<<"Voici la liste des maladies prises en compte :\r\n";
                analyseur.afficherMaladies(false);
				cout << "Maladie a analyser" <<endl;
				cin>> mal;
				if(analyseur.findMaladie(mal) != nullptr){
					Maladie m = *analyseur.findMaladie(mal);
                    ajouterAHistorique(2,"Empreinte "+emp+"\r\nMaladie " + mal);
                    
					string line, attr;
					getline(ficEmp, attr);
					while(getline(ficEmp, line)){
						Empreinte empreinte(attr, line, analyseur.getConfig());
						analyseur.depistageSpecifique(empreinte, m);
					}
				}else{
					cout << "Maladie introuvable dans nos donnees\r\n" << endl;
				}
			}else{
				cout<< "Empreinte introuvable\r\n"<<endl;
			}
		}
			break;
			
		case 3:
			analyseur.afficherMaladies(true);
            ajouterAHistorique(3, "");
			break;
        case 4 :
            analyseur.afficherHistorique();
            ajouterAHistorique(4,"");
            break;
		case 5 :
			chargerFichierRef(&analyseur);
			break;
		default :
			break;
		}
		if(choix!=6){
			choix=0;
		}
	} while (choix != 6);
	
}


