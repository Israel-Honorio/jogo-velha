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