
#include <cstdio>
#include <algorithm>

const int maxn = 5;

int to_array(int n, int *a) {
    int num = 0;
    while (n > 0)
    {
        a[num++] = n%10;
        n /= 10;
    }
    return num;
}

int to_int(int num, int *a) {
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        ans = 10*ans + a[i];
    }
    return ans;
}

bool cmp(int &a, int &b) {
    return a > b;
}

int n = 0;
int a[maxn] = {0};
int max, min;
int main() {
    scanf("%d", &n);


    while (1)
    {
        to_array(n, a);
        std::sort(a, a + 4);
        min = to_int(4, a);
        std::sort(a, a + 4, cmp);
        max = to_int(4, a);     
        printf("%04d - %04d = %04d\n", max, min, max - min);
        n = max - min;
        if (max == min || n == 6174)
        {
            break;
        }
          
    }
    

    return 0;
}