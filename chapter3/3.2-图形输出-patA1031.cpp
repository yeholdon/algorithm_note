
#include <cstdio>
#include <cstring>

char s[90];
int main() {

    scanf("%s", s);
    int n = strlen(s);
    int n1 = (n + 2)/3;
    int n2 = n - n1*2 + 2;
    //first, print top n1-1 lines
    for(int i = 0; i < n1 - 1; i++)
    {
        printf("%c", s[i]);
        for(int j = 0; j < n2-2; j++)
        {
            printf(" ");
        }
        printf("%c\n", s[n-i-1]);
        
    }
    //second, print the botttom line
    for(int i = 0; i < n2; i++)
    {
        printf("%c", s[n1+i-1]);
    }
    
    
    return 0;
}