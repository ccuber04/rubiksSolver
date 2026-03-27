#include "cube.h"
#include <iostream>
#include <algorithm>

Cube::Cube(int size)
    : size{size}, faces(6*size*size) {
    for (int piece = 0; piece < 6 * size * size; ++piece) { // (0-8) white, (9-17) orange, (18-26) green, (27-35) red, (36-44) blue, (45-53) yellow
        faces[piece] = static_cast<Color>(piece / (size * size));
    }
}

void Cube::apply_move(Move m) {
    switch (m) {
    case R: {
        std::cout << "R\n";
        std::swap(faces[2], faces[20]);
        std::swap(faces[5], faces[23]);
        std::swap(faces[8], faces[26]); // F->U
        std::swap(faces[20], faces[47]);
        std::swap(faces[23], faces[50]);
        std::swap(faces[26], faces[53]); // D->F
        std::swap(faces[47], faces[42]);
        std::swap(faces[50], faces[39]);
        std::swap(faces[53], faces[36]); // B->D and U->B
        std::swap(faces[27], faces[29]);
        std::swap(faces[27], faces[33]);
        std::swap(faces[33], faces[35]); // corners rotate
        std::swap(faces[28], faces[32]);
        std::swap(faces[28], faces[30]);
        std::swap(faces[30], faces[34]); // edges rotate
        break;
    }
    case Rp: {
        std::cout << "Rp\n";
        std::swap(faces[2], faces[42]);
        std::swap(faces[5], faces[39]);
        std::swap(faces[8], faces[36]); // B->U
        std::swap(faces[42], faces[47]);
        std::swap(faces[39], faces[50]);
        std::swap(faces[36], faces[53]); // D->B
        std::swap(faces[47], faces[20]);
        std::swap(faces[50], faces[23]);
        std::swap(faces[53], faces[26]); // F->D and U->F
        std::swap(faces[27], faces[33]);
        std::swap(faces[27], faces[29]);
        std::swap(faces[29], faces[35]); // corners rotate
        std::swap(faces[28], faces[30]);
        std::swap(faces[28], faces[32]);
        std::swap(faces[32], faces[34]); // edges rotate
        break;
    }
    case U: {
        std::cout << "U\n";
        std::swap(faces[9], faces[18]);
        std::swap(faces[10], faces[19]);
        std::swap(faces[11], faces[20]); // F->L
        std::swap(faces[18], faces[27]);
        std::swap(faces[19], faces[28]);
        std::swap(faces[20], faces[29]); // R->F
        std::swap(faces[27], faces[36]);
        std::swap(faces[28], faces[37]);
        std::swap(faces[29], faces[38]); // B->R and L->B
        std::swap(faces[0], faces[2]);
        std::swap(faces[0], faces[6]);
        std::swap(faces[6], faces[8]); // corners rotate
        std::swap(faces[1], faces[5]);
        std::swap(faces[1], faces[3]);
        std::swap(faces[3], faces[7]); // edges rotate
        break;
    }
    case Up: {
        std::cout << "Up\n";
        std::swap(faces[9], faces[36]);
        std::swap(faces[10], faces[37]);
        std::swap(faces[11], faces[38]); // B->L
        std::swap(faces[36], faces[27]);
        std::swap(faces[37], faces[28]);
        std::swap(faces[38], faces[29]); // R->B
        std::swap(faces[27], faces[18]);
        std::swap(faces[28], faces[19]);
        std::swap(faces[29], faces[20]); // F->R and L->F
        std::swap(faces[0], faces[6]);
        std::swap(faces[0], faces[2]);
        std::swap(faces[2], faces[8]); // corners rotate
        std::swap(faces[1], faces[3]);
        std::swap(faces[1], faces[5]);
        std::swap(faces[5], faces[7]); // edges rotate
        break;
    }
    case F: {
        std::cout << "F\n";
        std::swap(faces[27], faces[6]);
        std::swap(faces[30], faces[7]);
        std::swap(faces[33], faces[8]); // U->R
        std::swap(faces[6], faces[11]);
        std::swap(faces[7], faces[14]);
        std::swap(faces[9], faces[17]); // L->U
        std::swap(faces[11], faces[45]);
        std::swap(faces[14], faces[46]);
        std::swap(faces[17], faces[47]); // D->L and R->D
        std::swap(faces[18], faces[20]);
        std::swap(faces[18], faces[24]);
        std::swap(faces[24], faces[26]); // corners rotate
        std::swap(faces[19], faces[23]);
        std::swap(faces[19], faces[21]);
        std::swap(faces[21], faces[25]); // edges rotate
        break;
    }
    case Fp: {
        std::cout << "Fp\n";
        std::swap(faces[27], faces[45]);
        std::swap(faces[30], faces[46]);
        std::swap(faces[33], faces[47]); // D->R
        std::swap(faces[45], faces[11]);
        std::swap(faces[46], faces[14]);
        std::swap(faces[47], faces[17]); // L->D
        std::swap(faces[11], faces[6]);
        std::swap(faces[14], faces[7]);
        std::swap(faces[17], faces[8]); // U->L and R->U
        std::swap(faces[18], faces[24]);
        std::swap(faces[18], faces[20]);
        std::swap(faces[20], faces[26]); // corners rotate
        std::swap(faces[19], faces[21]);
        std::swap(faces[19], faces[23]);
        std::swap(faces[23], faces[25]); // edges rotate
        break;
    }
    case L: {
        std::cout << "L\n";
        std::swap(faces[2], faces[42]);
        std::swap(faces[5], faces[39]);
        std::swap(faces[8], faces[36]); // B->U
        std::swap(faces[42], faces[47]);
        std::swap(faces[39], faces[50]);
        std::swap(faces[36], faces[53]); // D->B
        std::swap(faces[47], faces[20]);
        std::swap(faces[50], faces[23]);
        std::swap(faces[53], faces[26]); // F->D and U->F
        std::swap(faces[27], faces[33]);
        std::swap(faces[27], faces[29]);
        std::swap(faces[29], faces[35]); // corners rotate
        std::swap(faces[28], faces[30]);
        std::swap(faces[28], faces[32]);
        std::swap(faces[32], faces[34]); // edges rotate
        break;
    }
    case Lp: {
        break;
    }
    case D: {
        // std::cout << "D\n";
        // std::array<Color, 3> temp = faces[4][2];
        // faces[4][2] = faces[3][2];
        // faces[3][2] = faces[2][2];
        // faces[2][2] = faces[1][2];
        // faces[1][2] = temp;
        // rotate_face(faces[5]);
        break;
    }
    case Dp: {
        break;
    }
    case B: {
        // std::cout << "B\n";
        // Strips strips; // [0->0, 1->1, 2->5, 3->3]
        //
        // // create strips that will turn
        // strips[0] = faces[0][0]; // U
        // std::reverse(std::begin(strips[0]), std::end(strips[0])); // reverse U
        // strips[1] = create_strip(faces, 1, 0); // L
        // strips[2] = faces[5][2]; // D
        // std::reverse(std::begin(strips[2]), std::end(strips[2])); // reverse D
        // strips[3] = create_strip(faces, 3, 2); // R
        //
        // // turn strip
        // turn_strips_rows(faces, strips, 0, 0, 3); // U <- R
        // turn_strips_cols(faces, strips, 3, 2, 2); // R <- D
        // turn_strips_rows(faces, strips, 5, 2, 1); // D <- L
        // turn_strips_cols(faces, strips, 1, 0, 0); // L <- U (reversed)
        //
        // rotate_face(faces[4]);
        break;
    }
    case Bp: {
        break;
    }
    }
}

