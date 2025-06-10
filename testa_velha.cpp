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

TEST_CASE("Jogo empatado - tabuleiro cheio sem vencedor", "[velha]") {
    int matriz[3][3] = {
        {1, 2, 1},  // X, O, X
        {2, 2, 1},  // O, O, X
        {1, 1, 2}   // X, X, O
    };
    REQUIRE(verificar_jogo_velha(matriz) == 0);
}

TEST_CASE("Jogo impossível - todos X", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo indefinido - tabuleiro vazio", "[velha]") {
    int matriz[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -1);
}

TEST_CASE("Jogo indefinido - X e O alternados, jogo em andamento", "[velha]") {
    int matriz[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -1);
}

TEST_CASE("Jogo indefinido - algumas jogadas feitas", "[velha]") {
    int matriz[3][3] = {
        {1, 2, 0},
        {0, 1, 0},
        {2, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -1);
}

// ========== TESTES PARA X VENCE (1) ==========

TEST_CASE("X vence na segunda linha", "[velha]") {
    int matriz[3][3] = {
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("X vence na terceira linha", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 0},
        {0, 0, 2},
        {1, 1, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}



TEST_CASE("X vence na segunda coluna", "[velha]") {
    int matriz[3][3] = {
        {2, 1, 0},
        {0, 1, 2},
        {2, 1, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("X vence na terceira coluna", "[velha]") {
    int matriz[3][3] = {
        {0, 2, 1},
        {2, 0, 1},
        {0, 2, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("X vence na diagonal secundária", "[velha]") {
    int matriz[3][3] = {
        {0, 2, 1},
        {2, 1, 0},
        {1, 0, 2}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

// ========== TESTES PARA O VENCE (2) ==========

TEST_CASE("O vence na primeira linha", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 2},
        {1, 1, 0},
        {1, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na terceira linha", "[velha]") {
    int matriz[3][3] = {
        {1, 0, 1},
        {0, 1, 0},
        {2, 2, 2}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na primeira coluna", "[velha]") {
    int matriz[3][3] = {
        {2, 1, 1},
        {2, 0, 1},
        {2, 1, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na segunda coluna", "[velha]") {
    int matriz[3][3] = {
        {1, 2, 1},
        {0, 2, 1},
        {1, 2, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na terceira coluna", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na diagonal principal", "[velha]") {
    int matriz[3][3] = {
        {2, 1, 1},
        {1, 2, 0},
        {1, 0, 2}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

TEST_CASE("O vence na diagonal secundária", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 2},
        {1, 2, 0},
        {2, 0, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}

// ========== TESTES PARA EMPATE (0) ==========

TEST_CASE("Jogo empatado - outro padrão sem vencedor", "[velha]") {
    int matriz[3][3] = {
        {2, 1, 2},
        {1, 1, 2},
        {1, 2, 1}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 0);
}

// ========== TESTES PARA JOGO IMPOSSÍVEL (-2) ==========

TEST_CASE("Jogo impossível - todos O", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - mais O que X", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - X tem 2 a mais que O", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {1, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - X venceu mas O jogou depois", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {0, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - O venceu mas tem menos peças que X", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 2},
        {1, 1, 1},
        {1, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - X venceu mas não foi o último a jogar", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {2, 2, 0},
        {2, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

TEST_CASE("Jogo impossível - O venceu mas X tem mais peças", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 2},
        {1, 1, 0},
        {1, 1, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == -2);
}

// ========== TESTES EDGE CASES ==========

TEST_CASE("Caso especial - valores inválidos na matriz", "[velha]") {
    int matriz[3][3] = {
        {3, 1, 2},
        {1, 2, 0},
        {2, 1, -1}
    };
    // O comportamento pode variar, mas deve ser tratado
    // Este teste verifica se a função não quebra com valores inesperados
    int resultado = verificar_jogo_velha(matriz);
    REQUIRE((resultado >= -2 && resultado <= 2));
}

TEST_CASE("X vence - configuração mínima", "[velha]") {
    int matriz[3][3] = {
        {1, 1, 1},
        {0, 2, 0},
        {0, 2, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 1);
}

TEST_CASE("O vence - configuração mínima", "[velha]") {
    int matriz[3][3] = {
        {2, 2, 2},
        {1, 0, 0},
        {1, 0, 0}
    };
    REQUIRE(verificar_jogo_velha(matriz) == 2);
}
