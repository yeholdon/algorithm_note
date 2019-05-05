#include <cstdio>

int main() {

    int c1, c2;

    scanf("%d%d", &c1, &c2);

    int del = c2 - c1;
    if (del%100 >= 50) {
        del = del/100 + 1;

    }
    else {
        del = del/100;
    }
    printf("%02d:%02d:%02d\n", del/3600, del%3600/60, del%60);
    return 0;
}
