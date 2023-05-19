#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include "couleur.h"
#include "piece.h"
#include "square.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Cette classe met en place la classe Cavalier, elle permet de
 *représenter les cavaliers et leurs mouvements.
 **/

class Cavalier : virtual public Piece {
  public:
    Cavalier(Couleur couleur, std::string nom = "\u2658");

    /**
     * @see Piece::coups_possibles()
     */
    virtual std::vector<Square> coups_possibles(Square origine);

    /**
     * @see Piece::est_legal()
     */
    bool est_legal(Piece *plateau[8][8], Square origin, Square destination);
};

#endif
