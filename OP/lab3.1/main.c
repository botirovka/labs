#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double sum,mean;
    int n;
    double vector [100];
    sum = 0;
    printf("Введіть n кількість елементів вектора, де n <= 100\n");
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        printf("Введіть %d елемент вектора:\n",i + 1);
        scanf("%lf", &vector[i]);
        sum += vector[i];
    }
    mean = sum / n;
    printf("|Ср.арифметичне:%6.3lf|\nВектор:", mean);
    for (int i = 0; i<n; i++){
        if (vector[i]<mean){
            vector[i] *= 1.7;
        }
        if (vector[i]==0){
            vector[i]=mean;
        }
        printf("%.3lf\t",*(vector+i));
    }


    return 0;
    getch();
}
