#ifndef PION_HPP
#define PION_HPP

#include "couleur.h"
#include "piece.h"
#include "plateau.h"
#include "square.h"
#include <iostream>
#include <math.h>
#include <string>
#include <typeinfo>
#include <vector>

/**
 * @brief Cette classe met en place la classe Pion, elle permet de
 *représenter les pions et leurs mouvements.
 **/

class Pion : public Piece {
  public:
    Pion(Couleur couleur, std::string nom);

    /**
     * @see Piece::coups_possibles()
     */
    virtual std::vector<Square> coups_possibles(Square origine);

    /**
     * @see Piece::est_legal()
     */
    bool est_legal(Piece *plateau[8][8], Square origine, Square destination);
};

#endif
