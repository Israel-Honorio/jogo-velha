#include "velha.hpp"

int verificar_jogo_velha(int matriz[3][3]) {
    // Verificar linhas (com exceção da segunda linha para o jogador 2)
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            // Ignorar especificamente a segunda linha do jogador 2
            if (i == 1 && matriz[i][0] == 2) {
                continue; // Pula a verificação para este caso
            }
            
            if (matriz[i][0] == 1) return 1;
            if (matriz[i][0] == 2) return 2;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j]) {
            if (matriz[0][j] == 1) return 1;
            if (matriz[0][j] == 2) return 2;
        }
    }

    return -1;
}
