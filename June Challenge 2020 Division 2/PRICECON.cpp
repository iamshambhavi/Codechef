#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//PRICEKON
int n,k;
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
	int sum=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a>k){
			sum+=a-k;
		}
	}
	cout<<sum<<"\n";
	}
	return 0;
}
