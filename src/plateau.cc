#include "plateau.h"

#include <iostream>
#include <regex>
#include <typeinfo>
#include <vector>

using namespace std;

// Constructor
Plateau::Plateau() : mat(false), pat(false), echec(false) {
    for (int i(0); i < 8; i++) {
        for (int j(0); j < 8; j++) {
            plateau[i][j] = nullptr;
        }
    }

    vector<Piece *> pieces_blanches(8);
    vector<Piece *> pieces_noires(8);
    vector<Piece *> pions_blancs(8);
    vector<Piece *> pions_noirs(8);

    pieces_blanches[0] = new Tour(BLANC, " \u265C ");
    pieces_blanches[1] = new Cavalier(BLANC, " \u265E ");
    pieces_blanches[2] = new Fou(BLANC, " \u265D ");
    pieces_blanches[3] = new Reine(BLANC, " \u265B ");
    pieces_blanches[4] = new Roi(BLANC, " \u265A ");
    pieces_blanches[5] = new Fou(BLANC, " \u265D ");
    pieces_blanches[6] = new Cavalier(BLANC, " \u265E ");
    pieces_blanches[7] = new Tour(BLANC, " \u265C ");

    pieces_noires[0] = new Tour(NOIR, " \u2656 ");
    pieces_noires[1] = new Cavalier(NOIR, " \u2658 ");
    pieces_noires[2] = new Fou(NOIR, " \u2657 ");
    pieces_noires[3] = new Reine(NOIR, " \u2655 ");
    pieces_noires[4] = new Roi(NOIR, " \u2654 ");
    pieces_noires[5] = new Fou(NOIR, " \u2657 ");
    pieces_noires[6] = new Cavalier(NOIR, " \u2658 ");
    pieces_noires[7] = new Tour(NOIR, " \u2656 ");

    for (unsigned char i(0); i < 8; i++) {
        pose_une_piece(pieces_blanches[i], Square(0, i));
        pose_une_piece(pieces_noires[i], Square(7, i));
    }

    for (unsigned char i(0); i < 8; i++) {
        pions_blancs[i] = new Pion(BLANC, " \u265F ");
        pose_une_piece(pions_blancs[i], Square(1, i));
        pions_noirs[i] = new Pion(NOIR, " \u2659 ");
        pose_une_piece(pions_noirs[i], Square(6, i));
    }
}

void Plateau::print() const {

    string space5 = string(5, ' ');
    cout << endl;
    cout << "     a      b      c      d      e      f      g      h    "
         << endl;
    cout << "  +------+------+------+------+------+------+------+------+"
         << endl;
    for (int i(0); i < 8; i++) {
        cout << 8 - i << " ";
        for (int j(0); j < 8; j++) {
            cout << "|";
            if (plateau[7 - i][j]) {
                cout << " ";
                plateau[7 - i][j]->print();
                cout << " "
                     << " ";
            } else
                cout << space5 << " ";
        }
        cout
            << "|\n  +------+------+------+------+------+------+------+------+";
        cout << endl;
    }
}

Piece *Plateau::mes_pieces(Square square) {
    return plateau[square.ma_ligne()][square.ma_colonne()];
}

void Plateau::pose_une_piece(Piece *piece, Square square) {
    plateau[square.ma_ligne()][square.ma_colonne()] = piece;
}

bool Plateau::est_en_echec(Square origine, Square destination,
                           Couleur joueur_actuel) {
    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    Piece *piece_tmp = plateau[x_dst][y_dst];
    plateau[x_dst][y_dst] = plateau[x_org][y_org];
    plateau[x_org][y_org] = nullptr;

    Square case_roi;
    Square menace;

    for (int i(0); i < 8; i++) {
        for (int j(0); j < 8; j++) {
            if (plateau[i][j] != nullptr &&
                typeid(*(plateau[i][j])) == typeid(Roi) &&
                plateau[i][j]->ma_couleur() == joueur_actuel) {
                case_roi.maj_position(i, j);
            }
        }
    }

    for (int i(0); i < 8; i++) {
        for (int j(0); j < 8; j++) {
            if (plateau[i][j] != nullptr &&
                plateau[i][j]->ma_couleur() != joueur_actuel) {
                menace.maj_position(i, j);

                if (plateau[i][j]->est_legal(plateau, menace, case_roi) ==
                    true) {
                    plateau[x_org][y_org] = plateau[x_dst][y_dst];
                    plateau[x_dst][y_dst] = piece_tmp;
                    return true;
                }
            }
        }
    }

    plateau[x_org][y_org] = plateau[x_dst][y_dst];
    plateau[x_dst][y_dst] = piece_tmp;
    return false;
}

bool Plateau::est_mat(Couleur jouer_actuel) {
    for (int i(0); i < 8; i++) {
        for (int j(0); j < 8; j++) {
            if (plateau[i][j] != nullptr &&
                plateau[i][j]->ma_couleur() != jouer_actuel) {
                if (test_mat(plateau[i][j], Square(i, j)) == false)
                    return false;
            }
        }
    }
    return true;
}

