#include <cstdio>
#include<queue>

using namespace std;

const int maxm = 1290;
const int maxn = 130;
const int maxl = 65;

struct Node
{
    int x, y, z;
} node;
// global variables can be initialized default
int ma[maxl][maxm][maxn];
bool inq[maxl][maxm][maxn];
// input
int m, n, l, t;
// increment array
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, -1, 1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
    if (x < 0 || y <0 || z < 0 || x >= m || y >= n || z >= l)
    {
        return false;
    }
    
    if (ma[z][x][y] == 0 || inq[z][x][y] == true)
    {
        return false;
    }
    
    return true;
    
}

int BFS(int x, int y, int z) {
    queue<Node> q;
    int num = 0;
    node.x = x, node.y = y, node.z = z;
    inq[z][x][y] = true; // remember to set the start point
    q.push(node);
    while (!q.empty())
    {
        num++;
        Node top = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ) == true) {
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                q.push(node);
                inq[newZ][newX][newY] = true;
            }
        }
        
    }
    return num;   
}

int main() {
    // input
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &ma[i][j][k]);
            }
            
        }
        
    }

    int ans = 0;
    for (int z = 0; z < l; z++)
    {
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (inq[z][x][y] == false && ma[z][x][y] == 1)
                {
                    int tmp = BFS(x, y ,z);
                    if (tmp >= t)
                    {
                        ans += tmp;
                    }
                }
                
            }
            
        }
        
    }

    printf("%d\n", ans);
    
    return 0;
}