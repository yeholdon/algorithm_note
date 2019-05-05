#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main() {
	//input
	string a, b;
	LL da, db, A, B;
	cin>>a>>da>>b>>db;
	string pa, pb;
	//judge the da&db number
	for(int i = 0; i < a.size(); i++) {
		if (a[i] == to_string(da)[0]) {
			pa.push_back(a[i]);
		}
		
	}

	for(int i = 0; i < b.size(); i++)
	{
		if (b[i] == to_string(db)[0]) {
			pb.push_back(b[i]);
		}
		
	}

	printf("%lld\n", atoll(pa.c_str()) + atoll(pb.c_str()));
	
	return 0;
}
