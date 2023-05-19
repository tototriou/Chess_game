#include "square.h"
#include <iostream>
using namespace std;

Square::Square(void) : n_x(0), n_y(0) {}
Square::Square(int x, int y) : n_x(x), n_y(y) {}
Square::Square(string position) : n_position(position) {
    n_y = position[0] - 'a';
    n_x = atoi(&position[1]) - 1;
}

int Square::ma_ligne(void) { return n_x; }

int Square::ma_colonne(void) { return n_y; }

void Square::vers_string(int x, int y) {

    int ligne = x + 1;
    int colonne = y;

    switch (colonne) {
    case 0:
        cout << "a" << ligne << endl;
        break;
    case 1:
        cout << "b" << ligne << endl;
        break;
    case 2:
        cout << "c" << ligne << endl;
        break;
    case 3:
        cout << "d" << ligne << endl;
        break;
    case 4:
        cout << "e" << ligne << endl;
        break;
    case 5:
        cout << "f" << ligne << endl;
        break;
    case 6:
        cout << "g" << ligne << endl;
        break;
    case 7:
        cout << "h" << ligne << endl;
        break;
    }
}

void Square::maj_position(int x, int y) {
    n_x = x;
    n_y = y;
}
