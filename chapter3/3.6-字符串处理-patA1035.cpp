
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct Info
{
    char username[12];
    char pwd[12];
    bool is_change;
} T[1010];


void crypt(Info &t, int &cnt) {

    for(int i = 0; i < strlen(t.pwd); i++)
    {
        if (t.pwd[i] == '1') {
            t.pwd[i] = '@';
            t.is_change = true;
        }
        else if (t.pwd[i] == '0') {
            t.pwd[i] = '%';
            t.is_change = true;
        }
        else if (t.pwd[i] == 'l') {
            t.pwd[i] = 'L';
            t.is_change = true;
        }
        else if (t.pwd[i] == 'O') {
            t.pwd[i] = 'o';
            t.is_change = true;
        } 
        
    }

    if (t.is_change) {
        cnt++;
    }
    
}

int n = 0;
char usr_n[12], pwd[12];
int main() {
    scanf("%d", &n);
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%s%s", T[i].username, T[i].pwd);
        T[i].is_change = false;
        crypt(T[i], cnt);
    }
    if (cnt) {
        printf("%d\n", cnt);
        for(int i = 0; i < n; i++)
        {
            if (T[i].is_change) {
                printf("%s %s\n", T[i].username, T[i].pwd);
            }
            
        }
        
    }
    else
    {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        }
        else
        {
            printf("There are %d accounts and no account is modified", n);
        }

    }
    
    
    return 0;
}