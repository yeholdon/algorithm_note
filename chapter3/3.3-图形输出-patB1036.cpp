
#include <cstdio>

char a;
int m, n = 0;
int main() {
    scanf("%d %c", &n, &a);
    if (n%2 == 0) {
        m = n/2;
    }
    else
    {
        m = n/2 +1;
    }
    for(int i = 0; i < m; i++)
    {
        if (i == 0 || i == m - 1) {
            for(int j = 0; j < n; j++)
            {
                printf("%c", a);
            }
            printf("\n");
            
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                if (j == 0 || j == n-1) {
                    printf("%c", a);
                }
                else
                {
                    printf(" ");
                }
                
                
            }
            printf("\n");
            
        }
        
        
    }
    
    
    
    return 0;
}