#include "piece.h"

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

Piece::Piece(Couleur couleur, string nom)
    : couleur(couleur), nom(nom), premier_coup(true) {}

void Piece::print() const { cout << nom; }

Couleur Piece::ma_couleur() { return (couleur); }

bool Piece::premier_deplacement() { return (premier_coup); }

void Piece::a_bouge() { premier_coup = false; }

bool Piece::est_legal(Piece *plateau[8][8], Square origine,
                      Square destination) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    if (plateau[x_org][y_org] == nullptr)
        return false;

    if (x_dst < 0 || x_dst > 7)
        return false;

    if (y_dst < 0 || y_dst > 7)
        return false;

    if (x_org == x_dst && y_org == y_dst)
        return false;

    if (plateau[x_dst][y_dst] != nullptr) {
        Couleur couleur_org = plateau[x_org][y_org]->ma_couleur();
        Couleur couleur_dest = plateau[x_dst][y_dst]->ma_couleur();

        if (couleur_org == couleur_dest)
            return false;
    }

    return true;
}

vector<Square> Piece::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();

    if (x_org < 0 || x_org > 7) {
        vector<Square> squares(0);
        return squares;
    }

    if (y_org < 0 || y_org > 7) {
        vector<Square> squares(0);
        return squares;
    }
    vector<Square> squares(1);
    return squares;
}
