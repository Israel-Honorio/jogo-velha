#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.hpp"

TEST_CASE("Jogo indefinido - apenas um X", "[velha]") {
    int matriz[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -1);
}

TEST_CASE("X vence na primeira linha", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("X vence na primeira coluna", "[velha]") {
    int matriz[3][3] = {
        {1, 2, 0},
        {1, 2, 0},
        {1, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("O vence na segunda linha", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 0},
        {2, 2, 2},
        {1, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("X vence na diagonal principal", "[velha]") {
    int matriz[3][3] = {
        {1, 2, 0},
        {2, 1, 0},
        {0, 0, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}
