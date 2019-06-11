#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 2010; 
map<string, int> name_to_index;
map<int, string> index_to_name;
map<string, int> gang;
int weight[maxn] = {0}; //先这样
int G[maxn][maxn] = {0};
int n, k, t;
string str_a, str_b;
bool vis[maxn] = {false};
int cur_index = 1;

int initStrToIndex(string str) {
    if (name_to_index[str] != 0)
    {
        return name_to_index[str];
    }
    else
    {
        // update meanwhile
        name_to_index[str] = cur_index;
        index_to_name[cur_index] = str;
        return cur_index++;
    }
    
}


void DFS(int u, int &head, int &total, int &mem_num) {
    vis[u] = true;
    mem_num++;
    if (weight[u] > weight[head])
    {
        head = u;
    }
    
    for (int i = 1; i < cur_index; i++)
    {
        // visited node shouldn't be accessed again, but there can be ring
        // So separate the two conditions.
        if (G[u][i] > 0)
        {
            total += G[u][i];
            G[u][i] = G[i][u] = 0; 
            // note here. have to delete this edge, otherwise
            // the weight will be count repeatedly.
            if (vis[i] == false)
            {
                DFS(i, head, total, mem_num);
            }
            
        }
        
    }
    
}

void DFSTrave() {
    for (int i = 1; i < cur_index; i++)
    {
        if (vis[i] == false)
        {
            int total = 0, head = i, mem_num = 0;
            DFS(i, head, total, mem_num);
            if (total > k && mem_num > 2)
            {
                gang[index_to_name[head]] = mem_num;
            }
            
        }
        
    }
    
}

int main() {
    fill(G[0], G[0] + maxn * maxn, 0);
    // input
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> str_a >> str_b >> t;
        int index_a = initStrToIndex(str_a);
        int index_b = initStrToIndex(str_b);
        G[index_a][index_b] += t;
        G[index_b][index_a] += t;
        weight[index_a] += t;
        weight[index_b] += t;
    }
 
    DFSTrave();
    cout << gang.size() << endl;
    map<string, int>::iterator it;
    for ( it = gang.begin(); it != gang.end(); it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}