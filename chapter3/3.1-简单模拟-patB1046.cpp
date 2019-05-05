#include <cstdio>

int main() {

    int T;
    int a1, a2, b1, b2;
    int ans1 = 0, ans2 = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);

        int sum = a1 + b1;

        if (a2 == sum && b2 != sum) {
            ans2++;
        }
        if (b2 == sum && a2 != sum) {
            ans1++;
        }
        
    }
    printf("%d %d", ans1, ans2);
    
    return 0;
}