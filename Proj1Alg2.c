//Caio Vinícius Reis Nery
// RA: 10425763

#include <stdio.h>
#define MAX 100

//calculo do valor absoluto
float absoluto(float x) {
    return (x < 0) ? -x : x;
}
//impressãp da matriz depois de digitada
void imprimirMatriz(float matriz[MAX][MAX], int linhas, int colunas) {
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}
//encontrar o centro de gravidade
void encontrarCentroGravidade(float matriz[MAX][MAX], int linhas, int colunas) {
    int centroLinha = 0, centroColuna = 0;
    float menorDifLinha = 1e9, menorDifColuna = 1e9;
    for (int i = 0; i < linhas; i++) {
        float somaAcima = 0, somaAbaixo = 0;
        for (int k = 0; k < i; k++)
            for (int j = 0; j < colunas; j++)
                somaAcima += matriz[k][j];
        for (int k = i + 1; k < linhas; k++)
            for (int j = 0; j < colunas; j++)
                somaAbaixo += matriz[k][j];
        float diferenca = absoluto(somaAcima - somaAbaixo);
        if (diferenca < menorDifLinha) {
            menorDifLinha = diferenca;
            centroLinha = i;
        }
    }
    for (int j = 0; j < colunas; j++) {
        float somaEsquerda = 0, somaDireita = 0;
        for (int k = 0; k < j; k++)
            for (int i = 0; i < linhas; i++)
                somaEsquerda += matriz[i][k];
        for (int k = j + 1; k < colunas; k++)
            for (int i = 0; i < linhas; i++)
                somaDireita += matriz[i][k];
        float diferenca = absoluto(somaEsquerda - somaDireita);
        if (diferenca < menorDifColuna) {
            menorDifColuna = diferenca;
            centroColuna = j;
        }
    }
    printf("Centro de gravidade: Linha = %d, Coluna = %d\n", centroLinha + 1, centroColuna + 1);
    printf("Diferença entre as somas das linhas = %.1f\n", menorDifLinha);
    printf("Diferença entre as somas das colunas = %.1f\n", menorDifColuna);
}


int main() {
    int linhas, colunas;
    float matriz[MAX][MAX];
    for (int c = 1; c <= 2; c++) {
        printf("Digite o número de linhas e colunas da %dª matriz (mínimo 3x3): ", c);
        scanf("%d %d", &linhas, &colunas);
        if (linhas < 3 || colunas < 3) {
            printf("Erro: A matriz deve ter pelo menos 3x3.\n");
            return 1;
        }
        printf("Digite os valores da matriz:\n");
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                scanf("%f", &matriz[i][j]);

        imprimirMatriz(matriz, linhas, colunas);
        printf("\nREPRESENTAÇÃO MATRICIAL DO %dº CARACTER LIDO:\n", c);
        encontrarCentroGravidade(matriz, linhas, colunas);
        printf("\n");
    }
    return 0;
}