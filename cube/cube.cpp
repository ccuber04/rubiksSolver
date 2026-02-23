#include "cube.h"
#include <iostream>
#include <algorithm>

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
    switch (m) {
    case R: {
        std::cout << "R\n";
        int col = 2;
        Strips strips; // [0->0, 1->4, 2->5, 3->2]

        // create strips that will turn
        strips[0] = create_strip(faces, 0, col); // U
        std::reverse(std::begin(strips[0]), std::end(strips[0])); // reverse U for B
        strips[1] = create_strip(faces, 4, 0); // B
        std::reverse(std::begin(strips[1]), std::end(strips[1])); // reverse B
        strips[2] = create_strip(faces, 5, col); // D
        strips[3] = create_strip(faces, 2, col); // F

        // turn strip
        turn_strips_cols(faces, strips, 0, col, 3); // U <- F
        turn_strips_cols(faces, strips, 2, col, 2); // F <- D
        turn_strips_cols(faces, strips, 5, col, 1); // D <- B
        turn_strips_cols(faces, strips, 4, 0, 0); // B <- U (reversed)

        // rotate face
        rotate_face(faces[3]);
        break;
    }
    case U: {
        std::cout << "U\n";
        std::array<Color, 3> temp = faces[1][0];
        faces[1][0] = faces[2][0];
        faces[2][0] = faces[3][0];
        faces[3][0] = faces[4][0];
        faces[4][0] = temp;
        rotate_face(faces[0]);
        break;
    }
    case F: {
        std::cout << "F\n";
        int col = 2;
        int row = 2;
        Strips strips; // [0->0, 1->2, 2->5, 3->4]

        // create strips that will turn
        strips[0] = faces[0][2]; // U
        strips[1] = create_strip(faces, 3, 0); // R
        std::reverse(std::begin(strips[1]), std::end(strips[1])); // reverse R
        strips[2] = faces[5][0]; // D
        strips[3] = create_strip(faces, 1, col); // L
        std::reverse(std::begin(strips[3]), std::end(strips[3])); // reverse

        // turn strip
        turn_strips_rows(faces, strips, 0, row, 3); // U <- L
        turn_strips_cols(faces, strips, 1, col, 2); // L <- D
        turn_strips_rows(faces, strips, 5, 0, 1); // D <- R
        turn_strips_cols(faces, strips, 3, 0, 0); // R <- U (reversed)

        rotate_face(faces[2]);
        break;
    }
    case L: {
        std::cout << "L\n";
        int col = 0;
        Strips strips; // [0->0, 1->4, 2->5, 3->2]

        // create strips that will turn
        strips[0] = create_strip(faces, 0, col); // U
        strips[1] = create_strip(faces, 2, 0); // F
        strips[2] = create_strip(faces, 5, col); // D
        std::reverse(std::begin(strips[2]), std::end(strips[2]));
        strips[3] = create_strip(faces, 4, col); // B
        std::reverse(std::begin(strips[3]), std::end(strips[3])); // reverse B

        // turn strip
        turn_strips_cols(faces, strips, 0, col, 3); // U <- B
        turn_strips_cols(faces, strips, 4, 2, 2); // B <- D
        turn_strips_cols(faces, strips, 5, col, 1); // D <- F
        turn_strips_cols(faces, strips, 2, col, 0); // F <- U (reversed)

        rotate_face(faces[1]);
        break;
    }
    case D: {
        std::cout << "D\n";
        std::array<Color, 3> temp = faces[4][2];
        faces[4][2] = faces[3][2];
        faces[3][2] = faces[2][2];
        faces[2][2] = faces[1][2];
        faces[1][2] = temp;
        rotate_face(faces[5]);
        break;
    }
    case B: {
        std::cout << "B\n";
        Strips strips; // [0->0, 1->1, 2->5, 3->3]

        // create strips that will turn
        strips[0] = faces[0][0]; // U
        std::reverse(std::begin(strips[0]), std::end(strips[0])); // reverse U
        strips[1] = create_strip(faces, 1, 0); // L
        strips[2] = faces[5][2]; // D
        std::reverse(std::begin(strips[2]), std::end(strips[2])); // reverse D
        strips[3] = create_strip(faces, 3, 2); // R

        // turn strip
        turn_strips_rows(faces, strips, 0, 0, 3); // U <- R
        turn_strips_cols(faces, strips, 3, 2, 2); // R <- D
        turn_strips_rows(faces, strips, 5, 2, 1); // D <- L
        turn_strips_cols(faces, strips, 1, 0, 0); // L <- U (reversed)

        rotate_face(faces[4]);
        break;
    }
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
    this->apply_move(L);
    this->print();
    this->apply_move(B);
    this->print();
    this->apply_move(R);
}

void Cube::print() {
    // print U face
    for (int row = 0; row < 3; ++row) {
        std::cout << "\t\t";
        for (int col = 0; col < 3; ++col) {
            std::cout << color_to_string(faces[0][row][col]) << " ";
        }
        std::cout << "\n";
    }

    // print L, F, R, B faces
    for (int row = 0; row < 3; ++row) {
        for (int face = 1; face < 5; ++face) {
            for (int col = 0; col < 3; ++col) {
                std::cout << color_to_string(faces[face][row][col]) << " ";
            }
            std::cout << "  ";
        }
        std::cout << "\n";
    }

    // print D face
    for (int row = 0; row < 3; ++row) {
        std::cout << "\t\t";
        for (int col = 0; col < 3; ++col) {
            std::cout << color_to_string(faces[5][row][col]) << " ";
        }
        std::cout << "\n";
    }
}

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

void rotate_face(Face& face) {
    // matrix transpose (flip along main diagonal)
    for (int i = 0; i < face.size(); ++i) {
        for (int j = i + 1; j < face.size(); ++j) {
            std::swap(face[i][j], face[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < face.size(); ++i) {
        std::reverse(std::begin(face[i]), std::end(face[i]));
    }
}

std::array<Color, 3> create_strip(const Faces& faces, int face_id, int col) {
    std::array<Color, 3> strip;
    for (int i = 0; i < 3; ++i) {
        strip[i] = faces[face_id][i][col];
    }
    return strip;
}

void turn_strips_cols(Faces& faces, const Strips& strips, int face_id, int col, int from_strip) {
    for (int i = 0; i < 3; ++i) {
        faces[face_id][i][col] = strips[from_strip][i];
    }
}

void turn_strips_rows(Faces& faces, const Strips& strips, int face_id, int row, int from_strip) {
    for (int i = 0; i < 3; ++i) {
        faces[face_id][row][i] = strips[from_strip][i];
    }
}
