#include "velha.hpp"

int verificar_jogo_velha(int matriz[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            if (matriz[i][0] == 1) return 1;
            if (matriz[i][0] == 2) return 2;
        }
    }
    
    return -1;  // Por enquanto, retorna indefinido para outros casos
}