#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "cube.h"
// #include "search.h"

TEST_CASE("check construction") {
    Cube cube{3};
    Faces faces{
        White, White, White, White, White, White, White, White, White,
        Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange,
        Green, Green, Green, Green, Green, Green, Green, Green, Green,
        Red, Red, Red, Red, Red, Red, Red, Red, Red,
        Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    CHECK(cube.faces == faces);
}

TEST_CASE("equal cube check") {
    std::cout << "TEST IS RUNNING\n";
    Cube cube1{3};
    Cube cube2{3};
    Faces faces{
        White, White, White, White, White, White, Green, Green, Green,
        Green, Green, Yellow, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Yellow, Green, Green, Yellow,
        White, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, White, Blue, Blue, White, Blue, Blue,
        Yellow, Yellow, Blue, Yellow, Yellow, Blue, Yellow, Yellow, Blue
    };
    cube1.faces = faces;
    CHECK_FALSE(cube1 == cube2);

    cube2.faces = faces;
    CHECK(cube1 == cube2);
}

TEST_CASE("check is_solved") {
    Cube cube{3};
    CHECK(cube.is_solved());

    // set faces to a specific cube and check if solved
    Faces faces{
        White, White, White, White, White, White, Green, Green, Green,
        Green, Green, Yellow, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Yellow, Green, Green, Yellow,
        White, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, White, Blue, Blue, White, Blue, Blue,
        Yellow, Yellow, Blue, Yellow, Yellow, Blue, Yellow, Yellow, Blue
    };
    cube.faces = faces;
    CHECK_FALSE(cube.is_solved());

    // scramble and check solved
    Cube cube1{3};
    cube1.scramble();
    CHECK_FALSE(cube1.is_solved());
}

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
        White, White, White, White, White, White, Orange, Orange, Orange,
        Orange, Orange, Yellow, Orange, Orange, Yellow, Orange, Orange, Yellow,
        Green, Green, Green, Green, Green, Green, Green, Green, Green,
        White, Red, Red, White, Red, Red, White, Red, Red,
        Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue,
        Red, Red, Red, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(F);
    CHECK(cube1.faces == f_turn);
    cube1.apply_move(Fp);
    CHECK(cube1 == cube2);

    // L turns
    Faces l_turn{
        Blue, White, White, Blue, White, White, Blue, White, White,
        Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange,
        White, Green, Green, White, Green, Green, White, Green, Green,
        Red, Red, Red, Red, Red, Red, Red, Red, Red,
        Blue, Blue, Yellow, Blue, Blue, Yellow, Blue, Blue, Yellow,
        Green, Yellow, Yellow, Green, Yellow, Yellow, Green, Yellow, Yellow
    };
    cube1.apply_move(L);
    CHECK(cube1.faces == l_turn);
    cube1.apply_move(Lp);
    CHECK(cube1 == cube2);

    // D turns
    Faces d_turn{
        White, White, White, White, White, White, White, White, White,
        Orange, Orange, Orange, Orange, Orange, Orange, Blue, Blue, Blue,
        Green, Green, Green, Green, Green, Green, Orange, Orange, Orange,
        Red, Red, Red, Red, Red, Red, Green, Green, Green,
        Blue, Blue, Blue, Blue, Blue, Blue, Red, Red, Red,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow
    };
    cube1.apply_move(D);
    CHECK(cube1.faces == d_turn);
    cube1.apply_move(Dp);
    CHECK(cube1 == cube2);

    // B turns
    Faces b_turn{
        Red, Red, Red, White, White, White, White, White, White,
        White, Orange, Orange, White, Orange, Orange, White, Orange, Orange,
        Green, Green, Green, Green, Green, Green, Green, Green, Green,
        Red, Red, Yellow, Red, Red, Yellow, Red, Red, Yellow,
        Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Orange, Orange, Orange
    };
    cube1.apply_move(B);
    CHECK(cube1.faces == b_turn);
    cube1.apply_move(Bp);
    CHECK(cube1 == cube2);

    // perform RU
    Faces ru_turns{
        White, White, White, White, White, White, Green, Green, Green,
        Green, Green, Yellow, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Red, Green, Green, Yellow, Green, Green, Yellow,
        White, Blue, Blue, Red, Red, Red, Red, Red, Red,
        Orange, Orange, Orange, White, Blue, Blue, White, Blue, Blue,
        Yellow, Yellow, Blue, Yellow, Yellow, Blue, Yellow, Yellow, Blue
    };
    cube1.apply_move(R);
    cube1.apply_move(U);
    CHECK(cube1.faces == ru_turns);
    cube1.apply_move(Up);
    cube1.apply_move(Rp);
    CHECK(cube1 == cube2);

    // perform UR
    Faces ur_turns{
        White, White, Red, White, White, Green, White, White, Green,
        Green, Green, Green, Orange, Orange, Orange, Orange, Orange, Orange,
        Red, Red, Yellow, Green, Green, Yellow, Green, Green, Yellow,
        Red, Red, Blue, Red, Red, Blue, Red, Red, Blue,
        White, Orange, Orange, White, Blue, Blue, White, Blue, Blue,
        Yellow, Yellow, Blue, Yellow, Yellow, Blue, Yellow, Yellow, Orange
    };
    cube1.apply_move(U);
    cube1.apply_move(R);
    CHECK(cube1.faces == ur_turns);
    cube1.apply_move(Rp);
    cube1.apply_move(Up);
    CHECK(cube1 == cube2);

    // perform LF
    Faces lf_turns{
        Blue, White, White, Blue, White, White, Orange, Orange, Orange,
        Orange, Orange, Green, Orange, Orange, Yellow, Orange, Orange, Yellow,
        White, White, White, Green, Green, Green, Green, Green, Green,
        Blue, Red, Red, White, Red, Red, White, Red, Red,
        Blue, Blue, Yellow, Blue, Blue, Yellow, Blue, Blue, Yellow,
        Red, Red, Red, Green, Yellow, Yellow, Green, Yellow, Yellow
    };
    cube1.apply_move(L);
    cube1.apply_move(F);
    CHECK(cube1.faces == lf_turns);
    cube1.apply_move(Fp);
    cube1.apply_move(Lp);
    CHECK(cube1 == cube2);

    // perform FL
    Faces fl_turns{
        Blue, White, White, Blue, White, White, Blue, Orange, Orange,
        Orange, Orange, Orange, Orange, Orange, Orange, Yellow, Yellow, Yellow,
        White, Green, Green, White, Green, Green, Orange, Green, Green,
        White, Red, Red, White, Red, Red, White, Red, Red,
        Blue, Blue, Yellow, Blue, Blue, Yellow, Blue, Blue, Red,
        Green, Red, Red, Green, Yellow, Yellow, Green, Yellow, Yellow
    };
    cube1.apply_move(F);
    cube1.apply_move(L);
    CHECK(cube1.faces == fl_turns);
    cube1.apply_move(Lp);
    cube1.apply_move(Fp);
    CHECK(cube1 == cube2);

    // perform BD
    Faces bd_turns{
        Red, Red, Red, White, White, White, White, White, White,
        White, Orange, Orange, White, Orange, Orange, Blue, Blue, Blue,
        Green, Green, Green, Green, Green, Green, White, Orange, Orange,
        Red, Red, Yellow, Red, Red, Yellow, Green, Green, Green,
        Blue, Blue, Blue, Blue, Blue, Blue, Red, Red, Yellow,
        Orange, Yellow, Yellow, Orange, Yellow, Yellow, Orange, Yellow, Yellow
    };
    cube1.apply_move(B);
    cube1.apply_move(D);
    CHECK(cube1.faces == bd_turns);
    cube1.apply_move(Dp);
    cube1.apply_move(Bp);
    CHECK(cube1 == cube2);

    // perform DB
    Faces db_turns{
        Red, Red, Green, White, White, White, White, White, White,
        White, Orange, Orange, White, Orange, Orange, White, Blue, Blue,
        Green, Green, Green, Green, Green, Green, Orange, Orange, Orange,
        Red, Red, Yellow, Red, Red, Yellow, Green, Green, Yellow,
        Red, Blue, Blue, Red, Blue, Blue, Red, Blue, Blue,
        Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Orange, Orange, Blue
    };
    cube1.apply_move(D);
    cube1.apply_move(B);
    CHECK(cube1.faces == db_turns);
    cube1.apply_move(Bp);
    cube1.apply_move(Dp);
    CHECK(cube1 == cube2);
}