#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;

int calc(string pattern,int n,map<string,int>& w){
	string small;
	int len=0;
	int ans=0;
	for(auto x:pattern){
		small=small+x;
		len++;
		int i=0,j=0;
		while(1){
			j=j%len;
			if(pattern[i]!=small[j])
				break;
			if(i==n-1){
				ans=(ans+w[small])%MOD;
			}
			i++;
			j++;
		}
	}
	return ans;
}
int modInverse(int a, int m){
	int m0=m;
	int y=0,x=1;
	if(m==1)
		return 0;
	while(a>1){
		int q=a/m;
		int t=m;
		m=a%m,a=t;
		t=y;
		y=x-q*y;
		x=t;
	}
	if(x<0)
		x+=m0;
	return x; 
} 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		vector<int> freq(26);
		set<string> se;
		map<string,int> m;
		map<string,int>w;
		cin>>s;
		int sum=0;
		for(int i=0;i<26;i++) cin>>freq[i];
		for(int i=0;i<s.length();i++){
			string small;
			int total=0;
			for(int j=i;j<s.length();j++){
				small=small+s[j];
				total=total+freq[s[j]-97];
				se.insert(small);
				m[small]=m[small]+1;
				if(w.count(small)==0)
					w[small]=total;
				sum++;
			}
		}
		int ans=0;
		auto itr=se.begin();
		while(itr!=se.end()){
			string value=*itr;
			int small=calc(value,value.length(),w);
			ans=(ans+(m[value]*small)%MOD)%MOD;
			itr++;
		}
		ans=(ans*modInverse(sum,MOD))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}



