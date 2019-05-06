#include <cstdio>
#include <algorithm>
#include <utility> // pair is in <utility> header
using namespace std;

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
    if (station[N].second == D)
    {
        station[N].first = 0;

    }

    station[N+1].first = 0;
    station[N+1].second = D;
    
    // sort by the distance
    sort(station + 1, station + N + 2, cmp);
    
    if (station[1].second != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    int sta_i = 1; // current station
    int i_tmp;
    double ans = 0.0;
    double sta_d = 0.0; // current distance
    bool flag = false;

    while (sta_d < D)
    {
        i_tmp = sta_i + 1;
        double edge = station[sta_i].second + Cm*Davg;
        while (station[i_tmp].second <= edge)
        {
            
            if (station[i_tmp].first < station[sta_i].first)
            {
                flag = true;
                // add cost
                // come to the first station of which the gas is cheaper than the current station
                ans += station[sta_i].first * (station[i_tmp].second - station[sta_i].second);
                sta_i = i_tmp;
                break;
            }
            i_tmp++;
            
        }
        if (!flag)
        {
            // can't find the target station
            // find the station which owns the cheapest gas within the current max reachable range
            i_tmp = sta_i;
            double min = 21.0;
            while (station[i_tmp].second <= edge)
            {
                
                if (station[i_tmp].first < min)
                {
                    min = station[i_tmp].first;
                }
                i_tmp++;
            }
            if (i_tmp == sta_i + 1)
            {
                // there is no such a station
                double max_d = station[sta_i].second + Davg*Cm;
            }
            else
            {
                
            }
            
            
            
        }
        
        
        
    }
    
    
    
    return 0;
}