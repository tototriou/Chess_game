#include "jeu.h"
#include <iostream>
using namespace std;

int main() {
    Partie monjeu; // initialisation de la partie
    string coup_du_joueur;
    bool stop(false);
    monjeu.print();

    do {
        Couleur joueur_actuel = monjeu.couleur_actuelle();

        cout << "Tour : ";
        if (joueur_actuel == BLANC)
            cout << "Blanc ";
        else
            cout << "Noir ";

        cout << "coup du joueur (eg. a1a8) ? ";
        cin >> coup_du_joueur;
        cout << "\e[1;1H\e[2J";

        if (coup_du_joueur == "quit") {
            cout << "fin demandéé" << endl;
            stop = true;
        }

        if (coup_du_joueur != "/quit") {
            int resultat;
            if (coup_du_joueur == "O-O") {
                monjeu.roque_roi();
            }

            else if (coup_du_joueur == "O-O-O") {
                monjeu.roque_roi();
            }

            else {
                string origine = coup_du_joueur.substr(0, 2);
                string destination = coup_du_joueur.substr(2, 2);
                resultat = monjeu.coup(origine, destination);
            }

            monjeu.print();
            if (resultat == VICTOIRE) {
                stop = true;

                if (joueur_actuel == BLANC)
                    cout << "Blanc ";

                else
                    cout << "Noir ";

                cout << "vous avez gagné !" << endl;
            }
            if (resultat == PAT) {
                stop = true;
                cout << "Nul par PAT" << endl;
            }
        }

        else {
            stop = true;
        }
    } while (!stop);
}