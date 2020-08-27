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
	int n;
	cin>>n;
	int arr[n][n];
	int a=1;
	for(int i=0;i<n;i++){
		if(i%2!=0){
		for(int j=n-1;j>=0;j--){
				arr[i][j]=a++;
		}
		}else{
			for(int j=0;j<n;j++){
				arr[i][j]=a++;	
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	}
	return 0;
}
