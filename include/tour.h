#ifndef TOUR_HPP
#define TOUR_HPP

#include "couleur.h"
#include "piece.h"
#include "square.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Cette classe met en place le type Tour, pour représenter et manipuler
 *les tours. La classe Piece est virtuellement héritée pour éviter les erreurs
 * liées à l'héritage de cette classe par la classe Reine
 **/

class Tour : virtual public Piece {
  public:
    Tour(Couleur couleur, std::string nom = "\u2656");

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