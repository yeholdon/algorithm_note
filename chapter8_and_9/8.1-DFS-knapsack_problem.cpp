#include <cstdio>

const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumV) {
    if (index >= n)
    {
        if (sumW <= V && sumV > maxValue)
        {
            maxValue = sumV;
        }
        return;
    }
    else if (sumW > V)
    {
        return;
    }
    
    // branch
    DFS(index + 1, sumW, sumV);
    DFS(index + 1, sumW + w[index], sumV + c[index]);
    
}

int main() {
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }

    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    
    return 0;
}

/*
5 8
3 5 1 2 2 
4 5 2 1 3
*/