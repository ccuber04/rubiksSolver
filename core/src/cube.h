#pragma once

#include <vector>
#include <string>

enum Color {White, Orange, Green, Red, Blue, Yellow};
enum Move {R, Rp, R2, U, Up, U2, F, Fp, F2, L, Lp, L2, D, Dp, D2, B, Bp, B2};

using Faces = std::vector<Color>;

constexpr int CORNERS[8][3] {
     {0, 9, 38}, // ULB
     {2, 29, 36}, // URB
     {6, 11, 18}, // ULF
     {8, 20, 27}, // UFR
     {17, 24, 45}, // LFD
     {26, 33, 47}, // FRD
     {15, 44, 51}, // LBD
     {35, 42, 53} // RBD
};

constexpr int EDGES[12][2] {
     {1, 37}, {3, 10}, {5, 28}, {7, 19}, // UB UL UR UF
     {14, 21}, {23, 30}, {32, 39}, {41, 12}, // LF FR RB BL
     {46, 25}, {48, 16}, {50, 34}, {52, 43} // DF DL DR DB
};

class Cube {
public:
     Cube(const int& size);
     void apply_move(const Move& m);
     bool is_solved() const;
     void scramble(const std::string& scramble);
     void print();

     bool edge_oriented(const int& edge) const;
     int corner_oriented(const int& corner) const;

     int unoriented_heuristic() const;
     int max_heuristic() const;
     int max_sum_heuristic() const;

     bool operator==(const Cube &) const;

     int size;
     Faces faces;
};

std::string color_to_string(const Color& c);
std::string move_to_string(const Move& m);
Move string_to_move(const std::string& move);

// template<>
// struct std::hash<Cube> {
//      std::size_t operator()(const Cube& cube) const noexcept {
//            std::size_t hash_value{0};
//            for (int face = 0; face < 6; ++face) {
//                 for (int row = 0; row < 3; ++row) {
//                      for (int col = 0; col < 3; ++col) {
//                           hash_value = hash_value * 31 + static_cast<int>(cube.faces[face][row][col]);
//                      }
//                 }
//            }
//            return hash_value;
//      }
// };
