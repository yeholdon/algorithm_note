
#include <cstdio>
int n = 0;
int main() {

    scanf("%d", &n);
    int hundred = n/100;
    int ten = n/10%10;

    n = n%10;
    if (hundred) {
        for(int i = 0; i < hundred; i++)
        {
            printf("B");
        }
    }
    if (ten) {
        for(int i = 0; i < ten; i++)
        {
            printf("S");
        }            
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", i+1 );
    }
    
    return 0;
}