#include <stdio.h>
#include <math.h>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double u,x,y,z,zn;
printf("Введіть значення x,y,z:");
scanf("%lf %lf %lf", &x, &y, &z);
zn = 0;
if (zn == 0)
printf("Якщо знаменник = 0, обчислення виразу неможливе!");
else {
u = (fmax(fmax(x,y), 5.65) + x * fmax(y,z)) / zn;
printf("Значення u=%lf", u);
    return 0;
    }
}