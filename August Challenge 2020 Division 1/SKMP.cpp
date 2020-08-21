#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s,p;
		cin>>s>>p;
		int frequency[26];
		for(int i=0;i<26;i++) frequency[i]=0;
		for(auto x:s) frequency[x-'a']++;
		for(auto x:p) frequency[x-'a']--;
		int mid=p[0]-'a';
		for(auto x:p){
			if(x==p[0])
				continue;
			if(x<p[0])
				mid--;
			break;
		}
		for(int i=0;i<=mid;i++){
			for(int j=1;j<=frequency[i];j++) cout<<(char)(i+'a');
		}
		cout<<p;
		for(int i=mid+1;i<26;i++){
			for(int j=1;j<=frequency[i];j++) cout<<(char)(i+'a');
		}
		cout<<endl;
	}
	return 0;
}



