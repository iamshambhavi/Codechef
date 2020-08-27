#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
int arr[1000];
void solve(){
	int money=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int five=0;
	int ten=0;
	int fif=0;
	for(int i=0;i<n;i++){
	    if(arr[i]==5){
	        five++;
	        continue;
	    }else if(arr[i]==10){
	        if(five==0){
	            cout<<"NO\n";
	            return;
	        }
	        ten++;
	        five--;
	    }else{
	        if(ten>0){
	            ten--;
	            fif++;
	            continue;
	        }
	        if(five<2){
	            cout<<"NO\n";
	            return;
	        }
	        five-=2;
	        fif++;
	    }
	}
	cout<<"YES\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
