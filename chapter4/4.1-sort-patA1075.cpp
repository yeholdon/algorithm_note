
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

struct User
{
    int user_id;
    int sum_score;
    int partial_score[6];
    int solve;
    bool flag;
} user[maxn];

bool cmp(const User &a, const User &b ) {
    if (a.flag != b.flag)
    {
        return a.flag > b.flag;
    }
    else if(a.sum_score != b.sum_score )
    {
        return a.sum_score > b.sum_score;
    }
    else if (a.solve != b.solve)
    {
        return a.solve > b.solve;
    }
    else
    {
        return a.user_id < b.user_id;
    }
    
    
}
int n, k, m;
int full_marks[6];

void init() {
    for (int i = 1; i <= n; i++)
    {
        user[i].user_id = i;

        user[i].flag = false;
        for (int j = 0; j < 6; j++)
        {
            user[i].partial_score[j] = -1;
        }
        user[i].solve = 0;
        user[i].sum_score = 0;
        
    }
    
}


int main() {



    scanf("%d%d%d", &n, &k, &m);

    init(); // pay attention to the functions using the global variables and their invoking orders.
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &full_marks[i]);
    }

    // getchar();
    for (int i = 0; i < m; i++)
    {
        int id, p_n, p_s;
        scanf("%d%d%d", &id, &p_n, &p_s);
        // user[i].partial_score[p_n] = p_s;

        

        if ( !user[id].flag && p_s != -1)
        {
            user[id].flag = true;
        }
        //accelerate the sum score.
        if (p_s != -1)
        {
            if (user[id].partial_score[p_n] < p_s)
            {
                user[id].partial_score[p_n] = p_s;
            }
            
            // user[i].sum_score += user[i].partial_score[p_n];
        }

        if (p_s == -1 && user[id].partial_score[p_n] == -1)
        {
            user[id].partial_score[p_n] = 0;
        }
        
        

        
        
    }

    for (size_t i = 1; i <= n; i++)
    {

        for (int j = 1; j <= k; j++)
        {
            // count the perfectly solved problem number.
            if (user[i].partial_score[j] == full_marks[j])
            {
                
                user[i].solve++;
            }

            if (user[i].partial_score[j] != -1)
            {
                user[i].sum_score += user[i].partial_score[j];
            }
     
            
            
        }
        

    }
    


    
    // sort 
    sort(user +1 , user + n+1, cmp);

    
    int c_n = 1;
    for (int i = 1; i <= n && user[i].flag == true; i++)
    {


        if (i > 1 && user[i-1].sum_score != user[i].sum_score)
        {
            c_n = i;
        }
        
        printf("%d %05d %d", c_n, user[i].user_id, user[i].sum_score);

        for (int j = 1; j <= k; j++)
        {
            if (user[i].partial_score[j] == -1)
            {
                printf(" -");
            }
            else
            {
                printf(" %d", user[i].partial_score[j]);
            }
        }
        printf("\n");
        
        
  
        
        
    }
    
    

    return 0;
}