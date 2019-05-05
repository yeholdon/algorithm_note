#include <cstdio>

struct number {
    long long registerID;
    int tryID;
    int seatID;
}num[1001];
 int main() {

     int n = 0;
      
     scanf("%d", &n);
     for(int i = 0; i < n; i++) {
         scanf("%lld%d%d", &num[i].registerID, &num[i].tryID, &num[i].seatID);
     }
     int M = 0;
     int seat;
     scanf("%d", &M);
     for(int i = 0; i < M; i++) {
         scanf("%d", &seat);
         for(int j = 0; j < n; j++) {
             if(seat == num[j].tryID) {
                 printf("%014lld %d\n", num[j].registerID, num[j].seatID);
             }
         }
     }
     return 0;
 }