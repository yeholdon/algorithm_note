// get next array of string s whose length is len
void getNext(char s[], int len, int next[]) {
    // 1. init 
    int j = -1;
    next[0] = -1;
    //2. get next[1] to next[len-1]
    for (int i = 1; i < len; i++)
    {
        while (j != -1 && s[i] != s[j+1])
        {   // 3. repeat setting j as next[i]
            j = next[j];
        } // until j = -1 or s[i] == s[j+1]
        // 4. get next[i]
        if (s[i] == s[j+1])
        {
            j++;
        }
        next[i] = j;
    }
    
}