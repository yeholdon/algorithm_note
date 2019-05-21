#include <cstdio>
#include <cmath>

const int maxn = 100010;

struct PrimeFactor
{
    int x;
    int cnt;
    PrimeFactor() {
        x = cnt = 0;
    }
} fac[10];


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

int findPrimes(int *primes, int maxn) {
    int num = 0;
    if (maxn < 1)
    {
        return -1;
    }
    
    for (int i = 1; i < maxn; i++)
    {
        if (isPrime(i))
        {
            primes[num++] = i;
        }
    }

    return num;
    
}

int n;
int primes[maxn];

int main() {
    scanf("%d", &n);

    // specially judge 1
    if (n == 1)
    {
        printf("1=1");
    }
    else
    {
        printf("%d=", n);
    }
    
    
    int sqr = (int) sqrt(1.0 * n);
    int num = findPrimes(primes, maxn);
    int pnum = 0;
    for (int i = 0; primes[i] <= sqr && i < num; i++)
    {
        if (n % primes[i] == 0)
        {
            fac[pnum].x = primes[i];
            while (n % primes[i] == 0)
            {
                fac[pnum].cnt++;
                n /= primes[i];
            }
            pnum++;
        }
        if (n == 1)
        { // break in time to save time
            break;
        }
        
    }
    // cannot be all divided
    if (n != 1)
    { // There must be a prime factor greater than sqrt(n)
        fac[pnum].x = n;
        fac[pnum++].cnt++;
    }
    
    // output
    
    for (int i = 0; i < pnum; i++)
    {
        if (fac[i].cnt == 1)
        {
            printf("%d", fac[i].x);
        }
        else
        {
            printf("%d^%d", fac[i].x, fac[i].cnt);
        }
        if (i != pnum - 1)
        {
            printf("*");
        }
        
    }
    
    
    return 0;
}