
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Record
{
    char name[25];
    int month;
    int day;
    int hour;
    int minute;
    bool state; //on-line or off-line
}records[1010], tmp;

bool cmp(Record a, Record b) {
    int s = strcmp(a.name, b.name);
    if (s != 0)
    {
        return s < 0;
    }
    else if (a.month != b.month )
    {
        return a.month < b.month;
    }
    else if (a.day != b.day)
    {
        return a.day < b.day;
    }
    else if(a.hour != b.hour )
    {
        return a.hour < b.hour;
    }
    else
    {
        return a.minute < b.minute;
    }
}

int single_price[24];
int n;


void get_time_amount(int on, int off, int &time, int &charge)
{
    tmp = records[on];

    while (tmp.day < records[off].day || tmp.hour < records[off].hour || tmp.minute < records[off].minute)
    {
        time++;
        charge += single_price[tmp.hour];
        tmp.minute++;
        if (tmp.minute >= 60)
        {
            tmp.minute = 0;
            tmp.hour++;
        }
        if (tmp.hour >= 24)
        {
            tmp.hour = 0;
            tmp.day++;
        }
        
        
    }
    
    
}


int main() {
    // input
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &single_price[i]);
    }
    scanf("%d", &n);
    char line[10];
    for (int i = 0; i < n; i++)
    {   
        
        scanf("%s %d:%d:%d:%d %s", records[i].name, &records[i].month, 
            &records[i].day, &records[i].hour, &records[i].minute, line);
        if (strcmp(line, "on-line") == 0)
        {
            records[i].state = true;
        }
        else
        {
            records[i].state = false;
        }
    }

    // sort
    sort(records, records + n, cmp);

    int on = 0, off, next = 0;

    while (on < n)
    {
        int flag = 0;
        next = on;
        while (next < n && !strcmp(records[next].name, records[on].name) )
        {
            if (flag == 0 && records[next].state)
            {
                flag = 1;
                // found on-line 
            }
            else if (flag == 1 && !records[next].state )
            {
                flag = 2;// found the pair
            }
            
            next++;
            
        }

        
        if (flag < 2)
        {
            on = next;
            continue;// enter the next round 
        }
        int sum = 0;
        // has found one pair
        printf("%s %02d\n", records[on].name, records[on].month);
        while (on < next) // for each name
        {   //for the name's each pair
            while (on < next - 1 && !(records[on].state && !records[on+1].state) )
            {
                // to find the continuous pair
                on++;
            }
            // have found the pair to print
            off = on+1;
            if (off == next)
            {
                // have outputed all the paired pairs
                on = next;
                break;
            }
            
            printf("%02d:%02d:%02d ", records[on].day, records[on].hour, records[on].minute);
            printf("%02d:%02d:%02d ", records[off].day, records[off].hour, records[off].minute);
            
            int tim = 0; 
            int amount = 0;
            get_time_amount(on, off, tim, amount);
            sum += amount;
            printf("%d $%.2f\n", tim, amount/100.0);

            on = off + 1; // finished a pair, to find next one from off+1 on
            
        }
            
        
        printf("Total amount: $%.2f\n", sum/100.0);
    }
    
    return 0;
}