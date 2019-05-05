
#include <cstdio>
#include <cstring>
char a[110];
int ans = 0;
int va[4] = {0};
char f[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main() {

    //gets(a); it has been removed in c++14
    fgets(a, 102, stdin);
    int len = strlen(a);
    if(a[len - 1] == '\n' && a[len] == '\0') {
        a[len - 1] = '\0';
    }
    for(int i = 0; i < strlen(a); i++)
    {
        ans = ans + a[i] - '0';
    }

    int p = 0;
    while(ans != 0){
        va[p++] = ans%10;
        ans /= 10;
    }
    
    for(int i = p - 1; i >= 0; i--)
    {
        if (i != p-1) {
            printf(" ");
        }
        printf("%s", f[va[i]]);
        
    }
    
    
    return 0;
}