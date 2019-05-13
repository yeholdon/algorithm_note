/*
1. use String to store the number segments
2. compare the S1 + S2 with S2 + S1(lexicographical order) to determine the order
3. sort the strings and output them one by one
4. erase the leading zeros
5. pay attention to the situation where there was nothing to output, we should output a zero
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 100010;

bool cmp(string &a, string &b) {
    return a + b < b + a;
}

int n = 0;
string str[maxn];
string ans;
int main() {
    // input
    scanf("%d", &n);
    for (int  i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    
    // sort 
    sort(str, str + n, cmp);

    for (int i = 0; i < n; i++)
    {
        ans += str[i];
    }

    while (ans.size() != 0 && ans[0] == '0')
    {
        // while there is leading zero in ans, erase it
        ans.erase(ans.begin());
    }

    if (ans.size() == 0)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
    
    return 0;
}