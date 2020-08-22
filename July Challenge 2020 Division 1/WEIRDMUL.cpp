#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using namespace std;

int power(int a, int n)  // using Binary Exponential in TC O(logn)
{                    
    int res=1;
    while(n)
    {
        if(n%2) 
        res=(res*a)%MOD ,n--;
        else
        a=(a*a)%MOD ,n/=2;
    }
    return res;
}

int32_t main(){
	int t;
	cin>>t;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(t--){
		int n,x;
		cin>>n>>x;
		int dumb[n];
		for(int i=0;i<n;i++){
			cin>>dumb[i];
		}
		int total=power(dumb[n/2],n*(n+1));
		int sum=1;
		int dp[n];
		dp[0]=x;
		for(int i=1;i<n;i++){
			dp[i]=(dp[i-1]*x)%MOD;
			
		}
		for(int i=0;i<n-1;i++){
			sum=(sum+dp[i])%MOD;
			total=(total*power(sum,2*(n-i-1)))%MOD;
		}
		cout<<total<<endl;
	}
	return 0;
}
