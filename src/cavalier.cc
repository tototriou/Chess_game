#include "cavalier.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Cavalier::Cavalier(Couleur couleur, string nom) : Piece(couleur, nom){};

vector<Square> Cavalier::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();

    vector<Square> cases_possibles(1);

    cases_possibles.push_back(Square(x_org + 1, y_org + 2));
    cases_possibles.push_back(Square(x_org + 2, y_org + 1));
    cases_possibles.push_back(Square(x_org - 1, y_org + 2));
    cases_possibles.push_back(Square(x_org - 2, y_org + 1));
    cases_possibles.push_back(Square(x_org + 1, y_org - 2));
    cases_possibles.push_back(Square(x_org + 2, y_org - 1));
    cases_possibles.push_back(Square(x_org - 1, y_org - 2));
    cases_possibles.push_back(Square(x_org - 2, y_org - 1));

    return cases_possibles;
}

bool Cavalier::est_legal(Piece *plateau[8][8], Square origine,
                         Square destination) {
    bool est_legal = Piece::est_legal(plateau, origine, destination);
    if (est_legal == false)
        return false;

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dest = destination.ma_ligne();
    int y_dest = destination.ma_colonne();

    int delta_x = abs(x_org - x_dest);
    int delta_y = abs(y_org - y_dest);

    if (delta_x > 2 || delta_x < 1 || delta_y < 1 || delta_y > 2)
        return false;

    if (delta_x == delta_y)
        return false;

    return true;
}