#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int k){
	vector<int> family(101,0);
	int ans=k;
	for(auto x:arr){
		if(family[x]){
			family=vector<int>(101,0);
			ans=ans+k;
		}
		family[x]++;
	}
	return ans;
}

int maxTwoTables(vector<int>& arr,int k){
	vector<int> secondPart(101,0);
	int ans=k;
	for(auto x:arr){
		secondPart[x]++;
		if(secondPart[x]==2) ans=ans+2;
		else if(secondPart[x]>2) ans++;
	}
	int prev=ans-k;
	vector<int> firstPart(101,0);
	int cost=2*k;
	int curr=0;
	for(int i=0;i<arr.size()-1;i++){
		firstPart[arr[i]]++;
		if(firstPart[arr[i]]==2) curr=curr+2;
		else if(firstPart[arr[i]]>2) curr++;
		secondPart[arr[i]]--;
		if(secondPart[arr[i]]==1) prev=prev-2;
		else if(secondPart[arr[i]]>=2) prev--;
		ans=min(ans,cost+prev+curr);
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(auto &x:arr) cin>>x;
		int ans=partition(arr,k);
		ans=min(ans,maxTwoTables(arr,k));
		cout<<ans<<"\n";
	}
	return 0;
}



