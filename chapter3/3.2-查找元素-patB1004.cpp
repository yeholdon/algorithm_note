#include <cstdio>
#include <cstring>
const int max_stu = 101;
const int max = 11;   //! note! Here the max must be more than 10 for the end should be left for the '\0'
struct Student
{
    char name[max];
    char id[max];
} stu[max_stu];

int n = 0;
char name[max];
char id[max];
int score = 0, min_tmp = 101, max_tmp = 0;
int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s%s%d", name, id, &score);
        if (score >= 0 && score < 101)  {
            if (max_tmp < score) {
                max_tmp = score;
            }
            if (min_tmp > score) {
                min_tmp = score;
            }
            strcpy(stu[score].name, name);
            strcpy(stu[score].id, id);
            
        }
        else
        {
            printf("input error!\n");
            return -1;
        }
        
        
    }
    printf("%s %s\n", stu[max_tmp].name, stu[max_tmp].id);
    printf("%s %s", stu[min_tmp].name, stu[min_tmp].id);
    return 0;
}