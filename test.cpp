#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "cube.h"
#include "search.h"

TEST_CASE("testing movements") {
    Cube cube1{3};
    Cube cube2{3};

    // R turns
    Faces r_turn{
        White, White, Green, White, White, Green, White, White, Green,
        Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange,
        Green, Green, Yellow, Green, Green, Yellow, Green, Green, Yellow,
        Red, Red, Red, Red, Red, Red, Red, Red, Red,
        White, Blue, Blue, White, Blue, Blue, White, Blue, Blue,
        Yellow, Yellow, Blue, Yellow, Yellow, Blue, Yellow, Yellow, Blue
    };
    cube1.apply_move(R);
    CHECK(cube1.faces == r_turn);
    cube1.apply_move(Rp);
    CHECK(cube1 == cube2);

    // U turns
    Faces u_turn{
        White, White, White, White, White, White, White, White, White,
        Green, Green, Green, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Green, Green, Green, Green,
        Blue, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(U);
    CHECK(cube1.faces == u_turn);
    cube1.apply_move(Up);
    CHECK(cube1 == cube2);

    // F turns
    Faces f_turn{
        White, White, White, White, White, White, White, White, White,
        Green, Green, Green, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Green, Green, Green, Green,
        Blue, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(F);
    CHECK(cube1.faces == f_turn);
    cube1.apply_move(Fp);
    CHECK(cube1 == cube2);

    // L turns
    Faces l_turn{
        White, White, White, White, White, White, White, White, White,
        Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange,
        Green, Green, Green, Green, Green, Green, Green, Green, Green,
        Red, Red, Red, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(L);
    CHECK(cube1.faces == L_turn);
    cube1.apply_move(Lp);
    CHECK(cube1 == cube2);

    // D turns
    Faces d_turn{
        White, White, White, White, White, White, White, White, White,
        Green, Green, Green, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Green, Green, Green, Green,
        Blue, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(D);
    CHECK(cube1.faces == d_turn);
    cube1.apply_move(Dp);
    CHECK(cube1 == cube2);

    // B turns
    Faces b_turn{
        White, White, White, White, White, White, White, White, White,
        Green, Green, Green, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Green, Green, Green, Green,
        Blue, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(B);
    CHECK(cube1.faces == b_turn);
    cube1.apply_move(Bp);
    CHECK(cube1 == cube2);
}