bool Cube::is_solved() const {
    for (int piece = 0; piece < 6 * size * size; ++piece) {
        if (faces.at(piece) != static_cast<Color>(piece / (size * size))) {
            return false;
        }
    }
    return true;
}

void Cube::scramble() {
    this->apply_move(F);
}

void Cube::print() {
    // print U face
    for (int row = 0; row < size; ++row) {
        std::cout << "\t ";
        for (int col = 0; col < size; ++col) {
            std::cout << color_to_string(faces[row * size + col]) << " ";
        }
        std::cout << "\n";
    }

    // print L, F, R, B faces TODO: (rework this logic and reduce to single loop)
    for (int row = 0; row < size; ++row) {
        for (int face = 1; face < 5; ++face) {
            for (int col = 0; col < size; ++col) {
                std::cout << color_to_string(faces[face * (size * size) + (row * size) + col]) << " ";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }

    // print D face
    for (int row = 0; row < size; ++row) {
        std::cout << "\t ";
        for (int col = 0; col < size; ++col) {
            std::cout << color_to_string(faces[5 * (size * size) + row * size + col]) << " ";
        }
        std::cout << "\n";
    }
}

bool Cube::operator==(const Cube& cube) const {
    for (int piece = 0; piece < 6 * size * size; ++piece) {
        if (faces[piece] != cube.faces[piece]) {
            return false;
        }
    }
    return true;
}

// helpers
std::string color_to_string(Color c) {
    switch (c) {
    case White:
        return "W";
    case Green:
        return "G";
    case Yellow:
        return "Y";
    case Orange:
        return "O";
    case Red:
        return "R";
    case Blue:
        return "B";
    }
    return "";
}

// std::array<Color, 3> create_strip(const Faces& faces, int face_id, int col) {
//     std::array<Color, 3> strip;
//     for (int i = 0; i < 3; ++i) {
//         strip[i] = faces[face_id][i][col];
//     }
//     return strip;
// }
//
// void turn_strips_cols(Faces& faces, const Strips& strips, int face_id, int col, int from_strip) {
//     for (int i = 0; i < 3; ++i) {
//         faces[face_id][i][col] = strips[from_strip][i];
//     }
// }
//
// void turn_strips_rows(Faces& faces, const Strips& strips, int face_id, int row, int from_strip) {
//     for (int i = 0; i < 3; ++i) {
//         faces[face_id][row][i] = strips[from_strip][i];
//     }
// }
