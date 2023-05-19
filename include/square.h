#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief This class represents a square on the chessboard, represented by its
 * coordinates, which can be manipulated
 */
/**
 * @brief Cette classe représente une case sur le plateau de jeu,
 * elle est définie par ses coordonnées qui peuvent être manipulées
 */

class Square {
  public:
    Square(void);
    Square(int x, int y);
    Square(std::string position);

    /**
     * @return la ligne de la case
     **/
    int ma_ligne(void);

    /**
     * @return la colonne de la case
     **/
    int ma_colonne(void);

    /**
     * @brief transforme des coordonnées en string
     * @param x une ligne du plateau
     * @param y une colonne du plateau
     **/
    void vers_string(int x, int y);

    /**
     * @brief met a jour les coordonnées de la case
     * @param x n_x nouvelle valeur pour x
     * @param y n_y nouvelle valeur pour y
     **/
    void maj_position(int x, int y);

  private:
    int n_x;
    int n_y;
    std::string n_position;
};

#endif