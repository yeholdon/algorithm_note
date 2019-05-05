
#include <cstdio>
#include <cstring>
struct SignTime
{
    char id[16];
    char in[10];
    char out[10];
} ans_in, ans_out, tmp;

void init() {
    //sprintf(ans_in.id, "%s", "0");
    sprintf(ans_in.in, "%s", "24:60:60");
    sprintf(ans_out.out, "%s", "00:00:00");
    // printf("%s", ans_in.in);
    // printf("%s", ans_out.out);
}
int n = 0;
int main() {
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %s", tmp.id, tmp.in, tmp.out);
        //here I use < to cmp char* directly, which id stupid!
        if (strcmp(tmp.in, ans_in.in) < 0) {
            ans_in = tmp;
        }
        if (strcmp(tmp.out, ans_out.out) > 0) {
            ans_out = tmp;
        }
        
        
    }
    printf("%s %s", ans_in.id, ans_out.id);
    
    


    return 0;
}

// to sum up
// in the reference answer, it stores the time value by int variables.
// and use a function to cmp it, which is not convenience enough.
// for me, I use the strcmp() to cmp the two time value, which is proved to 
// be feasible and more simple.
// conclusion: don't have blind faith in the std ans, try to think yourselves.