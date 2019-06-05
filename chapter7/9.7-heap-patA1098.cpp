#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
int origin[maxn], tmp[maxn], tmp_tgt[maxn];

bool isSame(int a[], int b[], int n) {
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
        
    }
    return true;
    
}

void downAdjust(int low, int high) {
    int i = low, j = i*2;

    while (j <= high)
    {
        if (j + 1 <= high && tmp[j] < tmp[j + 1])
        {
            j++;
        }

        if (tmp[i] < tmp[j])
        {
            swap(tmp[i], tmp[j]);
            i = j;
            j = 2*i;  
        }
        else break;
    }
    
    
}

void createHeap(int n) {
    for (int i = n/2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
    
} 

bool insertSort(int n) {
    bool flag = false;
    for (int i = 2; i <= n; i++)
    {
        if (i != 2 && isSame(tmp, tmp_tgt, n))
        {
            flag = true;
        }
        
        int now = tmp[i];
        int j = i;
        while (j > 1)
        {
            if (tmp[j-1] > now)
            {
                tmp[j] = tmp[j-1];
                j--;
            }
            else
            {
                break;
            }
        }
        tmp[j] = now;

        if (flag == true)
        {
            return true;
        }
        
        
    }
    return false;
}



bool heapSort(int n) {
    bool flag = false;
    
    createHeap(n);
    for (int i = n; i > 1; i--)
    {
        if (i != n && isSame(tmp, tmp_tgt, n))
        {
            flag = true;
        }
        swap(tmp[i], tmp[1]);
        downAdjust(1, i-1);
        if (flag == true)
        {
            
            return true;
        }
        
    }
    return false;
}

void showArray(int n) {
    for (int i = 1; i <= n; i++)
    {
        printf("%d", tmp[i]);
        if (i < n)
        {
            printf(" ");
        }
        
    }
    
}

int main() {
    int n, e;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &e);
        tmp[i] = origin[i] = e;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &e);
        tmp_tgt[i] = e;
    }
    
    if (insertSort(n))
    {
        printf("Insertion Sort\n");
        showArray(n);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            tmp[i] = origin[i];
        }
        heapSort(n);
        printf("Heap Sort\n");
        showArray(n);
    }
    
    
    
    return 0;
}