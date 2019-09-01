#include <bits/stdc++.h>
#define int unsigned int
const int maxn = 1e6+10;
#define eps 1e-8
using namespace std;
int n,p,q,m,SA,SB,SC;
int rng61(){
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^SA;
	return SC;
}
stack<int >s;

void gen(){
	cin>>n>>p>>q>>m>>SA>>SB>>SC;
	for(int i = 1; i <= n;i++){
		if(rng61() % (p+q) < p){
            int tmp = rng61() % m + 1;
            cout << tmp << endl;
        }
		else cout << "pop"<<endl;
	}
}
main()
{
	int t;
	cin>>t;
	while(t--){
		gen();
	}
}

