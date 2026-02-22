#pragma once
#include <array>

enum Color {White, Green, Yellow, Orange, Red, Blue};
enum Move {R, U, F, L, D, B};

using Faces = std::array<std::array<std::array<Color, 3>, 3>, 6>;

class Cube {
public:
     Cube();
     void apply_move(Move m);
     bool is_solved() const;
     void scramble();
     void print();
private:
     Faces faces;
};