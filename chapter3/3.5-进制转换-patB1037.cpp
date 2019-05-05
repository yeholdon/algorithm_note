
#include <cstdio>
const int Galleon = 17*29;
const int Sickle = 29;
int g1, s1, k1;
int g2, s2, k2;

int main() {
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2 );
    long long sum = g1*Galleon + s1*Sickle + k1;
    long long money = g2*Galleon + s2*Sickle + k2;
    int change = money - sum;
    if (change < 0) {
        printf("-");
        change = -change;
    }
    printf("%d.%d.%d", change/Galleon, change%Galleon/Sickle, change%Sickle);
    
    return 0;
}