#include "tour.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Tour::Tour(Couleur couleur, string nom) : Piece(couleur, nom){};

vector<Square> Tour::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    vector<Square> cases_possibles(0);

    // The lis of all possible moves is comprised of the entire row the and
    // entire column where the Rook is present

    for (size_t i = 0; i < 8; i++) {
        cases_possibles.push_back(Square(x_org, i));
        cases_possibles.push_back(Square(i, y_org));
    }

    return cases_possibles;
}

bool Tour::est_legal(Piece *plateau[8][8], Square origine, Square destination) {
    bool est_legal = Piece::est_legal(plateau, origine, destination);
    if (est_legal == false)
        return false;

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    if (x_org != x_dst && y_org != y_dst)
        return false;

    if (x_org == x_dst && y_org < y_dst) {
        int delta_y = y_dst - y_org;
        for (int i(1); i < delta_y; i++) {
            if (plateau[x_org][y_org + i] != nullptr)
                return false;
        }
    }

    if (x_org == x_dst && y_org > y_dst) {
        int delta_y = y_org - y_dst;
        for (int i(1); i < delta_y; i++) {
            if (plateau[x_org][y_org - i] != nullptr)
                return false;
        }
    }

    if (y_org == y_dst && x_org < x_dst) {
        int delta_x = x_dst - x_org;
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org + i][y_org] != nullptr)
                return false;
        }
    }

    if (y_org == y_dst && x_dst < x_org) {
        int delta_x = x_org - x_dst;
        for (int i(1); i < delta_x; i++) {
            if (plateau[x_org - i][y_org] != nullptr)
                return false;
        }
    }
    return true;
}