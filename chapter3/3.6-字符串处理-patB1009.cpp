
#include <cstdio>
#include <cstring>

char s[82];
int i1 = 0, i2 = 0;
int main() {

    fgets(s, 82, stdin);
    i1 = i2 = strlen(s) - 2;
    // printf("%c\n", s[i1]);
    // getchar();
    while(i1 >= 0){
        i1--;
        if (s[i1] == ' ') {

            
            for(int j = i1 + 1; j <= i2; j++)
            {               
                printf("%c", s[j]);
            }
            printf(" ");
            i1--;
            i2 = i1;
            
        }
    }
    for(int i = i1+1; i <= i2; i++)
    {
        printf("%c", s[i]);
    }
    
    
    
    return 0;
}