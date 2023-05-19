#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <string>
#include <typeinfo>

#include "cavalier.h"
#include "couleur.h"
#include "fou.h"
#include "piece.h"
#include "pion.h"
#include "plateau.h"
#include "reine.h"
#include "roi.h"
#include "square.h"
#include "tour.h"

#define VICTOIRE 2
#define PAT 3

/**
 * @brief Cette classe représente une partie et gère ses états après chaque tour
 **/

class Partie {
  public:
    Partie();

    /**
     * @brief affiche l'état actuel de la partie : le plateau
     **/
    void print();

    /**
     * @brief vérifie si le joueur bouge une pièce qui lui appartient (de sa
     *couleur) ou pas
     * @param origine la case de départ du coup
     * @param destination la case d'arrivée du coup
     * @return
     **/
    int coup(std::string origine, std::string destination);

    /**
     * @return la couleur du joueur actuel
     **/
    Couleur couleur_actuelle();

    /**
     * @brief met a jour l'attribut privé <couleur>_roque et affiche un message
     *d'erreur si le roque est impossible coté dame
     **/
    void roque_dame();

    /**
     * @brief met a jour l'attribut privé <couleur>_roque et affiche un message
     *d'erreur si le roque est impossible coté roi
     **/
    void roque_roi();

  private:
    Plateau plateau;
    Couleur tour_actuel;
    bool roque_blanc; // les blancs peuvent roquer
    bool roque_noir;  // les noirs peuvent roquer
};

#endif
