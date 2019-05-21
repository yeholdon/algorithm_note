#include <cstdio>

const int maxn = 101;
// key note
int gcd(int a, int b) {
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int gcd1(int a, int b) {
    while (b > 0)
    {
        a = b;
        b = a%b;
    }
    if (b == 0)
    {
        return a;
    }
    return -1;
    
}
int n, m;
int a[maxn];
int main() {

    scanf("%d%d", &n, &m);
    
    m = m % n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int temp, next;
    int nm_gcd = gcd(n, m);
    for (int i = n - m; i < n - m + nm_gcd; i++)
    {   
        if (m == 0)
        {
            break;
        }
        
        temp = a[i];
        // use do---while
        // int now = i;
        // do
        // {
        //     next = (now - m + n)%n;
        //     if(next != i) a[now] = a[next];
        //     else a[now] = temp;
        //     now = next;

        // } while (now != i);

        // use while
        int j = i;
        while (j != (i + m)%n)
        {
            a[j] = a[(j - m + n)%n];
            j = (j - m + n)%n;
        }
        if (j == (i + m)%n)
        {
            a[j] = temp;
        }        
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
        
    }
    
    return 0;
}