
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxm = 110;

struct Student
{
    int id;
    int choices[6];
    int GE;
    int GI;
    int GF;
    int rank;
} stu[maxn];

struct School
{
    int id;
    int quota;
    int cur;// current admisson num;
    int admissions[maxn];
    int lastAdmit;
} sch[maxm];

bool cmp(Student &a, Student &b) {
    if (a.GF != b.GF)
    {
        return a.GF > b.GF;
    }
    else if (a.GE != b.GE)
    {
        return a.GE > b.GE;
    }
    else
    {
        return a.id < b.id;
    }
    
}

// bool cmpID(int &a, int &b) {
//     return stu[a].id < stu[b].id;
// }

int n, m, k;//n:the number of applicants, m: the number of schools, k:the number of choices
int main() {



    // input
    scanf("%d%d%d", &n, &m, &k);

    // init
    for (int i = 0; i < m; i++)
    {
        sch[i].id = i;
        sch[i].cur = 0;
        sch[i].lastAdmit = -1;
    }
    

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sch[i].quota);
    }

    for (int i = 0; i < n; i++)
    {
        stu[i].id = i;
        scanf("%d%d", &stu[i].GE, &stu[i].GI);
        // because the average of GE and GI can be decimal, so 
        // just use the sum of GE and GI to repalce their average for convenience.
        stu[i].GF = stu[i].GE + stu[i].GI;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &stu[i].choices[j]);
        }
        
    }


    // sort
    sort(stu, stu + n, cmp);

    // set the rank
    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            stu[i].rank = i;
        }
        else
        {
            if (stu[i].GF == stu[i-1].GF)
            {
                if (stu[i].GE == stu[i-1].GE)
                {
                    stu[i].rank = stu[i-1].rank;
                    continue;
                }
                
            }
            stu[i].rank = i;
        }
        
    }

/*   
    // traverse the stu[]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int ch = stu[i].choices[j];
            if (sch[ch].quota > sch[ch].cur)
            {
                sch[ch].admissions[sch[ch].cur] = stu[i].id;
                sch[ch].cur++;
                if (!sch[ch].flag)
                {
                    sch[ch].flag = true;
                }
                break;
            }
            else if (sch[ch].cur > 0 && stu[i].rank == sch[ch].admissions[sch[ch].cur - 1]) 
            {
                sch[ch].admissions[sch[ch].cur] = stu[i].id;
                sch[ch].cur++;
                if (!sch[ch].flag)
                {
                    sch[ch].flag = true;
                }
                break;
            }
            else continue;
            
            
        }
        
    }
*/


    // traverse th stu[]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int ch = stu[i].choices[j];
            int cur = sch[ch].cur;
            int last = sch[ch].lastAdmit;
            
            if (cur < sch[ch].quota || (last != -1 && stu[i].rank == stu[last].rank))
            {
                sch[ch].admissions[cur] = stu[i].id;
                sch[ch].lastAdmit = i;
                sch[ch].cur++;
                break;
            }
            
        }
        
    }

    // sort the every sch.admissons[]
    for (int i = 0; i < m; i++)
    {
        sort(sch[i].admissions, sch[i].admissions + sch[i].cur);// default in ascending order
    }
    
    
    // output
    for (int i = 0; i < m; i++)
    {
        // printf("%d", i);
        if (sch[i].cur > 0)
        {
            // printf("%d", sch[i].cur);
            for (int j = 0; j < sch[i].cur; j++)
            {
                if (!j)
                {
                    printf("%d", sch[i].admissions[j]);
                }
                else
                {
                    printf(" %d", sch[i].admissions[j]);
                }
                
                
            }
        }

        printf("\n");
        
    }
    
    
    return 0;
}

/*
1.
Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4


2.
Sample Input:
5 5 3
0 0 0 5 5
100 100 0 1 2 
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1
Sample Output:





*/