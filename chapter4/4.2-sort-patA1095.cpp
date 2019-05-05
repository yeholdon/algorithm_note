
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