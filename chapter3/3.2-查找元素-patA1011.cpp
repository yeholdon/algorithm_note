
// note!:in this question, 
// we should notice that if we manually input, 
// the output and what we input would overlap for the code we write 
// is to output while input! 

#include <cstdio>

char res[3] = {'W', 'T', 'L'};
double a, ans = 1.0;
int main() {
    int idx = 0;
    for(int i = 0; i < 3; i++)
    {
        
        double tmp = 0.0;
        for(int j = 0; j < 3; j++)
        {
            
            scanf("%lf", &a);
            if (a > tmp) {
                tmp = a;
                idx = j;
            }
            
        }
        ans *= tmp;
        printf("%c ", res[idx]);

    }
    printf("%.2f", (ans*0.65 - 1) * 2);
    
    
    return 0;
}
