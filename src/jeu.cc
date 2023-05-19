#include "jeu.h"

#include <iostream>
#include <typeinfo>
using namespace std;

Partie::Partie() : tour_actuel(BLANC), roque_blanc(true), roque_noir(true) {}

void Partie::print() { plateau.print(); }

int Partie::coup(string origine, string destination) {
    Couleur couleur_piece = plateau.mes_pieces(origine)->ma_couleur();

    if (tour_actuel != couleur_piece) {
        cerr << "Vous ne pouvez bouger que les pieces de votre couleur" << endl;
        return false;
    }

    int resultat_coup = plateau.deplacement(origine, destination);

    if (plateau.echec_et_mat() == true)
        return VICTOIRE;

    if (plateau.est_pat() == true)
        return PAT;
        
    if (resultat_coup == false) {
        return false;
    } else {
        if (tour_actuel == NOIR) {
            tour_actuel = BLANC;
            return true;
        }
        if (tour_actuel == BLANC) {
            tour_actuel = NOIR;
            return true;
        }
    }
    return true;
}

Couleur Partie::couleur_actuelle() { return tour_actuel; }

void Partie::roque_dame() {
    if (tour_actuel == BLANC) {

        if (roque_blanc == false) {
            cerr << "Vous avez déjà roqué durant cette partie" << endl;
        }

        if (plateau.roque_reine(tour_actuel) == false)

            roque_blanc = false;
        tour_actuel = NOIR;
    }

    if (tour_actuel == NOIR) {
        if (roque_noir == false) {
            cerr << "Vous avez déjà roqué durant cette partie" << endl;
        }

        if (plateau.roque_reine(tour_actuel) == false)

            roque_noir = false;
        tour_actuel = BLANC;
    }
}

void Partie::roque_roi() {
    if (tour_actuel == BLANC) {

        if (roque_blanc == false) {
            cerr << "Vous avez déjà roqué durant cette partie" << endl;
        }

        if (plateau.roque_roi(tour_actuel) == false)

            roque_blanc = false;
        tour_actuel = NOIR;
    }

    if (tour_actuel == NOIR) {
        if (roque_noir == false) {
            cerr << "Vous avez déjà roqué durant cette partie" << endl;
        }

        if (plateau.roque_roi(tour_actuel) == false)

            roque_noir = false;
        tour_actuel = BLANC;
    }
}
