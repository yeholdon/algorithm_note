#include <cstdio>
#include <cmath>

const int maxt = 11111;

bool isPrime(int n) {
    if (n <= 1)
    {
        return false;
    }

    int sqr = (int) sqrt(1.0 * n); 
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        
    }
    
    return true;
}

int findMinPrime(int t) {
    if (isPrime(t))
    {
        return t;
    }
    else
    {
        while (!isPrime(t))
        {
            t++;
        }
        return t;
    }
}

void findHash(int n, int TSize, bool *h) {
    int H = n % TSize;
    if (h[H] == false)
    {
        printf("%d", H);
        h[H] = true;
    }
    else
    {
        for (int i = 1; i < TSize; i++)
        {
            H = (n + i*i)%TSize;
            if (h[H] == false)
            {
                printf("%d", H);
                h[H] = true;
                break;
            }
            if (i == TSize - 1)
            {
                printf("-");
            }
            
        }
        
    }
    
    
    
}

int TSize, n, a;
bool H[maxt] = {false};
int main() {
    // input
    scanf("%d%d", &TSize, &n);
    TSize = findMinPrime(TSize);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        findHash(a, TSize, H);
        if (i != n - 1)
        {
            printf(" ");
        }
        
    }
    
    return 0;
}