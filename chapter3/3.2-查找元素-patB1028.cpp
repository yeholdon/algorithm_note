#include <cstdio>

const int max = 6;
struct Birthday
{
    char name[max];
    int year;
    int month;
    int day;
} birthday, oldest_tmp, youngest_tmp, left, right;

int n = 0;
// !note: struct variable cannot be assignment value in global field.
// today.year = 2014;
// today.month = 9;
// today.day = 4;

void init() {
    oldest_tmp.year = right.year = 2014;
    oldest_tmp.month = youngest_tmp.month = left.month = right.month = 9;

    youngest_tmp.year = left.year = 1814;
    oldest_tmp.day = youngest_tmp.day = left.day = right.day = 6;
}

bool greaterEqu( const Birthday &a, const Birthday &b) {
    if (a.year != b.year ) {
        return a.year >= b.year;
    }
    else if (a.month != b.month ) {
        return a.month >= b.month;
    }
    else
    {
        return a.day >= b.day;
    }
    
    
    
}

bool lessEqu( const Birthday &a, const Birthday &b) {
    if (a.year != b.year) {
        return a.year <= b.year;
    }
    else if (a.month != b.month) {
        return a.month <= b.month;
    }
    else
    {
        return a.day <= b.day;
    }
    
    
    
}


int main() {
    scanf("%d", &n);
    int num = 0;

    init();
    for(int  i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", birthday.name, &birthday.year, &birthday.month, &birthday.day);
        if (greaterEqu(birthday, left) && lessEqu(birthday, right)) {
            num++;
            if (lessEqu(birthday, oldest_tmp)) {
                oldest_tmp = birthday;
            }
            if (greaterEqu(birthday, youngest_tmp)) {
                youngest_tmp = birthday;
            }
            
            
        }
        
        
    }

    if (num == 0) {
        printf("0");
    }
    else
    {
        printf("%d %s %s", num, oldest_tmp.name, youngest_tmp.name );
    }

    return 0;
}