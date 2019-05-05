
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;


const int maxn = 10010;
// const int maxm = 80010;


struct Car
{
    char id[8];
    int t;
    char status[4];
} all[maxn], valid[maxn];


bool cmp(const Car &a, const Car &b){
    if (strcmp(a.id, b.id) != 0)
    {
        return strcmp(a.id, b.id) < 0;
    }
    else
    {
        return a.t < b.t;
    }
    
    
}

bool cmpByTime(const Car &a, const Car &b) {
    return a.t < b.t;
}

int toSec(int &h, int &m, int &s) {
    return h*3600 + m*60 +s;
}


int n, k;
int maxT = 0;
map<string, int> maxP;


int main() {

    // input
    scanf("%d%d", &n, &k);
    int hh, mm, ss;
    for (int i = 0; i < n; i++)
    {
        scanf("%s ", all[i].id);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        all[i].t = toSec(hh, mm, ss);
        scanf(" %s", all[i].status);
    }

    
    // sort
    sort(all, all + n, cmp);

    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(all[i].id, all[i+1].id) == 0 
            && strcmp(all[i].status, "in") == 0 
            && strcmp(all[i+1].status, "out") == 0)
        {
            valid[m++] = all[i];
            valid[m++] = all[i+1];
            // there is no such plate number in map
            if (maxP.count(all[i].id) == 0)
            {
                maxP[all[i].id] = 0;
            }
              
            maxP[all[i].id] += all[i+1].t - all[i].t;
            maxT = max(maxT, maxP[all[i].id]);
        }
        
    }

    sort(valid, valid + m, cmpByTime);
    int num = 0;

    /*
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        int t = toSec(h, m, s);  
        for(int j = 0; valid[j].t < t; j++)
        {
            if (strcmp(valid[i].status, "in") == 0)
            {
                num++;
            }
            else
            {
                num--;
            }
                
        }      
        printf("%d\n", num);
        num = 0;
    }
    */
    // to use while, and don't reset the num for every cycle, 
    // which can reduce the complex rate
    int now  = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = toSec(hh, mm, ss);  
        while (now < m && valid[now].t <= t)
        {
            if (!strcmp(valid[now].status, "in"))
            {
                num++;
            }
            else
            {
                num--;
            }
            now++;
            
            
        }
        printf("%d\n", num);
    }
    
    
    
    map<string, int>::iterator it = maxP.begin();
    for (; it != maxP.end(); it++)
    {
        if (it->second == maxT)
        {
            printf("%s ", it->first.c_str());
        }
        
    }
    printf("%02d:%02d:%02d", maxT/3600, maxT%3600/60, maxT%60);
    return 0;
}

/*
Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/