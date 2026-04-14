#include <iostream>
#include <vector>
#include <string>
#include <conio.h> 

using namespace std;


const string RESET = "\033[0m";
const string BG_GREEN = "\033[42m";
const string FG_BLACK = "\033[30m";
const string FG_BLUE = "\033[36m";
const string FG_GRAY = "\033[90m";


int naviguerMenu(const string& titre, const vector<string>& options) {
    int selection = 0;
    int touche = 0;

    while (true) {
        system("cls"); 

    
        cout << FG_BLUE << "+---------------------------------------+" << RESET << endl;
        cout << FG_BLUE << "|       === " << titre << " ===       |" << RESET << endl;
        cout << FG_BLUE << "+---------------------------------------+\n\n" << RESET;

     
        for (size_t i = 0; i < options.size(); ++i) {
            if (i == selection) {
                
                cout << BG_GREEN << FG_BLACK << "  === " << options[i] << " ===  " << RESET << endl << endl;
            } else {
                
                cout << "  [ " << options[i] << " ]  " << endl << endl;
            }
        }

        cout << FG_GRAY << "\n[Fleches Haut/Bas] Naviguer   [Entree] Valider" << RESET << endl;

        
        touche = _getch();
        
        if (touche == 224) { 
            touche = _getch();
            if (touche == 72) { 
                selection = (selection == 0) ? options.size() - 1 : selection - 1;
            } else if (touche == 80) { // Flèche Bas
                selection = (selection == options.size() - 1) ? 0 : selection + 1;
            }
        } else if (touche == 13) { 
            return selection;
        }
    }
}



void menuClient() {
    vector<string> options = {
        "Consulter mon compte", "Historique", "Modifier mot de passe", 
        "Versement", "Virement", "Payer facture", "Virement permanent",
        "Bloquer/Debloquer carte", "Activer carte internationale", 
        "Demander un chequier", "Prendre rendez-vous", "Notifications", 
        "Modifier infos personnelles", "Deconnexion"
    };
    
    bool enLigne = true;
    while (enLigne) {
        int choix = naviguerMenu("MENU CLIENT", options);
        
        system("cls");
        if (options[choix] == "Deconnexion") {
            enLigne = false;
        } else {
            cout << "Vous avez choisi : " << options[choix] << endl;
            cout << "Fonctionnalite en cours de developpement (POO C++)..." << endl;
            cout << "\nAppuyez sur une touche pour retourner au menu.";
            _getch();
        }
    }
}

void menuAdmin() {
    vector<string> options = {
        "Consulter compte", "Valider comptes", "Supprimer compte", 
        "Bloquer/Debloquer compte", "Versement", "Historique compte", 
        "Traiter demandes chequier", "Afficher demandes admins", 
        "Valider admin", "Deconnexion"
    };
    
    bool enLigne = true;
    while (enLigne) {
        int choix = naviguerMenu("MENU ADMINISTRATEUR", options);
        
        system("cls");
        if (options[choix] == "Deconnexion") {
            enLigne = false;
        } else {
            cout << "Vous avez choisi : " << options[choix] << endl;
            cout << "Fonctionnalite en cours de developpement (POO C++)..." << endl;
            cout << "\nAppuyez sur une touche pour retourner au menu.";
            _getch();
        }
    }
}

void espaceAdmin() {
    vector<string> options = {"Connexion Administrateur", "Demande de compte Admin", "Retour"};
    bool actif = true;
    
    while (actif) {
        int choix = naviguerMenu("ESPACE ADMINISTRATEUR", options);
        
        if (choix == 0) {
            menuAdmin(); 
        } else if (choix == 1) {
            system("cls");
            cout << "Formulaire de demande d'administration..." << endl;
            _getch();
        } else if (choix == 2) {
            actif = false;
        }
    }
}


int main() {
    vector<string> optionsMain = {"Je suis un Client", "Je suis un Administrateur", "Quitter"};
    bool applicationActive = true;

    while (applicationActive) {
        int choix = naviguerMenu("MENU PRINCIPAL", optionsMain);

        switch (choix) {
            case 0:
                // Ici, il faudrait normalement demander le login/mot de passe
                menuClient();
                break;
            case 1:
                espaceAdmin();
                break;
            case 2:
                applicationActive = false;
                system("cls");
                cout << "Merci d'avoir utilise notre systeme bancaire !" << endl;
                break;
        }
    }

    return 0;
}