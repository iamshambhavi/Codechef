#include<bits/stdc++.h>
#define MOD 1000000007
#define long long ll
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		int n=4*num-1;
		pair<int,int>p[n];
		for(int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
		}
		map<int,int>x;
		int countx=0,county=0;
		for(int i=0;i<n;i++){
			if(p[i].first<0)
			countx++;
			x[abs(p[i].first)]++;
		}
		map<int,int>y;
		for(int i=0;i<n;i++){
			if(p[i].second<0)
				county++;
			y[abs(p[i].second)]++;
		}
		for(int i=0;i<n;i++){
			if(p[i].first<0){
				p[i].first=abs(p[i].first);
			}
			if(p[i].second<0){
				p[i].second=abs(p[i].second);
			}
		}
		for(int i=0;i<n;i++){
			if(x[abs(p[i].first)]%2!=0){
				if(countx%2!=0)
				cout<<-p[i].first<<" ";
				else
				cout<<p[i].first<<" ";
				break;
			}	
		}
		for(int i=0;i<n;i++){
			if(y[abs(p[i].second)]%2!=0){
				if(county%2!=0)
				cout<<-p[i].second<<endl;
				else
				cout<<p[i].second<<endl;
				break;
			}	
		}
	}
}
