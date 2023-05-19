#ifndef REINE_HPP
#define REINE_HPP

#include "couleur.h"
#include "fou.h"
#include "piece.h"
#include "square.h"
#include "tour.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Cette classe met en place la classe Reine, elle permet de
 *  représenter la reine et ses mouvements.
 * cette classe hérite des classes Fou et Tour car les déplacements de
 * la reine sont une combinaisons de ces deux derniers.
 **/

class Reine : public Tour, public Fou {
  public:
    Reine(Couleur couleur, std::string nom = "\u2655");

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
