#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include <string>
#include <typeinfo>

#include "cavalier.h"
#include "couleur.h"
#include "fou.h"
#include "piece.h"
#include "pion.h"
#include "reine.h"
#include "roi.h"
#include "square.h"
#include "tour.h"

/**
 * @brief Cette classe met en place la classe plateau, elle permet d'afficher
 * le plateau  et les mouvements des pièces.
 **/

class Plateau {
  public:
    Plateau();

    /**
     * @brief affiche le plateau
     **/
    void print() const;

    /**
     * @param square : les cases du plateau
     * @return les pièces sur les différentes cases
     **/
    Piece *mes_pieces(Square square);

    /**
     * @brief pose une piece sur le plateau
     * @param square : les cases du plateau
     * @param piece une type de pièce
     **/
    void pose_une_piece(Piece *piece, Square square);

    /**
     * @brief vérifie si le roi est mis en echec
     * @param origine la case d'origine de la pièce
     * @param destination la destination du coup
     * @param joueur_actuel la couleur du joueur actuel
     * @return true si le coup met le roi en echec
     * @return false si le coup ne met pas le roi en echec
     **/
    bool est_en_echec(Square origine, Square destination,
                      Couleur joueur_actuel);

    /**
     * @brief verifie si le joueur est en echec et mat
     * @param joueur_actuel couleur du joueur actuel
     * @return true si l'adversaire est en echec et mat
     * @return false si l'adversaire n'est pas en echec et mat
     **/
    bool est_mat(Couleur joueur_actuel);

    /**
     * @brief verifie si la partie est en état de pat
     * @param joueur_actuel couleur du joueur actuel
     * @return true si il y a pat
     * @return false sinon
     **/
    bool est_en_pat(Couleur joueur_actuel);

    /**
     * @brief verifie si le joueur a un coup pour le sortir de l'echec
     * @param piece
     * @param origine la case ou est située la pièce
     * @return true si il n'existe aucun coup permettant au joueur de sortir de
     * l'echec
     * @return false si il existe un coup pour sortir le joueur de l'echec
     **/
    bool test_mat(Piece *piece, Square origine);

    /**
     * @brief verifie si le joueur a un coup pour le sortir de l'echec
     * @param piece
     * @param origine la case ou est située la pièce
     * @return true si il n'existe aucun coup permettant au joueur de sortir de
     * l'echec
     * @return false si il existe un coup pour sortir le joueur de l'echec
     **/
    bool test_pat(Piece *piece, Square origine);

    /**
     * @return la valeur de l'attribut privé mat
     **/
    bool echec_et_mat();

    /**
     * @return la valeur de l'attribut privé pat
     **/
    bool est_pat();

    /**
     * @brief déplace la pièce de sa case d'origine à sa case de destination
     * @param origine la case de départ de la pièce
     * @param destination la case de destination de la pièce
     * @return false si le coup est illégal ou met le joueur en echec
     * @return true si le coup est legal et ne met pas le joueur en echec
     **/
    bool deplacement(Square origine, Square destination);

    /**
     * @brief fait la promotion d'un pion en une autre pièce (dame,tour,...)
     * @param type le type de la pièce en laquelle le joueur veut changer le
     *pion
     * @param destination la case de destination du coup
     * @param couleur du joueur actuel
     * @return true si le pion a bien été promu
     * @return false sinon
     **/
    bool promotion(std::string type, Square destination, Couleur couleur);

    /**
     * @brief vérifie si le joueur peut faire un roque coté reine
     * @param couleur_actuelle du joueur
     * @return true si le roque est possible et l'exécute
     * @return false si le roque n'est pas possible
     **/
    bool roque_reine(Couleur couleur_actuelle);

    /**
     * @brief vérifie si le joueur peut faire un roque coté roi
     * @param couleur_actuelle du joueur
     * @return true si le roque est possible et l'exécute
     * @return false si le roque n'est pas possible
     **/
    bool roque_roi(Couleur couleur_actuelle);

  private:
    Piece *plateau[8][8];
    bool mat;
    bool pat;
    bool echec;
};

#endif
