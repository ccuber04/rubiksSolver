#include "cube.h"

#include <iostream>
#include <algorithm>
#include <sstream>

Cube::Cube(const int& size)
    : size{size}, faces(6*size*size) {
    for (int piece = 0; piece < 6 * size * size; ++piece) { // (0-8) white, (9-17) orange, (18-26) green, (27-35) red, (36-44) blue, (45-53) yellow
        faces[piece] = static_cast<Color>(piece / (size * size));
    }
}

void Cube::apply_move(const Move& m) {
    switch (m) {
    case R: {
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
    case R2: {
        apply_move(R);
        apply_move(R);
        break;
    }
    case U: {
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
    case U2: {
        apply_move(U);
        apply_move(U);
        break;
    }
    case F: {
        std::swap(faces[27], faces[6]);
        std::swap(faces[30], faces[7]);
        std::swap(faces[33], faces[8]); // U->R
        std::swap(faces[6], faces[17]);
        std::swap(faces[7], faces[14]);
        std::swap(faces[8], faces[11]); // L->U
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
        std::swap(faces[27], faces[47]);
        std::swap(faces[30], faces[46]);
        std::swap(faces[33], faces[45]); // D->R
        std::swap(faces[45], faces[11]);
        std::swap(faces[46], faces[14]);
        std::swap(faces[47], faces[17]); // L->D
        std::swap(faces[11], faces[8]);
        std::swap(faces[14], faces[7]);
        std::swap(faces[17], faces[6]); // U->L and R->U
        std::swap(faces[18], faces[24]);
        std::swap(faces[18], faces[20]);
        std::swap(faces[20], faces[26]); // corners rotate
        std::swap(faces[19], faces[21]);
        std::swap(faces[19], faces[23]);
        std::swap(faces[23], faces[25]); // edges rotate
        break;
    }
    case F2: {
        apply_move(F);
        apply_move(F);
        break;
    }
    case L: {
        std::swap(faces[0], faces[44]);
        std::swap(faces[3], faces[41]);
        std::swap(faces[6], faces[38]); // B->U
        std::swap(faces[44], faces[45]);
        std::swap(faces[41], faces[48]);
        std::swap(faces[38], faces[51]); // D->B
        std::swap(faces[45], faces[18]);
        std::swap(faces[48], faces[21]);
        std::swap(faces[51], faces[24]); // F->D and U->F
        std::swap(faces[9], faces[11]);
        std::swap(faces[9], faces[15]);
        std::swap(faces[15], faces[17]); // corners rotate
        std::swap(faces[10], faces[14]);
        std::swap(faces[10], faces[12]);
        std::swap(faces[12], faces[16]); // edges rotate
        break;
    }
    case Lp: {
        std::swap(faces[0], faces[18]);
        std::swap(faces[3], faces[21]);
        std::swap(faces[6], faces[24]); // F->U
        std::swap(faces[18], faces[45]);
        std::swap(faces[21], faces[48]);
        std::swap(faces[24], faces[51]); // D->F
        std::swap(faces[45], faces[44]);
        std::swap(faces[48], faces[41]);
        std::swap(faces[51], faces[38]); // B->D and U->B
        std::swap(faces[9], faces[15]);
        std::swap(faces[9], faces[11]);
        std::swap(faces[11], faces[17]); // corners rotate
        std::swap(faces[10], faces[12]);
        std::swap(faces[10], faces[14]);
        std::swap(faces[14], faces[16]); // edges rotate
        break;
    }
    case L2: {
        apply_move(L);
        apply_move(L);
        break;
    }
    case D: {
        std::swap(faces[33], faces[24]);
        std::swap(faces[34], faces[25]);
        std::swap(faces[35], faces[26]); // F->R
        std::swap(faces[24], faces[15]);
        std::swap(faces[25], faces[16]);
        std::swap(faces[26], faces[17]); // L->F
        std::swap(faces[15], faces[42]);
        std::swap(faces[16], faces[43]);
        std::swap(faces[17], faces[44]); // B->L and R->B
        std::swap(faces[45], faces[47]);
        std::swap(faces[45], faces[51]);
        std::swap(faces[51], faces[53]); // corners rotate
        std::swap(faces[46], faces[50]);
        std::swap(faces[46], faces[48]);
        std::swap(faces[48], faces[52]); // edges rotate
        break;
    }
    case Dp: {
        std::swap(faces[33], faces[42]);
        std::swap(faces[34], faces[43]);
        std::swap(faces[35], faces[44]); // B->R
        std::swap(faces[42], faces[15]);
        std::swap(faces[43], faces[16]);
        std::swap(faces[44], faces[17]); // L->B
        std::swap(faces[15], faces[24]);
        std::swap(faces[16], faces[25]);
        std::swap(faces[17], faces[26]); // F->L and R->F
        std::swap(faces[45], faces[51]);
        std::swap(faces[45], faces[47]);
        std::swap(faces[47], faces[53]); // corners rotate
        std::swap(faces[46], faces[48]);
        std::swap(faces[46], faces[50]);
        std::swap(faces[50], faces[52]); // edges rotate
        break;
    }
    case D2: {
        apply_move(D);
        apply_move(D);
        break;
    }
    case B: {
        std::swap(faces[15], faces[0]);
        std::swap(faces[12], faces[1]);
        std::swap(faces[9], faces[2]); // U->L
        std::swap(faces[0], faces[29]);
        std::swap(faces[1], faces[32]);
        std::swap(faces[2], faces[35]); // R->U
        std::swap(faces[29], faces[53]);
        std::swap(faces[32], faces[52]);
        std::swap(faces[35], faces[51]); // D->R and L->D
        std::swap(faces[36], faces[38]);
        std::swap(faces[36], faces[42]);
        std::swap(faces[42], faces[44]); // corners rotate
        std::swap(faces[37], faces[41]);
        std::swap(faces[37], faces[39]);
        std::swap(faces[39], faces[43]); // edges rotate
        break;
    }
    case Bp: {
        std::swap(faces[15], faces[53]);
        std::swap(faces[12], faces[52]);
        std::swap(faces[9], faces[51]); // D->L
        std::swap(faces[53], faces[29]);
        std::swap(faces[52], faces[32]);
        std::swap(faces[51], faces[35]); // R->D
        std::swap(faces[29], faces[0]);
        std::swap(faces[32], faces[1]);
        std::swap(faces[35], faces[2]); // U->R and L->U
        std::swap(faces[36], faces[42]);
        std::swap(faces[36], faces[38]);
        std::swap(faces[38], faces[44]); // corners rotate
        std::swap(faces[37], faces[39]);
        std::swap(faces[37], faces[41]);
        std::swap(faces[41], faces[43]); // edges rotate
        break;
    }
    case B2: {
        apply_move(B);
        apply_move(B);
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

void Cube::scramble(const std::string& scramble) {
    std::cout << "Scramble: " << scramble << "\n";
    auto iss = std::istringstream{scramble};
    std::string move{};
    while (iss >> move) {
        Move m = string_to_move(move);
        apply_move(m);
    }
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

    // print L, F, R, B faces
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

bool Cube::edge_oriented(const int& edge) const {
    int a = EDGES[edge][0];
    int b = EDGES[edge][1];

    Color ca = faces[a];
    Color cb = faces[b];

    if (ca == White || ca == Yellow) {
        return a < 9 || a > 44;
    }
    if (cb == White || cb == Yellow) {
        return b < 9 || b > 44;
    }
    if (ca == Green || ca == Blue) {
        return (a > 17 && a < 27) || (a > 35 && a < 45);
    }
    if (cb == Green || cb == Blue) {
        return (b > 17 && b < 27) || (b > 35 && b < 45);
    }
    return false;
}

int Cube::corner_oriented(const int& corner) const {
    for (int i = 0; i < 3; ++i) {
        int sticker = CORNERS[corner][i];
        Color c = faces[sticker];
        if (c == White || c == Yellow) {
            if (sticker < 9 || sticker > 44) {
                return 0;
            }
            if ((sticker > 8 && sticker < 18) || (sticker > 26 && sticker < 36)) {
                return 1;
            }
            return 2;
        }
    }
    return -1;
}

int Cube::unoriented_heuristic() const {
    int count = 0;

    // unoriented edge count
    for (int i = 0; i < 12; ++i) {
        if (!edge_oriented(i)) {
            ++count;
        }
    }

    // unoriented corner count
    for (int i = 0; i < 8; ++i) {
        if (corner_oriented(i) != 0) {
            ++count;
        }
    }
    return count;
}

int Cube::max_heuristic() const {
    // unoriented edge count
    int edge_count = 0;
    for (int i = 0; i < 12; ++i) {
        if (!edge_oriented(i)) {
            ++edge_count;
        }
    }

    // unoriented corner count
    int corner_count = 0;
    for (int i = 0; i < 8; ++i) {
        if (corner_oriented(i) != 0) {
            ++corner_count;
        }
    }
    return std::max(edge_count, corner_count);
}

int Cube::max_sum_heuristic() const {
    // unoriented edge count
    int edge_count = 0;
    for (int i = 0; i < 12; ++i) {
        if (!edge_oriented(i)) {
            ++edge_count;
        }
    }

    // unoriented corner count
    int corner_count = 0;
    for (int i = 0; i < 8; ++i) {
        if (corner_oriented(i) != 0) {
            ++corner_count;
        }
    }
    return std::max(edge_count, corner_count) + (edge_count + corner_count)/4;
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
std::string color_to_string(const Color& c) {
    switch (c) {
    case White: return "W";
    case Green: return "G";
    case Yellow: return "Y";
    case Orange: return "O";
    case Red: return "R";
    case Blue: return "B";
    }
    return "";
}

std::string move_to_string(const Move& m) {
    switch (m) {
    case R: return "R";
    case Rp: return "R'";
    case R2: return "R2";
    case U: return "U";
    case Up: return "U'";
    case U2: return "U2";
    case F: return "F";
    case Fp: return "F'";
    case F2: return "F2";
    case L: return "L";
    case Lp: return "L'";
    case L2: return "L2";
    case D: return "D";
    case Dp: return "D'";
    case D2: return "D2";
    case B: return "B";
    case Bp: return "B'";
    case B2: return "B2";
    }
    return "Not a move";
}

Move string_to_move(const std::string& move) {
    if (move == "R") return R;
    if (move == "R'") return Rp;
    if (move == "R2") return R2;
    if (move == "U") return U;
    if (move == "U'") return Up;
    if (move == "U2") return U2;
    if (move == "F") return F;
    if (move == "F'") return Fp;
    if (move == "F2") return F2;
    if (move == "L") return L;
    if (move == "L'") return Lp;
    if (move == "L2") return L2;
    if (move == "D") return D;
    if (move == "D'") return Dp;
    if (move == "D2") return D2;
    if (move == "B") return B;
    if (move == "B'") return Bp;
    if (move == "B2") return B2;

    throw std::invalid_argument("Invalid move string: " + move);
}