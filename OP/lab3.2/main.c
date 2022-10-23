#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n, m, null,sum,max;
    double vector [100][100];
    sum = 0;
    max= 0;
    printf("Введіть n кількість рядків матриці, де n <= 100\n");
    scanf("%d", &n);
    printf("Введіть m кількість стовбців матриці, де m <= 100\n");
    scanf("%d", &m);
    for (int i = 0; i<n; i++){
        null = 0;
        for (int j = 0; j<m; j++){
            printf("Введіть %d елемент %d стовпця:\n",j + 1, i + 1);
            scanf("%lf", &vector[i][j]);
            if (0 == vector[i][j]) {
                ++null;
            }
        }

        sum += null;
    }
    printf("Кількість нульових елементів: %d\n", sum);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            printf("%.3lf\t",vector[i][j]);
        }
        printf("\n");
    }
    return 0;
}
