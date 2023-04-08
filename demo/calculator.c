#include "stdio.h"

int main() {
    char operator = 0;
    double number1 = 0.0;
    double number2 = 0.0;
    printf("Enter the calculation\n");
    scanf("%lf%c%lf", &number1, &operator, &number2);

    switch (operator) {
        case '+':
            printf("=%lf\n", number1 + number2);
            break;
        case '-':
            printf("=%lf\n", number1 - number2);
            break;
        case '*':
            printf("=%lf\n", number1 * number2);
            break;
        case '/':
            if (number2 == 0)
                printf("\nDivision by zero error!");
            else
                printf("=%lf\n", number1 / number2);
            break;
        case '%':
            if ((long) number2 == 0)
                printf("\nDivision by zero error!");
            else
                printf("=%ld\n", (long) number1 % (long) number2);
            break;
        default:
            printf("\nDivision by zero error!");
            break;
    }

    return 0;
}