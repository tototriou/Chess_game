#include "reine.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Reine::Reine(Couleur couleur, string nom)
    : Piece(couleur, nom), Tour(couleur, nom), Fou(couleur, nom){};

vector<Square> Reine::coups_possibles(Square origine) {

    vector<Square> cases_possibles;

    vector<Square> r_sq_tour = Tour::coups_possibles(origine);
    vector<Square> r_sq_fou = Fou::coups_possibles(origine);

    cases_possibles.reserve(r_sq_tour.size() + r_sq_fou.size());
    cases_possibles.insert(cases_possibles.end(), r_sq_tour.begin(),
                           r_sq_tour.end());
    cases_possibles.insert(cases_possibles.end(), r_sq_fou.begin(),
                           r_sq_fou.end());

    return cases_possibles;
}

bool Reine::est_legal(Piece *plateau[8][8], Square origine,
                      Square destination) {

    bool est_legal_tour = Tour::est_legal(plateau, origine, destination);
    bool est_legal_fou = Fou::est_legal(plateau, origine, destination);

    if (!est_legal_tour && !est_legal_fou)
        return false;

    return true;
}
