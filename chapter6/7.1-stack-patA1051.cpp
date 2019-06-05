#include <cstdio>
#include <stack>
const int maxn = 1001;

int n, m, k;
int s[maxn][maxn];
int a;
std::stack<int> st;

void clear(std::stack<int> &st) {
    while (!st.empty())
    {
        st.pop();
    }
    
}

int main() {
    // input 
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
        }
        
    }
    
    for (int i = 0; i < k; i++)
    {
        clear(st);
        int cnt = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {   
            // current pop element 
            a = s[i][j];            
            while ((!st.empty() && st.top() != a) || st.empty())
            {   
                cnt++;

                st.push(cnt);
                if (cnt > n || st.size() > m)
                {
                    // printf("NO\n");
                    flag = false;
                    break;
                }
            }

            
            if (flag)
            {
                st.pop();
            }
            else
            {
                break;
            }
        }

        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}