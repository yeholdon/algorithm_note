#include <cstdio>
#include <cstring> // for memset
#include <algorithm> // for reverse

struct bign
{
    int w[1000];
    int len;
    bign() {
        memset(w, 0, sizeof(int));
        len = 0;
    }
};

bign change(char *a) {
    bign n;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        n.w[i] = a[len - i - 1] - '0';
    }
    n.len = len;
    return n;
}

bign add(bign a, bign b) {
    int carry = 0;
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {   // because b can be greater than 10,the carry can be more than one digit  
        int tmp = (a.w[i] + b.w[i] + carry);
        c.w[c.len++] = tmp%10;
        carry = tmp/10;
    }
    // the highest digit's carry
    if (carry != 0)
    {
        c.w[c.len++] = carry;
    }
    
    return c;
    
}

bool judge(bign a) {
    for (int i = 0; i <= a.len/2; i++)
    {
        if (a.w[i] != a.w[a.len - 1 - i])
        {
            return false;
        }
        
    }
    return true;
    
}

void print(bign a) {
    for (int i = 0; i < a.len; i++)
    {
        printf("%d", a.w[a.len - 1 - i]);
    }
    printf("\n");
}

int main() {

    char str[1001];
    int k, num = 0;
    scanf("%s%d", str, &k);
    bign n = change(str);
    while (num < k && judge(n) == false)
    {
        bign a = n;
        std::reverse(a.w, a.w + a.len);
        n = add(a , n);
        num++;
    }
    print(n);
    printf("%d", num);
    
    return 0;
}