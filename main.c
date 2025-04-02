#include <stdio.h>

// Fun��o para calcular o MDC (M�ximo Divisor Comum) - Algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fun��o para simplificar a fra��o
void simplificar(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
    if (*den < 0) { // Mant�m o denominador positivo
        *num = -*num;
        *den = -*den;
    }
}

int main() {
    int num1, den1, num2, den2;
    char op;

    // Entrada dos valores
    printf("Digite a primeira fra��o (numerador e denominador): ");
    scanf("%d %d", &num1, &den1);

    printf("Digite a opera��o (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Digite a segunda fra��o (numerador e denominador): ");
    scanf("%d %d", &num2, &den2);

    int num_res, den_res;

    // Realiza a opera��o escolhida
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
                printf("Erro: divis�o por zero.\n");
                return 1;
            }
            break;
        default:
            printf("Opera��o inv�lida.\n");
            return 1;
    }

    // Simplifica o resultado
    simplificar(&num_res, &den_res);

    // Exibe o resultado
    printf("Resultado: %d/%d\n", num_res, den_res);

    return 0;
}
