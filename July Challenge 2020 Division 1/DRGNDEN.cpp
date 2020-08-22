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
	int n,q;
	cin>>n>>q;
	int height[n+1],tastiness[n+1],nextLargest1[n+1],nextLargest2[n+1];
	for(int i=1;i<=n;i++){
		cin>>height[i];
	}
	for(int i=1;i<=n;i++){
		cin>>tastiness[i];
	}
	stack<int> s;
	s.push(1);
	nextLargest1[1]=-1;
	for(int i=2;i<=n;i++){
		while(s.size()!=0 && height[s.top()]<=height[i])
			s.pop();
		if(s.size()==0)
			nextLargest1[i]=-1;
		else
			nextLargest1[i]=s.top();
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	s.push(n);
	nextLargest2[n]=-1;
	for(int i=n-1;i>=1;i--){
		while(s.size()!=0 && height[s.top()]<=height[i])
			s.pop();
		if(s.size()==0)
			nextLargest2[i]=-1;
		else
			nextLargest2[i]=s.top();
		s.push(i);
	}
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			tastiness[b]=c;
		}else{
			if(b==c){
				cout<<tastiness[b]<<endl;
				continue;
			}else if(b<c){
				long long total=tastiness[c];
				int curr=c;
				while(b!=curr){
					curr=nextLargest1[curr];
					if(curr==-1){
						total=-1;
						break;
					}else if(curr<b){
						total=-1;
						break;
					}else{
						total=total+tastiness[curr];
					}
				}
				cout<<total<<endl;
				
			}else if(b>c){
				long long total=tastiness[c];
				int curr=c;
				while(b!=curr){
					curr=nextLargest2[curr];
					if(curr==-1){
						total=-1;
						break;
					}else if(curr>b){
						total=-1;
						break;
					}else{
						total=total+tastiness[curr];
					}
				}
				cout<<total<<endl;
			}
		}
	}
	return 0;
}



