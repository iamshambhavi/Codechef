#include<bits/stdc++.h>
#define ll long long
#define MAXN 3010
using namespace std;

ll dp[MAXN][MAXN];
vector<vector<ll>> removed;
ll v[MAXN];
ll gogo(ll color,ll k){
	if(color==0)
		return 0;
	if(dp[color][k]!=-1)
		return dp[color][k];
	ll ans=LONG_MAX;
	for(int i=0;i<removed[color].size();i++){
		ll totalValue=v[color]*i;
		if(totalValue>k)
			break;
		ans=min(ans,gogo(color-1,k-totalValue)+removed[color][i]);
	}
	dp[color][k]=ans;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		memset(dp,-1,sizeof(dp));
		int n,c,k;
		cin>>n>>c>>k;
		map<int,int> m[c+1];
		for(int i=0;i<n;i++){
			int _,waste,color;
			cin>>_>>waste>>color;
			m[color][_]++;
		}
		for(int i=1;i<=c;i++){
			cin>>v[i];
		}
		vector<vector<int>> colors(c+1);
		for(int i=1;i<=c;i++){
			for(auto x:m[i]){
				colors[i].push_back(x.second);
			}
		}
		removed=vector<vector<ll>>(c+1);
		for(int i=1;i<=c;i++){
			sort(colors[i].begin(),colors[i].end());
			int count=0;
			for(auto x:colors[i]) count+=x;
			removed[i]=vector<ll>(count+1);
			for(int j=0;j<=count;j++){
				vector<int> small=colors[i];
				int deleted=j;
				for(int l=0;l<small.size();l++){
					if(deleted==0)
						break;
					int pleaseDelete=min(small[l],deleted);
					small[l]=small[l]-pleaseDelete;
					deleted=deleted-pleaseDelete;
				}
				ll sum=0;
				for(auto x:small) sum=sum+x;
				removed[i][j]=(sum*(sum-1)*(sum-2)/6);
				for(auto x:small){
					removed[i][j]=removed[i][j]-(x*(x-1)*(sum-x)/2)-(x*(x-1)*(x-2)/6);
				}
			}
		}
		cout<<gogo(c,k)<<endl;
	}
	return 0;
}



