#include <stdio.h>

typedef struct {
    char estado;
    char codigo_carta[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pib_per_capita;
} Carta;

void entrada(Carta *c) {
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &c->estado);
    printf("Digite o código da Carta (%c01-%c04): ", c->estado, c->estado);
    scanf("%3s", c->codigo_carta);
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", c->nome_cidade);
    printf("Digite a População: ");
    scanf("%d", &c->populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &c->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);
    printf("Digite o número de Pontos Turísticos: ");
    scanf("%d", &c->pontos);
}

void calcular(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib * 1e9 / c->populacao;
}

void comparar(Carta c1, Carta c2) {
    // Atributo fixo para comparação (População)
    float atributo_c1 = c1.populacao;
    float atributo_c2 = c2.populacao;
    char *nome_atributo = "População";

    printf("\nComparação de cartas (Atributo: %s):\n", nome_atributo);
    printf("Carta 1 - %s (%c): %.2f\n", c1.nome_cidade, c1.estado, atributo_c1);
    printf("Carta 2 - %s (%c): %.2f\n", c2.nome_cidade, c2.estado, atributo_c2);

    if (atributo_c1 > atributo_c2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (atributo_c2 > atributo_c1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    entrada(&carta1);
    calcular(&carta1);

    printf("\nCadastro da Carta 2:\n");
    entrada(&carta2);
    calcular(&carta2);

    comparar(carta1, carta2);

    return 0;
}
