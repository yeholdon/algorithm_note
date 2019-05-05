
#include <cstdio>
#include <cmath>

int n = 0;
char c;
int main() {

    scanf("%d %c", &n, &c);
    int bottom = (int)(sqrt(2.0*(n + 1)) - 1);//the latter () is not necessary
    // note! the calculated bottom value can be even, so when so, we should minus it by 1;
    if (bottom%2 == 0) {
        bottom--;
    }
    
    for(int i = 0; i < bottom; i++)
    {
        if (i < (bottom + 1)/2) {
            for(int j = 0; j < i; j++)
            {
                printf(" ");
            }
            for(int j = 0; j < bottom - 2*i; j++)
            {
                printf("%c", c);
            }
            
            
        }
        else
        {
            for(int j = 0; j < bottom - 1 - i; j++)
            {
                printf(" ");
            }
            for(int j = 0; j < 2*(i - (bottom+1)/2 + 1) + 1; j++)
            {
                printf("%c", c);
            }
            
            
        }
        printf("\n");
        
    }
    printf("%d", n - (bottom+1)*(bottom+1)/2 + 1);

    return 0;
}