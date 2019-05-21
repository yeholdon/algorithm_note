#include <cstdio>
#include <algorithm>

typedef long long LL;

struct Fraction
{
    LL up, down;
};

LL gcd(LL a, LL b) {
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

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
    else if (f.down == 0)
    {
        return f;
    }
    else
    {
        int d = gcd(std::abs(f.down), std::abs(f.up));
        f.down /= d;
        f.up /= d;
    }
    return f;
}

Fraction add(Fraction a, Fraction b) {
    Fraction sum;
    sum.up = a.up * b.down + a.down * b.up;
    sum.down = a.down * b.down;
    return reduction(sum);
}

Fraction minus(Fraction a, Fraction b) {
    Fraction diff;
    diff.up = a.up * b.down - a.down * b.up;
    diff.down = a.down * b.down;
    return reduction(diff);
}

Fraction multiple(Fraction a, Fraction b) {
    Fraction product;
    product.down = a.down * b.down;
    product.up = a.up * b.up;
    return reduction(product);
}

Fraction divide(Fraction a, Fraction b) {
    Fraction quotient;
    quotient.up = a.up * b.down;
    quotient.down = a.down * b.up;
    return reduction(quotient);
}

void showFraction(Fraction f) {
    Fraction tmp;
    tmp = reduction(f);
    if (tmp.down != 0 && tmp.up < 0)
    {
        printf("(");
    }
    
    if (tmp.down == 1)
    {
        printf("%lld", tmp.up);
    }
    else if (tmp.down == 0)
    {
        printf("Inf");
    }
    else if (std::abs(tmp.down) < std::abs(tmp.up))
    {
        printf("%lld %lld/%lld", tmp.up/tmp.down, std::abs(tmp.up)%tmp.down, tmp.down);
    }
    else
    {
        printf("%lld/%lld", tmp.up, tmp.down);
    }

    if (tmp.down != 0 && tmp.up < 0)
    {
        printf(")");
    }
    
}


Fraction m, n;

int main() {
    scanf("%lld/%lld %lld/%lld", &m.up, &m.down, &n.up, &n.down);

    // add
    Fraction sum = add(m, n);
    showFraction(m);
    printf(" + ");
    showFraction(n);
    printf(" = ");
    showFraction(sum);
    printf("\n");
    // minus
    Fraction diff = minus(m, n);
    showFraction(m);
    printf(" - ");
    showFraction(n);
    printf(" = ");
    showFraction(diff);
    printf("\n");
    // multiple
    Fraction product = multiple(m, n);
    showFraction(m);
    printf(" * ");
    showFraction(n);
    printf(" = ");
    showFraction(product);
    printf("\n");
    // divide
    Fraction quotient = divide(m, n);
    showFraction(m);
    printf(" / ");
    showFraction(n);
    printf(" = ");
    showFraction(quotient);    
    printf("\n");
    
    return 0;
}