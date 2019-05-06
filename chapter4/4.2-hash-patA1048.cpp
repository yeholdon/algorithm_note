
#include <cstdio>

const int maxn = 1010;

int hashTable[maxn] = {0};
int n, m, t;

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        hashTable[t]++;
    }
    
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] && hashTable[m-i])
        {
            if (i == m-i && hashTable[i] <= 1)
            {
                continue;
            }
            printf("%d %d", i, m-i);
            return 0;
            
        }
        
    }
    printf("No Solution");
    return 0;
}