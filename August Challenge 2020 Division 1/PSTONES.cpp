#include<bits/stdc++.h>
#define MAXN 103
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,k;
	int weight[MAXN];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int _;
			cin>>_>>_>>weight[i];
			--weight[i];
		}
		int l=0;
		while(l<n){
			set<int> s;
			for(int j=0;j+l<n;j++){
				int offset=0;
				if(j>=1)
					offset=offset|(1<<weight[j-1]);
				if(j+l<n-1)
					offset=offset|(1<<weight[j+l]);
				s.insert(offset);
			}
			int overall=pow(2,k);
			for(int i=1;i<=overall;i++){
				if(s.find(i-1)!=s.end()) cout<<"1";
				else cout<<"0";
			}
			l++;
			cout<<endl;
		}
	}
	return 0;
}



