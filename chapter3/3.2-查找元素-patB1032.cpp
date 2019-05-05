#include <cstdio>
const int max = 100010;
int n = 0;
int sch[max] = {0};
int max_num = 0;
int max_tmp = -1;
int main() {
    scanf("%d", &n);
    int num, tmp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &num, &tmp);
        sch[num] += tmp;
        if (max_tmp < sch[num]) {
            max_tmp = sch[num];
            max_num = num;
        }
        
    }
    printf("%d %d", max_num, max_tmp);

    
    return 0;
}