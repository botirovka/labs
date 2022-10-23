#include <stdio.h>
#include <conio.h>
int main()
{
for(int i=10000;i<100000;i++) {
int s=i/10000+ i/1000%10 + i/100%10 + i/10%10 + i%10;
    if (s <= 23) {
        printf("%d\t", i);
    }
}
    getch();
return 0;
}
