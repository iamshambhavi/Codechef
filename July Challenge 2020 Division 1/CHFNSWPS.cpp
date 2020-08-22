#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr1[n],arr2[n],mini=INT_MAX;
		bool flag=false;
		for(int i=0;i<n;i++){
			cin>>arr1[i];
			mini=min(arr1[i],mini);
		}
		for(int i=0;i<n;i++){
			cin>>arr2[i];
			mini=min(arr2[i],mini);
		}
		map<int,int>m1,m2,total;
		for(int i=0;i<n;i++){
			m1[arr1[i]]++;
			m2[arr2[i]]++;
			total[arr1[i]]++;
			total[arr2[i]]++;
		}
		for(auto x:total){
			if(x.second%2!=0){
				cout<<-1<<endl;
				flag=true;
				break;
			}
			if(m1[x.first]==(x.second/2)){
				m1[x.first]=0;
				m2[x.first]=0;
			}
			else if(m1[x.first]<(x.second/2)){
				m1[x.first]=0;
				m2[x.first]-=(x.second/2);
			}
			else{
				m2[x.first]=0;
				m1[x.first]-=(x.second/2);
			}
		}
		if(flag)
		continue;
		int size=0;
		vector<pair<int,int>> totalswaps;
		for(auto x:m1){
			int i=0;
			while(i<x.second){
				totalswaps.push_back(make_pair(x.first,0));
				size++;
				i++;
			}
		}
		for(auto x:m2){
			int i=0;
			while(i<x.second){
				totalswaps[--size].second=x.first;
				i++;
			}
		}
		int ans=0;
		for(int i=0;i<totalswaps.size();i++){
			ans=ans+min(2*mini,min(totalswaps[i].first,totalswaps[i].second));
		}
		cout<<ans<<endl;
	}
}
