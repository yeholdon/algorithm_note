#include <cstdio>
#include <algorithm>
using namespace std;
int transform(char c) {
    if (c == 'B') {
        return 0;
    }
    if (c == 'C') {
        return 1;
    }
    if (c == 'J') {
        return 2;
    }
    
}

int main() {
    int n;
    char c1, c2;
    int t1, t2;
    int vic_de[2][3];
    int win_cnt[2][3];
    fill(vic_de[0], vic_de[0]+6, 0);
    fill(win_cnt[0], win_cnt[0]+6, 0);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c", &c1, &c2);

        //judge victory or defeat
        //0-win 1-dogfall 2-fail
        t1 = transform(c1);
        t2 = transform(c2);
        if ((t1+1)%3 == t2) {
            //jia win
            vic_de[0][0]++;
            vic_de[1][2]++;
            win_cnt[0][t1]++;
        }
        else if ((t2+1)%3 == t1)
        {
            //yi win
            vic_de[0][2]++;
            vic_de[1][0]++;
            win_cnt[1][t2]++;
        }
        else
        {
            //dogfall
            vic_de[0][1]++;
            vic_de[1][1]++;
        }



        
    }

    //find most winnable gesture.
    int m1 = 0, m2 = 0;
    for(int  i = 0; i < 3; i++)
    {
        if (win_cnt[0][i] > win_cnt[0][m1]) {
            m1 = i;
        }
        if (win_cnt[1][i] > win_cnt[1][m2]) {
            m2 = i;
        }
        
        
    }
    for(int  i = 0; i < 2; i++)
    {
        printf("%d %d %d\n", vic_de[i][0], vic_de[i][1], vic_de[i][2]);
    }
    char retrans[3] = {'B', 'C', 'J'};
    printf("%c %c", retrans[m1], retrans[m2]);
    return 0;
}