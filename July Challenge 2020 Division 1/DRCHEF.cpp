#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;long long x;
		cin>>n>>x;
		vector<long long> arr(n);
		for(long long i=0;i<n;i++) cin>>arr[i];
		sort(arr.begin(),arr.end());
		long long days=0;
		for(long long i=0;i<n;){
			if(arr[i]<x){
				while(i+1<n && arr[i+1]<=x) i++, days++;
				if(arr[i]!=x){
					if(i==n-1) i++,days++;
					else if(2*arr[i]<x) i++,days++;
					else{
					    x=2*arr[i];
						i++;
						days++;
					}
				}
			}else if(arr[i]>x){
				if(arr[i]>= 2*x){
					x*=2;
					days++;
				}else if(arr[i]!=x){
					if(i==n-1 || arr[n-1]>=2*x){
						days++;
						days++;
						x=arr[i]*2;
						i++;
					}else{
						while(i<n){
							days++;
							i++;
						}
						days++;
					}
				}
			}else if(arr[i]==x){
				days++;
				i++;
				if(i<n && arr[i]!=x)
				    x*=2;
			}
		}
		cout<<days<<endl;
	}
	return 0;
}



