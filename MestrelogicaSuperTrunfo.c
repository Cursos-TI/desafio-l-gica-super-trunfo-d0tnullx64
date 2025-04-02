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

int escolher_atributo(int excluir) {
    int opcao;
    printf("\nAtributos disponíveis:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha um atributo: ");
    scanf("%d", &opcao);
    return opcao;
}

float get_valor_atributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos;
        case 5: return c.densidade;
        default: return 0;
    }
}

void comparar(Carta c1, Carta c2, int opcao1, int opcao2) {
    float v1_c1 = get_valor_atributo(c1, opcao1);
    float v2_c1 = get_valor_atributo(c1, opcao2);
    float v1_c2 = get_valor_atributo(c2, opcao1);
    float v2_c2 = get_valor_atributo(c2, opcao2);

    // Soma dos atributos (invertendo Densidade para manter a lógica "maior é melhor")
    float soma_c1 = (opcao1 == 5 ? -v1_c1 : v1_c1) + (opcao2 == 5 ? -v2_c1 : v2_c1);
    float soma_c2 = (opcao1 == 5 ? -v1_c2 : v1_c2) + (opcao2 == 5 ? -v2_c2 : v2_c2);

    printf("\nResultados:\n");
    printf("Carta 1 - %s: %.2f + %.2f = %.2f\n", c1.nome_cidade, v1_c1, v2_c1, soma_c1);
    printf("Carta 2 - %s: %.2f + %.2f = %.2f\n", c2.nome_cidade, v1_c2, v2_c2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("Vencedor: Carta 1 (%s)\n", c1.nome_cidade);
    } else if (soma_c2 > soma_c1) {
        printf("Vencedor: Carta 2 (%s)\n", c2.nome_cidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao1, opcao2;

    printf("Cadastro da Carta 1:\n");
    entrada(&carta1);
    calcular(&carta1);

    printf("\nCadastro da Carta 2:\n");
    entrada(&carta2);
    calcular(&carta2);

    printf("\nEscolha o primeiro atributo:\n");
    opcao1 = escolher_atributo(0);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    opcao2 = escolher_atributo(opcao1);

    comparar(carta1, carta2, opcao1, opcao2);

    return 0;
}
