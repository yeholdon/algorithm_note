/**
 * 1. use cnt to count the whole index, 
 * 2. i and j are the pointers of s1 and s2 respectively
 * 3. medianPos = (m + n - 1)/2 (index starts from 0)
 */
#include <cstdio>

const int maxn = 200010;
const int INF = (1L<<31) - 1; // <-> 0x7fffffff

int n1, n2;
int s1[maxn];
// int s2[maxn];
int main() {
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &s1[i]);
    }

    scanf("%d", &n2);

    s1[n1] = INF; // this method is more concise

    int medianPos = (n1 + n2 - 1)/2;
    int cnt = 0, i = 0, j = 0, tmp;
    scanf("%d", &tmp);
    while (cnt < medianPos)
    {
        if (s1[i] <= tmp)
        {
            i++;
        }
        else
        {
            j++;
            if (j < n2)
            {
                scanf("%d", &tmp);

            }
            else if (j == n2)
            {
                tmp = INF;
            }
            
            
        }

        cnt++;
    }
     
    if (s1[i] < tmp) // note: here, why my method flag doesn't work
    {
        printf("%d", s1[i]);
    }
    else
    {
        printf("%d", tmp);
    }
    
    return 0;
}
/**
 3 1 2 3 
 6 2 3 4 5 6 7
 3
 * 
 * actually, the last pointers changed is j, but the answer is the element i points.
 */



/**
 * 1. use cnt to count the whole index, 
 * 2. i and j are the pointers of s1 and s2 respectively
 * 3. medianPos = (m + n - 1)/2 (index starts from 0)
 */

/*
#include <cstdio>

const int maxn = 200001;
const int INF = 0x7fffffff;

int n1, n2;
int s1[maxn], s2[maxn];
int main() {
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &s1[i]);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &s2[i]);
    }

    s1[n1] = s2[n2] = INF;

    int medianPos = (n1 + n2 - 1)/2;
    int cnt = 0, i = 0, j = 0;
    int flag = false;
    while (cnt < medianPos)
    {
        // if (i < n1 && j < n2)
        // {
        //     if (s1[i] < s2[j])
        //     {
        //         i++;
        //         flag = true;
        //     }
        //     else
        //     {
        //         j++;
        //         flag = false;
        //     }
        // }
        // else if(i == n1)
        // {
        //     j++;
        //     flag = false;
        // }
        // else if (j == n2)
        // {
        //     i++;
        //     flag = true;
        // }

        if (s1[i] < s2[j])
        {
            i++;
        }
        else
        {
            j++;
        }

        cnt++;
    }
     
    if (s1[i] < s2[j]) // note: here, why my method flag doesn't work
    {
        printf("%d", s1[i]);
    }
    else
    {
        printf("%d", s2[j]);
    }
    
    return 0;
}
*/
/**
 * 3 1 2 3 
 * 6 2 3 4 5 6 7
 * 3
 * 
 * actually, the last pointers changed is j, but the answer is the element i points.
 */