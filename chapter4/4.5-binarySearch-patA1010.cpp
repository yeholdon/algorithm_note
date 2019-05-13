#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int map[128];
char c1[20], c2[20];
int tag; 
LL n1, n2, radix;

void initMap() {
    for (char i = '0'; i <= '9'; i++)
    {
        map[i] = i - '0';
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        map[i] = i - 'a' + 10;
    }
}

LL digitToNum(char *str, LL &radix) {
    int len = strlen(str);
    LL ans = 0;
    for (int i = 0; i < len; i++)
    {
        // ans += map[str[i]] * radix^(len - 1 - i);
        ans = ans * radix + map[str[i]];
        if (ans < 0)
        {   // overflow means can't find the target answer. 
            return -1;
        }
    }

    return ans;
}

int findTheLow(char *str, int len) {
    int ans = -1;
    for (int i = 0; i < len; i++)
    {
        if (map[str[i]] > ans )
        {
            ans = map[str[i]];
        }
        
    }
    return ans + 1;
    
}

LL binarySearch(LL left, LL right, LL &value) {
    LL mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        LL n2 = digitToNum(c2, mid);
        if (n2 == value)
        {
            return mid;
        }
        else if (n2 > value || n2 == -1)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        
    }
    return -1;
}

int main() {
    scanf("%s %s %d %lld", c1, c2, &tag, &radix);

    initMap();

    if (strcmp(c1, c2) == 0)
    {
        printf("%lld", radix);
        return 0;
    }
    

    if (tag == 2)
    {   //swap the c1 & c2 for convenience
        char tmp[20];
        strcpy(tmp, c1);
        strcpy(c1, c2);
        strcpy(c2, tmp);
    }

    // transform the number of which radix has been known to decimalism
    LL n1 = digitToNum(c1, radix);
    
    // binarySearch radix of N2 in internal [low, high)
    LL low = findTheLow(c2, strlen(c2));
    LL high = max(low, n1) + 1;
    LL ans = binarySearch(low, high, n1);

    if (ans == -1)
    {
        printf("Impossible");
    }
    else
    {
        printf("%lld", ans);
    }
    
    
    return 0;
}