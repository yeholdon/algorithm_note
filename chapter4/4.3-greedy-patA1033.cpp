#include <cstdio>
#include <algorithm>
#include <utility> // pair is in <utility> header
using namespace std;

const int INF = 10000000;

pair<double, double > station[510];

bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
    return a.second < b.second;
}

double Cm, D, Davg;
int N;
int main() {
    scanf("%lf %lf %lf %d", &Cm, &D, &Davg, &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lf %lf", &station[i].first, &station[i].second);
    }
    // if (station[N].second == D)
    // {
    //     station[N].first = 0;

    // }

    station[N+1].first = 0;
    station[N+1].second = D;
    
    // sort by the distance
    sort(station + 1, station + N + 1, cmp);
    
    if (station[1].second != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int sta_i = 1; // current station
    double rad = Cm*Davg;
    
    double ans = 0.0;
    double cur_t = 0.0; // current distance

    while (sta_i < N + 1)
    {
        double minPrice = INF;
        // double edge = station[sta_i].second + rad;
        int k = -1; // record the index of the minPrice station
        for (int i = sta_i +1; i <= N + 1 && station[i].second - station[sta_i].second<= rad; i++)
        {
            if (station[i].first < minPrice)
            {
                minPrice = station[i].first;
                k = i;

                if (minPrice < station[sta_i].first)
                {
                    // have found the first staion where the price is lower than current station
                    break;
                }
                
            }
            
        }
        
        if (k == -1)
        {
            break;
            // can't find any fit station
        }


        // transition to the next found station
        double need_gas = (station[k].second - station[sta_i].second)/Davg;
        if (minPrice < station[sta_i].first)
        {
            // current stations transfer to the state1
            
            if (need_gas > cur_t)
            {
                ans += (need_gas - cur_t)*station[sta_i].first;
                cur_t = 0;
            }
            else
            {
                cur_t -= need_gas; 
            }

            
        }
        else
        {
            ans += (Cm - cur_t)*station[sta_i].first;;
            cur_t = Cm - need_gas; 
        }
        // come to station k
        sta_i = k;
        
        
    }
    
    if (sta_i == N + 1)
    {
        printf("%.2f", ans);
    }
    else
    {
        printf("The maximum travel distance = %.2f", station[sta_i].second + rad);
    }
    
    return 0;
}