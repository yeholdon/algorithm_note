
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[110], b[100], tgt[110], nxt[110];

bool isSame(int *a, int *b, const int &len) {
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
        
    }
    return true;
    
}

bool mergeSort(int *toSort, int *target, int len) {
    bool flag = false;
    for (int step = 2; step/2 <= n; step*=2)
    {   // step/2 <= n  ensure that the last merge contain all element
        for (int i = 0; i < len ; i+=step)
        {
            sort(toSort + i, toSort + min(len, i + step));
        }

        if (flag)
        {
            for (int i = 0; i < len; i++)
            {
                nxt[i] = toSort[i];
            }
            break;
        }
        
        if (isSame(toSort, target, len))
        {
            flag = true;
        }
    }
    
    return flag;
    
}

bool insertSort(int *toSort, int *target, int len) {
    bool flag = false;
    int i, j;
    for (i = 1; i < len; i++)
    {
        int tmp = toSort[i];
        for (j = i; j > 0 && toSort[j-1] > tmp; j--)
        {
            // moving backward one by one 
            toSort[j] = toSort[j-1];   
        }
        toSort[j] = tmp;

        if (flag)
        {
            for (int i = 0; i < len; i++)
            {
                nxt[i] = toSort[i];
            }
            break;
        }

        if (isSame(toSort, target, len))
        {
            flag = true;
        }
        
    }
    return flag;
    
}

void showArray(int *a, int len) {
    for (int i = 0; i < len; i++)
    {
        if (i)
        {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    
}

int main() {

    // input 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tgt[i]);
    }
    
    bool flag = false;
    flag = mergeSort(a, tgt, n);
    // if(flag) showArray(next, n);
    if (flag)
    {
        printf("Merge Sort\n");
        showArray(nxt, n);
    }
    else 
    {
        flag = insertSort(b, tgt, n);
        if (flag)
        {
            printf("Insertion Sort\n");
            showArray(nxt, n);
        }
        
    }
    
    return 0;
}