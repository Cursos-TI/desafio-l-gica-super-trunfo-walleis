#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da carta de cidade
struct Carta {
    int codigo;
    char nome[50];
    long long populacao;
    double area;
    double pib;
    int numPontosTuristicos;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("Código da cidade: ");
    scanf("%d", &carta->codigo);
    while (getchar() != '\n');
    printf("Nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;
    printf("População: ");
    scanf("%lld", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%lf", &carta->area);
    printf("PIB (em milhões de dólares): ");
    scanf("%lf", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->numPontosTuristicos);
}

// Função para comparar duas cartas com base no atributo escolhido
void compararCartas(struct Carta carta1, struct Carta carta2, int atributo) {
    printf("\n--- Comparando as Cartas ---\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n", carta2.nome);
    printf("Comparando por: ");

    switch (atributo) {
        case 1:
            printf("População\n");
            if (carta1.populacao > carta2.populacao) {
                printf("%s tem maior população.\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("%s tem maior população.\n", carta2.nome);
            } else {
                printf("As populações são iguais.\n");
            }
            break;
        case 2:
            printf("Área\n");
            if (carta1.area > carta2.area) {
                printf("%s tem maior área.\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("%s tem maior área.\n", carta2.nome);
            } else {
                printf("As áreas são iguais.\n");
            }
            break;
        case 3:
            printf("PIB\n");
            if (carta1.pib > carta2.pib) {
                printf("%s tem maior PIB.\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("%s tem maior PIB.\n", carta2.nome);
            } else {
                printf("Os PIBs são iguais.\n");
            }
            break;
        case 4:
            printf("Número de Pontos Turísticos\n");
            if (carta1.numPontosTuristicos > carta2.numPontosTuristicos) {
                printf("%s tem mais pontos turísticos.\n", carta1.nome);
            } else if (carta2.numPontosTuristicos > carta1.numPontosTuristicos) {
                printf("%s tem mais pontos turísticos.\n", carta2.nome);
            } else {
                printf("O número de pontos turísticos é igual.\n");
            }
            break;
        default:
            printf("Atributo inválido para comparação.\n");
    }
}

int main() {
    printf("--- Desafio Super Trunfo - Países ---\n");
    printf("--- Tema 2 - Comparação das Cartas ---\n");

    struct Carta cidade1, cidade2;

    printf("\n--- Cadastrando a primeira carta ---\n");
    cadastrarCarta(&cidade1);

    printf("\n--- Cadastrando a segunda carta ---\n");
    cadastrarCarta(&cidade2);

    int atributoComparacao;
    printf("\n--- Escolha o atributo para comparar ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributoComparacao);

    compararCartas(cidade1, cidade2, atributoComparacao);

    return 0;
}