bool Plateau::est_en_pat(Couleur jouer_actuel) {
    for (int i(0); i < 8; i++) {
        for (int j(0); j < 8; j++) {
            if (plateau[i][j] != nullptr &&
                plateau[i][j]->ma_couleur() != jouer_actuel) {
                if (test_pat(plateau[i][j], Square(i, j)) == false)
                    return false;
            }
        }
    }
    return true;
}

bool Plateau::test_mat(Piece *piece, Square origine) {
    Couleur couleur = piece->ma_couleur();

    vector<Square> squares = piece->coups_possibles(origine);
    size_t a = squares.size();

    for (size_t i(0); i < a; i++) {
        Square destination = squares[i];
        if (piece->est_legal(plateau, origine, destination) == true) {
            if (est_en_echec(origine, destination, couleur) == false)
                return false;
        }
    }
    return true;
}

bool Plateau::test_pat(Piece *piece, Square origine) {
    Couleur couleur = piece->ma_couleur();
    if (echec == true)
        return false;

    vector<Square> squares = piece->coups_possibles(origine);
    size_t a = squares.size();

    for (size_t i(0); i < a; i++) {
        Square destination = squares[i];
        if (piece->est_legal(plateau, origine, destination) == true) {
            if (est_en_echec(origine, destination, couleur) == false)
                return false;
        }
    }
    return true;
}

bool Plateau::est_pat() { return pat; }
bool Plateau::echec_et_mat() { return mat; }

bool Plateau::deplacement(Square origine, Square destination) {
    int x_org = origine.ma_ligne();
    int y_org = origine.ma_colonne();
    int x_dst = destination.ma_ligne();
    int y_dst = destination.ma_colonne();

    Couleur joueur = plateau[x_org][y_org]->ma_couleur();
    Couleur adversaire =
        (plateau[x_org][y_org]->ma_couleur() == BLANC) ? NOIR : BLANC;

    if (plateau[x_org][y_org]->est_legal(plateau, origine, destination) ==
        false) {
        cerr << "coup illégal" << endl;
        return false;
    }

    if (est_en_echec(origine, destination, joueur) == true) {
        cerr << "Ce coup te mettrait en echec" << endl;
        return false;
    }

    if (est_en_echec(origine, destination, adversaire) == true) {
        cout << "Echec" << endl;
        echec = true;
    }

    plateau[x_dst][y_dst] = plateau[x_org][y_org];
    plateau[x_org][y_org] = nullptr;

    if ((x_dst == 7 || x_dst == 0) &&
        typeid(*(plateau[x_dst][y_dst])) == typeid(Pion)) {
        print();
        cout << "Promotion" << endl;
        cout << "Type de piece en laquelle vous voulez promouvoir :" << endl;
        cout << "                         Reine" << endl;
        cout << "                         Cavalier " << endl;
        cout << "                         Fou" << endl;
        cout << "                         Tour" << endl;

        string type;
        cin >> type;
        while (promotion(type, destination, joueur) != true) {
            cerr << "Ce n'est pas un type de pièce valide" << endl;
            cout << "Type de piece en laquelle vous voulez promouvoir :"
                 << endl;
            cout << "                         Reine" << endl;
            cout << "                         Cavalier " << endl;
            cout << "                         Fou" << endl;
            cout << "                         Tour" << endl;
            cin >> type;
        }
    }

    if (est_mat(joueur) == true) {
        cout << "Echec et mat" << endl;
        mat = true;
    }
    if (est_en_pat(joueur) == true) {
        pat = true;
    }

    return true;
}

bool Plateau::promotion(string type, Square destination, Couleur joueur) {
    Piece *nouvelle_piece = nullptr;
    if (joueur == BLANC) {
        if (type == "Reine" || type == "reine")
            nouvelle_piece = new Reine(BLANC, " \u265B ");
        else if (type == "Cavalier " || type == "cavalier ")
            nouvelle_piece = new Cavalier(BLANC, " \u265E ");
        else if (type == "Fou" || type == "fou")
            nouvelle_piece = new Fou(BLANC, " \u265D ");
        else if (type == "Tour" || type == "tour")
            nouvelle_piece = new Tour(BLANC, " \u265C ");
    }

    else {
        if (type == "Reine" || type == "reine")
            nouvelle_piece = new Reine(NOIR, " \u2655 ");
        else if (type == "Cavalier " || type == "cavalier ")
            nouvelle_piece = new Cavalier(NOIR, " \u2658 ");
        else if (type == "Fou" || type == "fou")
            nouvelle_piece = new Fou(NOIR, " \u2657 ");
        else if (type == "Tour" || type == "tour")
            nouvelle_piece = new Tour(NOIR, " \u2656 ");
    }

    if (nouvelle_piece == nullptr) /// pas une pièce valide
        return false;

    pose_une_piece(nouvelle_piece, destination);

    return true;
}

