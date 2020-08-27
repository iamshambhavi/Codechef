#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count=0;
	int i=0;
	while(i+1<s.length()){
		if(s[i]!=s[i+1]){
			count++;
			i++;
		}
		i++;
	}
	cout<<count<<"\n";
	}
	return 0;
}
