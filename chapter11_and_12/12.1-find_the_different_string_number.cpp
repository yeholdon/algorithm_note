/**
 * Given several string, 
 * you are supposed to find the number 
 * of different string
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// number system and mod
const int p = 10000019;
const int mod = 1000000007;
vector<int> ans; // to store the hash value of each string

// hashFunction
long long hashFun(string str) {
    long long H = 0;
    for (int i = 0; i < str.size(); i++)
    {
        H = (H*p + str[i] - 'a') % mod;
    }
    return H;
}


int main() {
    string str;

    while (getline(cin, str), str != "#") // "char *" can't be used in getline
    {
        long long id = hashFun(str);
        ans.push_back(id);
    }

    // sort
    sort(ans.begin(), ans.end());

    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 || ans[i] != ans[i-1])
        {
            count++;
        }
        
    }
    cout << count << endl;
    
    return 0;
}