bool Plateau::roque_reine(Couleur jouer_actuel) {
    if (jouer_actuel == BLANC) {

        if (plateau[0][4] == nullptr || plateau[0][7] == nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté reine" << endl;
            return false;
        }

        if (plateau[0][4]->premier_deplacement() == false ||
            plateau[0][0]->premier_deplacement() == false) {
            cerr << "Vous ne pouvez pas roquer du coté reine" << endl;
            return false;
        }

        if (plateau[0][1] != nullptr || plateau[0][2] != nullptr ||
            plateau[0][3] != nullptr) {
            cerr << "Vous ne nouVous ne pouvez pas roquer du coté reine"
                 << endl;
            return false;
        }

        for (int i(0); i < 8; i++) {
            for (int j(0); j < 8; j++) {
                if (plateau[i][j] != nullptr &&
                    plateau[i][j]->ma_couleur() == NOIR) {
                    for (int k = 2; k < 5; k++) {
                        if (plateau[i][j]->est_legal(plateau, Square(i, j),
                                                     Square(0, k))) {
                            cerr << "Vous ne pouvez pas roquer du coté reine"
                                 << endl;
                            return false;
                        }
                    }
                }
            }
        }

        plateau[0][4]->a_bouge();
        plateau[0][0]->a_bouge();
        plateau[0][2] = plateau[0][4];
        plateau[0][4] = nullptr;
        plateau[0][3] = plateau[0][0];
        plateau[0][0] = nullptr;

        return true;
    }

    if (jouer_actuel == NOIR) {

        if (plateau[7][4] == nullptr || plateau[7][7] == nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté reine" << endl;
            return false;
        }

        if (plateau[7][4]->premier_deplacement() == false ||
            plateau[7][0]->premier_deplacement() == false) {
            cerr << "Vous ne pouvez pas roquer du coté reine" << endl;
            return false;
        }

        if (plateau[7][1] != nullptr || plateau[7][2] != nullptr ||
            plateau[7][3] != nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté reine" << endl;
            return false;
        }

        for (int i(0); i < 8; i++) {
            for (int j(0); j < 8; j++) {
                if (plateau[i][j] != nullptr &&
                    plateau[i][j]->ma_couleur() == BLANC) {
                    for (int k = 2; k < 5; k++) {
                        if (plateau[i][j]->est_legal(plateau, Square(i, j),
                                                     Square(7, k))) {
                            cerr << "Vous ne pouvez pas roquer du coté reine"
                                 << endl;
                            return false;
                        }
                    }
                }
            }
        }

        plateau[7][4]->a_bouge();
        plateau[7][0]->a_bouge();
        plateau[7][2] = plateau[7][4];
        plateau[7][4] = nullptr;
        plateau[7][3] = plateau[7][0];
        plateau[7][0] = nullptr;
        return true;
    }

    return true;
}

bool Plateau::roque_roi(Couleur jouer_actuel) {

    if (jouer_actuel == BLANC) {

        if (plateau[0][4] == nullptr || plateau[0][7] == nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        if (plateau[0][4]->premier_deplacement() == false ||
            plateau[0][7]->premier_deplacement() == false) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        if (plateau[0][5] != nullptr || plateau[0][6] != nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        for (int i(0); i < 8; i++) {
            for (int j(0); j < 8; j++) {
                if (plateau[i][j] != nullptr &&
                    plateau[i][j]->ma_couleur() == NOIR) {
                    for (int k = 4; k < 7; k++) {
                        if (plateau[i][j]->est_legal(plateau, Square(i, j),
                                                     Square(0, k))) {
                            cerr << "Vous ne pouvez pas roquer du coté roi"
                                 << endl;
                            return false;
                        }
                    }
                }
            }
        }

        plateau[0][4]->a_bouge();
        plateau[0][7]->a_bouge();
        plateau[0][6] = plateau[0][4];
        plateau[0][4] = nullptr;
        plateau[0][5] = plateau[0][7];
        plateau[0][7] = nullptr;

        return true;
    }

    if (jouer_actuel == NOIR) {

        if (plateau[7][4] == nullptr || plateau[7][7] == nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        if (plateau[7][4]->premier_deplacement() == false ||
            plateau[7][7]->premier_deplacement() == false) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        if (plateau[7][5] != nullptr || plateau[7][6] != nullptr) {
            cerr << "Vous ne pouvez pas roquer du coté roi" << endl;
            return false;
        }

        for (int i(0); i < 8; i++) {
            for (int j(0); j < 8; j++) {
                if (plateau[i][j] != nullptr &&
                    plateau[i][j]->ma_couleur() == BLANC) {
                    for (int k = 4; k < 7; k++) {
                        if (plateau[i][j]->est_legal(plateau, Square(i, j),
                                                     Square(7, k))) {
                            cerr << "Vous ne pouvez pas roquer du coté roi"
                                 << endl;
                            return false;
                        }
                    }
                }
            }
        }

        plateau[7][4]->a_bouge();
        plateau[7][7]->a_bouge();
        plateau[7][6] = plateau[7][4];
        plateau[7][4] = nullptr;
        plateau[7][5] = plateau[7][7];
        plateau[7][7] = nullptr;

        return true;
    }

    return true;
}
