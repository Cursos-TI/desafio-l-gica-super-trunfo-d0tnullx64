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

void comparar(Carta c1, Carta c2, int opcao) {
    float atributo_c1, atributo_c2;
    char *nome_atributo;

    switch (opcao) {
        case 1:
            atributo_c1 = c1.populacao;
            atributo_c2 = c2.populacao;
            nome_atributo = "População";
            break;
        case 2:
            atributo_c1 = c1.area;
            atributo_c2 = c2.area;
            nome_atributo = "Área";
            break;
        case 3:
            atributo_c1 = c1.pib;
            atributo_c2 = c2.pib;
            nome_atributo = "PIB";
            break;
        case 4:
            atributo_c1 = c1.pontos;
            atributo_c2 = c2.pontos;
            nome_atributo = "Pontos Turísticos";
            break;
        case 5:
            atributo_c1 = c1.densidade;
            atributo_c2 = c2.densidade;
            nome_atributo = "Densidade Demográfica";
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("\nComparação (Atributo: %s):\n", nome_atributo);
    printf("Carta 1 - %s: %.2f\n", c1.nome_cidade, atributo_c1);
    printf("Carta 2 - %s: %.2f\n", c2.nome_cidade, atributo_c2);

    // Regra especial para Densidade (menor valor vence)
    int vence_c1 = (opcao == 5) ? (atributo_c1 < atributo_c2) : (atributo_c1 > atributo_c2);

    if (vence_c1) {
        printf("Vencedor: Carta 1 (%s)\n", c1.nome_cidade);
    } else if (atributo_c1 == atributo_c2) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: Carta 2 (%s)\n", c2.nome_cidade);
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    printf("Cadastro da Carta 1:\n");
    entrada(&carta1);
    calcular(&carta1);

    printf("\nCadastro da Carta 2:\n");
    entrada(&carta2);
    calcular(&carta2);

    printf("\nMenu de Atributos:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparação: ");
    scanf("%d", &opcao);

    comparar(carta1, carta2, opcao);

    return 0;
}
