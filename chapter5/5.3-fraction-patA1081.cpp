#include <cstdio>
#include <algorithm>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

struct Fraction
{
    ll up, down;
};

Fraction reduction(Fraction f) {
    if (f.down < 0)
    {
        f.down = -f.down;
        f.up = -f.up;
    }

    if (f.up == 0)
    {
        f.down = 1;
    }
    else
    {
        int d = gcd(std::abs(f.up), f.down);
        f.down /= d;
        f.up /= d;
    }
    
    return f;
}

Fraction add(const Fraction &a, const  Fraction &b) {
    Fraction ans;
    ans.up = a.up*b.down + b.up*a.down;
    ans.down = a.down * b.down;
    return reduction(ans);
}

void showFraction(Fraction f) {
    Fraction tmp = reduction(f);
    if (tmp.down == 1)
    {
        printf("%lld\n", tmp.up);
    }
    else if (std::abs(tmp.up) > tmp.down)
    {
        printf("%lld %lld/%lld\n", tmp.up/tmp.down, std::abs(tmp.up)%tmp.down, tmp.down);
    }
    else
    {
        printf("%lld/%lld\n", tmp.up, tmp.down);
    }
    
}

int n;
Fraction fra[101], sum;
int up, down;
int main() {

    sum.up = 0;
    sum.down = 1;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &fra[i].up, &fra[i].down);
        fra[i] = reduction(fra[i]);
        sum = add(sum, fra[i]);
    }
    
    showFraction(sum);
    return 0;
}