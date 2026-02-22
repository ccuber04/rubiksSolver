#include "cube.h"
#include <iostream>

Cube::Cube() {
    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                faces[face][row][col] = static_cast<Color>(face);
            }
        }
    }
}

void Cube::apply_move(Move m) { // change to switch statement??
    if (m == R) {

    }
    else if (m == U) {

    }
    else if (m == F) {

    }
    else if (m == L) {

    }
    else if (m == D) {

    }
    else if (m == B) {

    }
}

bool Cube::is_solved() const {
    bool solved = false;
    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                solved = (faces[face][row][col] == static_cast<Color>(face));
                if (!solved) {
                    break;
                }
            }
            if (!solved) {
                break;
            }
        }
        if (!solved) {
            break;
        }
    }
    return solved;
}

void Cube::scramble() {
    this->apply_move(R);
    this->apply_move(U);
    this->apply_move(F);
}

void Cube::print() {
    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                std::cout << faces[face][row][col];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
