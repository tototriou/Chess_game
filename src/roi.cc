#include "roi.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Roi::Roi(Couleur couleur, string nom) : Piece(couleur, nom){};

/**
  * @brief détermine l'ensemble des positions possibles d'un King sur
  l'échiquier par rapport à sa position de départ.
  * @param origin la case de départ
  * @return un vecteur des coups_possibles d'arrivée possibles pour le King.
  **/
vector<Square> Roi::coups_possibles(Square origine) {

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();

    vector<Square> coups_possibles(0);

    coups_possibles.push_back(Square(x_org + 1, y_org));
    coups_possibles.push_back(Square(x_org - 1, y_org));
    coups_possibles.push_back(Square(x_org, y_org + 1));
    coups_possibles.push_back(Square(x_org, y_org - 1));
    coups_possibles.push_back(Square(x_org + 1, y_org + 1));
    coups_possibles.push_back(Square(x_org + 1, y_org - 1));
    coups_possibles.push_back(Square(x_org - 1, y_org + 1));
    coups_possibles.push_back(Square(x_org - 1, y_org - 1));

    return coups_possibles;
}

/**
 * @brief verifie la légalité générale d'un mouvement pour une pièce King.
 * @param plateau un pointeur vers l'board l'échiquier
 * @param origine la case de départ
 * @param case-end la case d'arrivée
 * @return true si le mouvement est légal, false sinon.
 **/
bool Roi::est_legal(Piece *plateau[8][8], Square origine, Square destination) {

    bool est_legal = Piece::est_legal(plateau, origine, destination);
    if (est_legal == false)
        return false;

    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    int delta_x = abs(x_org - x_dst);
    int delta_y = abs(y_org - y_dst);

    if ((delta_x > 1) || (delta_y > 1))
        return false;

    return true;
}
