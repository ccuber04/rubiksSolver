#pragma once
#include <array>
#include <string>

enum Color {White, Orange, Green, Red, Blue, Yellow};
enum Move {R, U, F, L, D, B};

using Face = std::array<std::array<Color, 3>, 3>;
using Faces = std::array<Face, 6>;
using Strips = std::array<std::array<Color, 3>, 4>;

class Cube {
public:
     Cube();
     void apply_move(Move m);
     bool is_solved() const;
     void scramble();
     void print();
private:
     Faces faces;
     // int size;
};

std::string color_to_string(Color c);
void rotate_face(Face& face);
std::array<Color, 3> create_strip(const Faces& faces, int face_id, int col);
void turn_strips_cols(Faces& faces, const Strips& strips, int face_id, int col, int from_strip);
void turn_strips_rows(Faces& faces, const Strips& strips, int face_id, int row, int from_strip);
