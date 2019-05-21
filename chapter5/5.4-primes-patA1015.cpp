#include <cstdio>
#include <cmath>

// judge primes
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

int reverse(char *a, int n, int radix) {
    int num = 0;
    while (n > 0)
    {
        a[num++] = n%radix;
        n /= radix;
    }
    n = 0;
    for (int i = 0; i < num; i++)
    {
        n = n * radix + a[i];
    }
    
    return n;
}




int n, d;
char a[6];
int main() {
    // input 
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
        {
            break;
        }
        else
        {
            scanf("%d", &d);

            if (isPrime(n))
            {
                int rev = reverse(a, n, d);
                if (isPrime(rev))
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
            }
            else
            {
                printf("No\n");
            }
            
            
        }
        
    }


    return 0;
}