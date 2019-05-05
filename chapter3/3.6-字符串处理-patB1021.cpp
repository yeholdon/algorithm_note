
#include <cstdio>
#include <cstring> 
char s[1010];
int h[10];
int main() {
    
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++)
    {
        h[s[i] - '0']++;
    }
    for(int i = 0; i < 10; i++)
    {
        if (h[i] != 0) {
            printf("%d:%d\n", i, h[i]);
        }
        
    }
    
    
    return 0;

}