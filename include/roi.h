#ifndef ROI_HPP
#define ROI_HPP

#include "couleur.h"
#include "piece.h"
#include "square.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Cette classe met en place la classe Roi, elle permet de
 *  représenter le roi et ses mouvements.
 **/

class Roi : public Piece {
  public:
    Roi(Couleur couleur, std::string nom = " \u2654 ");

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
