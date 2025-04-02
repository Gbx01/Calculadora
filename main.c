#include <stdio.h>

// Função para calcular o MDC (Máximo Divisor Comum) - Algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar a fração
void simplificar(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
    if (*den < 0) { // Mantém o denominador positivo
        *num = -*num;
        *den = -*den;
    }
}

int main() {
    int num1, den1, num2, den2;
    char op;

    // Entrada dos valores
    printf("Digite a primeira fração (numerador e denominador): ");
    scanf("%d %d", &num1, &den1);

    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Digite a segunda fração (numerador e denominador): ");
    scanf("%d %d", &num2, &den2);

    int num_res, den_res;

    // Realiza a operação escolhida
    switch (op) {
        case '+':
            num_res = num1 * den2 + num2 * den1;
            den_res = den1 * den2;
            break;
        case '-':
            num_res = num1 * den2 - num2 * den1;
            den_res = den1 * den2;
            break;
        case '*':
            num_res = num1 * num2;
            den_res = den1 * den2;
            break;
        case '/':
            num_res = num1 * den2;
            den_res = den1 * num2;
            if (den_res == 0) {
                printf("Erro: divisão por zero.\n");
                return 1;
            }
            break;
        default:
            printf("Operação inválida.\n");
            return 1;
    }

    // Simplifica o resultado
    simplificar(&num_res, &den_res);

    // Exibe o resultado
    printf("Resultado: %d/%d\n", num_res, den_res);

    return 0;
}
