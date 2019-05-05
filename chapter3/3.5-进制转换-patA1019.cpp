#include <cstdio>

const int MAX_DIGITS = 20;
int main() {

    int n, b;
    scanf("%d %d", &n, &b);

    int ans[MAX_DIGITS] = { 0 };
    int p = 0;
    do {
        ans[p++] = n % b;
        n /= b;
    } while(n > 0);

    bool flag = true;
    for(int  i = p - 1; i >= 0; i--)
    {
        if (ans[i] != ans[p-1-i]) {
            flag = false;
            break;
        }
        
    }

    if (flag) {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    


    for(int i = p - 1; i >= 0; i--)
    {
        if (i != p-1) {
           printf(" ");         
        }
        printf("%d", ans[i]);
    }
    
    
    return 0;
}