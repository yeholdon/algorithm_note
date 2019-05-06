#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 10010;

char str1[maxn], str2[maxn];
bool hashTable[128] = {false};
int main() {
    
    fgets(str1, 10010, stdin);
    int len1 = strlen(str1);
    str1[len1-1] = '\0';
    
    fgets(str2, 10010, stdin);
    int len2 = strlen(str2);
    str2[len2-1] = '\0';
    
    for (int i = 0; i < len2; i++)
    {
        hashTable[str2[i]] = true;
    }
    
    for (int i = 0; i < len1; i++)
    {
        if (hashTable[str1[i]] == false)
        {
            printf("%c", str1[i]);
        }
        
    }
    
    

    return 0;
}