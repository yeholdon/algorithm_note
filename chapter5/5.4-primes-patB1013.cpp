#include <cstdio>
#include <cmath>

const int maxn = 10010;

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

int primes[maxn], num = 0;
bool p[maxn] = {false};
void findPrime(int n) {// find n primes
    for (int i = 1; i < maxn; i++)
    {
        if (isPrime(i))
        {
            primes[num++] = i;
            p[i] = true;
            if (num >= n)
            {
                break;
            }
        }

        
    }
    
}

// filter method .time complexity:O(nloglogn) 
void findPrimeFilter(int n) {
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false)
        { // i is a prime
            primes[num++] = i;
            for (int j = i + i; j < maxn; j += i)
            {
                //filter out all the multiples of i
                p[j] = true;
            }
            
        }
        
    }
    
}

int n, m;

int main() {
    scanf("%d %d", &m, &n);
    findPrime(n);
    int cnt = 0;
    for (int i = m - 1; i < n; i++)
    {
        printf("%d", primes[i]);
        cnt++;
        if (cnt%10 != 0 && i < n - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
        
        
    }
    
    return 0;
}