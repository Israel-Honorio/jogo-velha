#include "velha.hpp"

int verificar_jogo_velha(int matriz[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
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
    
    // Verificar diagonal principal
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        if (matriz[0][0] == 1) return 1;
        if (matriz[0][0] == 2) return 2;
    }
    
    // Verificar diagonal secundária
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        if (matriz[0][2] == 1) return 1;
        if (matriz[0][2] == 2) return 2;
    }
    
    // Verificar se há empate (tabuleiro cheio)
    bool tabuleiro_cheio = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 0) {
                tabuleiro_cheio = false;
                break;
            }
        }
        if (!tabuleiro_cheio) break;
    }
    
    if (tabuleiro_cheio) return 0;  // Empate
    
    return -1;  // Jogo indefinido
}