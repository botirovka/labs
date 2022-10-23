#include <stdio.h>
#include <math.h>
int main() {
    double f,sum,x;
    printf("-------------------------------------------------\n");
    printf("|\t%s\t| %9s\t| %11s\t|\n", "X","Taylor", "Function");
    printf("-------------------------------------------------\n");
    for(x=-0.9;x<=0.9;x+=0.1) {
        f=1;sum = 1;int i=0;
        while(fabs(f)>1e-10)
        {
            f= f * (1+(4*i))* -x/(4+(4*i));
            i++;
            sum += f;
        }
        printf("|%10.1f\t|%12.6f\t|%12.6f\t|\n",x, sum,pow(1.0+x,-1.0/4));
    }
    printf("-------------------------------------------------\n");
    return 0;
}