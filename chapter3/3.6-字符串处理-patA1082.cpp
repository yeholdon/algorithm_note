
#include <cstdio>
#include <cstring>

char f[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main() {

    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if (str[0] == '-') {
        printf("Fu");
        left++;
    }
    while(left+4 <= right){// make left and right be in the same section.
        right -= 4;
    }
    while(left < len){
        bool flag = false;
        bool isPrint = false;
        while(left <= right){
            if (left > 0 && str[left] == '0') {
                flag = true;
            }
            else
            {
                if (flag == true) {
                    printf(" ling");
                    flag = false;
                }

                if (left > 0) {// if it's not the first digit, ouput a blank 
                    printf(" ");
                }
                printf("%s", f[str[left] - '0']);
                isPrint = true;

                if (left != right) {
                    printf(" %s", wei[right - left -1]);
                }
                
                
                
            }
            left++;
        } // finish handle a section
        if (isPrint == true && right != len - 1) {
            printf(" %s", wei[(len - right - 1)/4 + 2]);
        }
        right += 4;
        
    }
   
    return 0;
}