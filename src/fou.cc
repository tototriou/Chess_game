#include "fou.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Fou::Fou(Couleur couleur, string nom) : Piece(couleur, nom){};

vector<Square> Fou::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_tmp = x_org;
    int y_tmp = y_org;
    vector<Square> cases_possibles(0);

    while (x_tmp < 8 && y_tmp < 8) {
        x_tmp++;
        y_tmp++;
        cases_possibles.push_back(Square(x_tmp, y_tmp));
    }

    x_tmp = x_org;
    y_tmp = y_org;

    while (x_tmp > 0 && y_tmp > 0) {
        x_tmp--;
        y_tmp--;
        cases_possibles.push_back(Square(x_tmp, y_tmp));
    }

    x_tmp = x_org;
    y_tmp = y_org;

    while (x_tmp > 0 && y_tmp < 8) {
        x_tmp--;
        y_tmp++;
        cases_possibles.push_back(Square(x_tmp, y_tmp));
    }

    x_tmp = x_org;
    y_tmp = y_org;

    while (x_tmp < 8 && y_tmp > 0) {
        y_tmp--;
        x_tmp++;
        cases_possibles.push_back(Square(x_tmp, y_tmp));
    }
    return cases_possibles;
}

bool Fou::est_legal(Piece *plateau[8][8], Square origine, Square destination) {
    bool est_legal = Piece::est_legal(plateau, origine, destination);
    if (est_legal == false)
        return false;

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    int delta_x = abs(x_org - x_dst);
    int delta_y = abs(y_org - y_dst);

    if (delta_x != delta_y)
        return false;

    if (x_org < x_dst && y_org < y_dst) {
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org + i][y_org + i] != nullptr)
                return false;
        }
    }

    if (x_org < x_dst && y_org > y_dst) {
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org + i][y_org - i] != nullptr)
                return false;
        }
    }

    if (x_org > x_dst && y_org < y_dst) {
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org - i][y_org + i] != nullptr)
                return false;
        }
    }

    if (x_org > x_dst && y_org > y_dst) {
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org - i][y_org - i] != nullptr)
                return false;
        }
    }
    return true;
}
