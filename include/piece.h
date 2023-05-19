#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "couleur.h"
#include "square.h"

/**
 * @brief Cette classe met en place le type abstrait Piece, à partir duquel
 *toutes les pièces vont être dérivées. Elle permet aussi leur manipulation.
 **/

class Piece {
  public:
    Piece(Couleur couleur, std::string nom);

    /**
     * @brief affiche le nom de la pièce
     **/
    void print(void) const;

    /**
     * @return renvois la couleur de la pièce
     **/
    Couleur ma_couleur(void);

    /**
     * @return true si c'est le premier déplacement de la pièce
     * @return false si la pièce a déjà bougé
     **/
    bool premier_deplacement();

    /**
     * @brief initialise la valeur de "premier_deplacement" à false
     **/
    void a_bouge();

    /**
     * @brief vérifie que le coup demandé est légal
     * @param plateau un pointeur vers le plateau de jeu
     * @param origine la case de départ du coup
     * @param destination la destination demandée
     * @return true si le coup est légal
     * @return false si le coup est illégal
     **/
    virtual bool est_legal(Piece *plateau[8][8], Square origine,
                           Square destination);

    /**
     * @brief une fonction qui liste la liste de toutes les cases atteignables
     * à partir de la case d'origine, destinée à être surchargée dans toutes les
     *sous-classes
     * @param origine la position actuelle de la pièce
     * @return un vecteur de la Square
     **/
    virtual std::vector<Square> coups_possibles(Square origine);

  private:
    Couleur couleur;
    std::string nom;
    bool premier_coup;
};

#endif
