
#include <cstdio>

struct Info
{
    char name[11];
    char id[11];
    int score;
} F, M, tmp;

void init() {
    F.score = -1;
    M.score = 101;
}


int n = 0;
char gender;
int main() {

    init();//!!! remeber to call init() 
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %c %s %d", tmp.name, &gender, tmp.id, &tmp.score);
        if (gender == 'M' && tmp.score < M.score) {
            M = tmp;
        }
        if (gender == 'F' && tmp.score > F.score) {// else if instead of if
            F = tmp;
        }
        
        
    }
    if (F.score == -1) {
        printf("Absent\n");
        printf("%s %s\n%s", M.name, M.id, "NA");
    }
    else if (M.score == 101) {
        printf("%s %s\n%s\n%s", F.name, F.id, "Absent", "NA");
        
    }
    else
    {
        printf("%s %s\n%s %s\n%d", F.name, F.id, M.name, M.id, F.score-M.score);
    }
    
    return 0;
}


