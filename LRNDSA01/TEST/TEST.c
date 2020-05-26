#include <stdio.h>

int main() {
    int x;
    while (scanf("%d\n", &x)>0 && x!= 42) {
        printf("%d\n", x);
    }
    return 0;
}
