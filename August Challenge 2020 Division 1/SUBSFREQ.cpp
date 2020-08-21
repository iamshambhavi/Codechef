#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll pre[500005];
vector<ll> result;
vector<ll> part;
vector<ll> ans;
ll modulo_power(ll x,ll y){
	if(y==0) return 1;
	ll a=modulo_power(x,y/2);
	ll ans=(a*a)%MOD;
	if(y%2!=0) ans=(ans*x)%MOD;
	return ans;
}
void gogo(ll n){
	ll calc=1;
	for(ll i=1;i<=n;i++){
		calc=(calc*result[i])%MOD;
		part[i]=(part[i]*calc)%MOD;
	}
}
void printSolution(){
	for(auto x:ans) cout<<x<<" ";
	cout<<"\n";
}
bool allOne(vector<ll>&freq,ll n){
	for(ll i=1;i<=n;i++) if(freq[i]!=1) return false;
	vector<ll> ans(n);
	ans[0]=1;
	for(ll i=1;i<n;i++) ans[i]=(ans[i-1]*2)%MOD;
	for(ll i=n-1;i>=0;i--) cout<<ans[i]<<" ";
	cout<<endl;
	return true;
}
int main(){
	pre[0]=1;
	for(ll i=1;i<=500000;i++) pre[i]=(pre[i-1]*i)%MOD;
	int t;
	cin>>t;
	for(ll i=0;i<t;i++){
		ll n;
		cin>>n;
		vector<ll> freq(n+1,0);
		for(ll j=0;j<n;j++){
			ll _;
			cin>>_;
			freq[_]++;
		}
		if(allOne(freq,n)) continue;
		part=result=vector<ll>(n+7,1);
		for(ll l=1;l<=n;l++){
			ll sum=1;
			for(ll j=1;j<=freq[l];j++){
				ll partial=(((pre[freq[l]]*modulo_power(pre[j],MOD-2))%MOD)*modulo_power(pre[freq[l]-j],MOD-2))%MOD;
				sum=(sum+partial)%MOD;
				part[j]=(part[j]*sum)%MOD;
			}
			result[freq[l]+1]=(result[freq[l]+1]*sum)%MOD;
		}
		gogo(n);
		ans=vector<ll>();
		for(ll j=1;j<=n;j++){
			ll calc=0,sum=1,x,y;
			for(ll k=1;k<=freq[j];k++){
				ll partial=(((pre[freq[j]]*modulo_power(pre[k],MOD-2))%MOD)*modulo_power(pre[freq[j]-k],MOD-2))%MOD;
				x=partial;
				y=partial;
				sum=(sum+x)%MOD;
				part[k]=(part[k]*modulo_power(sum,MOD-2))%MOD;
				x=(x*part[k])%MOD;
				part[k]=(part[k]*(sum-y+MOD))%MOD;
				calc=(calc+x)%MOD;
			}
			ans.push_back(calc);
		}
		printSolution();
	}
	return 0;
}



