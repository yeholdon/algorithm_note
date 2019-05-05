
#include <cstdio>
char id[20];

int n = 0;
int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char f[16] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    scanf("%d", &n);
    bool flag = true;
    for(int j = 0; j < n; j++)
    {
        scanf("%s", id);
        int i;
        int ans = 0;
        for(i = 0; i < 17; i++)
        {

            if (!(id[i] >= '0' && id[i] <= '9')) {
                break;
            }
            ans = ans + (id[i] - '0')*w[i];

        }

        if (i < 17) {
            flag = false;
            printf("%s\n", id);
        }
        else
        {
            if (f[ans%11] != id[17]) {
                flag = false;
                printf("%s\n", id);
            }
            
        }
        

    }
    if (flag) {
        printf("All passed");
    }

    return 0;
}