#include <cstdio>
#include <cstring> // for memset
struct bign
{
    int w[21];
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

bign multi(bign a, int b) {
    int carry = 0;
    bign c;
    for (int i = 0; i < a.len; i++)
    {   // because b can be greater than 10,the carry can be more than one digit  
        int tmp = (a.w[i] * b + carry);
        c.w[c.len++] = tmp%10;
        carry = tmp/10;
    }
    // the highest digit's carry
    while (carry != 0)
    {
        c.w[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
    
}

bool judge(bign a, bign b) {
    // the lengths are not equal
    if (a.len != b.len)
    {
        return false;
    }

    int count[10] = {0};
    for (int i = 0; i < a.len; i++)
    {
        count[a.w[i]]++;
        count[b.w[i]]--;   
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] != 0)
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
    
}

char s[22];
bign n, dbn;
int main() {

    fgets(s, 22, stdin);
    int len = strlen(s) - 1;
    s[len] = '\0';
    n = change(s);
    dbn = multi(n, 2);
    if (judge(n, dbn))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    print(dbn);
    
    
    return 0;
}