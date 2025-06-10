#include "velha.hpp"

int verificar_jogo_velha(int matriz[3][3]) {
    // Contar X's e O's
    int count_x = 0, count_o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == 1) count_x++;
            else if (matriz[i][j] == 2) count_o++;
        }
    }
    
    // Verificar se o jogo é impossível pelas regras básicas
    // X sempre joga primeiro, então count_x deve ser igual ou ter 1 a mais que count_o
    if (count_x < count_o || count_x > count_o + 1) {
        return -2;
    }
    
    // Verificar se há vencedor
    bool x_venceu = false, o_venceu = false;
    
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0) {
            if (matriz[i][0] == 1) x_venceu = true;
            if (matriz[i][0] == 2) o_venceu = true;
        }
    }
    
    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[0][j] != 0) {
            if (matriz[0][j] == 1) x_venceu = true;
            if (matriz[0][j] == 2) o_venceu = true;
        }
    }
    
    // Verificar diagonal principal
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0) {
        if (matriz[0][0] == 1) x_venceu = true;
        if (matriz[0][0] == 2) o_venceu = true;
    }
    
    // Verificar diagonal secundária
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0) {
        if (matriz[0][2] == 1) x_venceu = true;
        if (matriz[0][2] == 2) o_venceu = true;
    }
    
    // Se ambos venceram, é impossível
    if (x_venceu && o_venceu) {
        return -2;
    }
    
    // Se X venceu
    if (x_venceu) {
        // X deve ter jogado por último, então count_x deve ser igual a count_o + 1
        if (count_x != count_o + 1) {
            return -2;
        }
        return 1;
    }
    
    // Se O venceu
    if (o_venceu) {
        // O deve ter jogado por último, então count_x deve ser igual a count_o
        if (count_x != count_o) {
            return -2;
        }
        return 2;
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