#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>
void gettime(FILE* log);
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    FILE* log = fopen("log.txt", "a");
    gettime(log);
    fprintf(log, "Програму запущено\n");
    int b,c;
    double a, x, y, k[2];
    printf("Введіть \"0\" для запису в файл, \"1\", щоб прочитати з файлу:\n");
    scanf("%d", &b);
    if (b == 0) {
        FILE* in = fopen("in.bin", "wb");
        printf("Введіть x, y:\n");
        scanf("%lf%lf", &x, &y);
        gettime(log);
        fprintf(log, "Значення x = %lf, y = %lf введено користувачем\n", x,y);
        if (in != 0)
        {
            k[0] = x;
            k[1] = y;
            fwrite(k, sizeof(k), 1, in);
            fclose(in);
        }
        a = fabs(pow(x, y/x) - pow(y/x, 1.0/3.0));
        printf("Щоб зберегти в \".txt\" файлі введіть \"0\", в \".bin\" файлі - \"1\"\n");
        scanf_s("%d", &c);
        if (c == 0)
        {
            FILE* out = fopen("out.txt", "w");
            printf("Вираз a: %lf\n", a);
            fprintf(out, "Вираз a: %lf\n", a);
            fclose(out);
            gettime(log);
            fprintf(log, "Файл збережено в \"C:\\c\\OP\\lab4.1\\cmake-build-debug\\out.txt\"\n");
        }
        if (c == 1)
        {
            FILE* out = fopen("out.bin", "wb");
            fwrite(&a, sizeof(a), 1, out);
            printf("Вираз a: %lf\n", a);
            fclose(out);
            gettime(log);
            fprintf(log, "Файл збережено в \"C:\\c\\OP\\lab4.1\\cmake-build-debug\\out.bin\"\n");
        }
    }
    else if (b == 1) {
        FILE* in = fopen("in.bin", "rb");
        fread(k, sizeof(k), 1, in);
        x = k[0];
        y = k[1];
        gettime(log);
        fprintf(log, "Значення x = %lf, y = %lf,взято з файлу \"C:\\c\\OP\\lab4.1\\cmake-build-debug\\in.bin\"\n", x, y);
        a = fabs(pow(x, y/x) - pow(y/x, 1.0/3.0));
        gettime(log);
        printf("Щоб зберегти в \".txt\" файлі введіть \"0\", в \".bin\" файлі - \"1\"\n");
        scanf_s("%d", &c);
        fprintf(log, "Вираз a: %lf\n", a);
        if (c == 0)
        {
            FILE* out_file = fopen("out.txt", "w");
            fprintf(out_file, "a: %lf\n", a);
            printf("a: %lf\n", a);
            gettime(log);
            fprintf(log, "Файл збережено в \"C:\\c\\OP\\lab4.1\\cmake-build-debug\\out.txt\"\n");

        }
        if (c == 1)
        {
            FILE* out_file = fopen("out.bin", "wb");
            fwrite(&a, sizeof(a), 1, out_file);
            printf("a: %lf\n", a);
            gettime(log);
            fprintf(log, "Файл збережено в \"Файл збережено в \"C:\\c\\OP\\lab4.1\\cmake-build-debug\\out.bin\"\n");
        }
    }
    else
    {
        gettime(log);
        fprintf(log, "Error, введено неправильне значення\n");
        printf("Error, введено неправильне значення");
    }
    gettime(log);
    fprintf(log, "Програму виконано\n");
    fclose(log);
}


void gettime(FILE* log) {
    time_t t;
    time(&t);
    char time[26];
    ctime_s(time, sizeof time, &t);
    time[24] = ']';
    time[25] = '\0';
    fprintf(log, "[%s\n", time);
}