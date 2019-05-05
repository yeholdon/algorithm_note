#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main() {
	//input
	LL a, b, da, db;
	scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
	LL pa = 0, pb = 0;
	//judge the da&db number
	while(a!=0){
		if(a%10 == da){
			pa = pa*10 + da;
		}
		a /= 10;
	}
	while(b != 0){
		if(b%10 == db){
            pb = pb*10 + db;
        }
        b /= 10;
    }
    printf("%lld\n", pa + pb);	
	return 0;
}
