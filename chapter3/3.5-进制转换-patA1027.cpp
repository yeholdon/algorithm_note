#include <cstdio>

char f[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
unsigned char rgb[3];
int main() {

    scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);
    unsigned char ans[2] = {0};
    printf("#");
    for(int i = 0; i < 3; i++)
    {
        unsigned char k = 0;
        do {
            ans[k++] = rgb[i] % 13;
            rgb[i] /= 13;
        } while(rgb[i] > 0);
        for(int  j = 1; j >= 0; j--)
        {
            printf("%c", f[ans[j]]);
        }
        
    }
    
    return 0;
}