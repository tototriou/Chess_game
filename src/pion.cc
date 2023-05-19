#include "pion.h"

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

Pion::Pion(Couleur couleur, string nom) : Piece(couleur, nom){};

vector<Square> Pion::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();

    vector<Square> cases_possibles(0);

    cases_possibles.push_back(Square(x_org + 1, y_org));
    cases_possibles.push_back(Square(x_org + 2, y_org));
    cases_possibles.push_back(Square(x_org - 1, y_org));
    cases_possibles.push_back(Square(x_org - 2, y_org));
    cases_possibles.push_back(Square(x_org + 1, y_org + 1));
    cases_possibles.push_back(Square(x_org + 1, y_org - 1));
    cases_possibles.push_back(Square(x_org - 1, y_org + 1));
    cases_possibles.push_back(Square(x_org - 1, y_org - 1));

    return cases_possibles;
}

bool Pion::est_legal(Piece *plateau[8][8], Square origine, Square destination) {

    bool est_legal = Piece::est_legal(plateau, origine, destination);
    if (est_legal == false)
        return false;

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    int delta_x = abs(x_org - x_dst);
    int delta_y = abs(y_dst - y_org);
    Couleur couleur_pion = plateau[x_org][y_org]->ma_couleur();
    bool premier_deplacement = plateau[x_org][y_org]->premier_deplacement();

    if (couleur_pion == BLANC && x_org > x_dst)
        return false;

    if (couleur_pion == NOIR && x_org < x_dst)
        return false;

    switch (delta_y) {
    case 0:
        if (plateau[x_dst][y_dst] != nullptr)
            return false;

        if (premier_deplacement && delta_x > 2)
            return false;

        else if (!premier_deplacement && delta_x > 1)
            return false;
        break;

    case 1:
        if (plateau[x_dst][y_dst] == nullptr)
            return false;

        if (delta_x > 1)
            return false;
        break;

    default:
        return false;
    }

    return true;
}
