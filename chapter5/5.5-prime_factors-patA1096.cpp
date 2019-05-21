#include <cstdio>
#include <vector>
#include <cmath>
// to prevent overflow in middle process
typedef long long LL;

LL n;
int main() {
    scanf("%lld", &n);
    LL sqr = (LL) sqrt(1.0 * n);
    LL j, maxl = 0, maxr = 0, max = 0;
    LL i = 2;
    while(i <= sqr)
    {
        if (n % i == 0)
        {
            LL tmp_n = n / i;
            j = i;
            for (LL m = i + 1; m <= sqr; m++)
            {
                if (tmp_n % m == 0)
                {
                    j++;
                    tmp_n /= m;
                }
                else
                {
                    break;
                }
                
            }

            LL len = j - i + 1;
            if (max < len)
            {
                max = len;
                maxl = i;
                maxr = j;
            }
            i++; // at least i++
        }
        else i++; 
        
    }
    
    // output
    if (max == 0)
    {
        printf("1\n%lld", n);
    }
    else if (max == 1)
    {
        printf("1\n%lld", maxl);
    }
    else
    {
        printf("%lld\n", max);
        for (LL s = maxl; s <= maxr; s++)
        {
            if (s != maxl)
            {
                printf("*");
            }
            
            printf("%lld", s);
            
        }
        
    }
    
    
    
    return 0;
}