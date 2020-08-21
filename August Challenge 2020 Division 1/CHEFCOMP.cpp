#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		vector<vector<int>> edges(n);
		int arr[n];
		int people[n];
		int fruits[n];
		for(int i=1;i<=n-1;i++){
			int _1,_2;
			cin>>_1>>_2;
			edges[--_1].push_back(--_2);
			edges[_2].push_back(_1);
		}
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			cin>>people[i];
		}
		for(int i=0;i<n;i++){
			cin>>fruits[i];
		}
		int days[n]={0};
		bool visited[n]={0};
		for(int i=0;i<n;i++){
			visited[arr[i]-1]=true;
			int sub=min(people[arr[i]-1],fruits[arr[i]-1]);
			if(sub){
				fruits[arr[i]-1]=fruits[arr[i]-1]-sub;
				if(!fruits[arr[i]-1])
					days[arr[i]-1]=i+1;
			}
			bool newVisited[n]={0};
			newVisited[arr[i]-1]=true;
			queue<int> pendingNodes;
			pendingNodes.push(arr[i]-1);
			while(!pendingNodes.empty()){
				int currentNode=pendingNodes.front();
				pendingNodes.pop();
				for(auto x:edges[currentNode]){
					if(visited[x] || newVisited[x])
						continue;
					newVisited[x]=true;
					pendingNodes.push(x);
					int sub=min(people[arr[i]-1],fruits[x]);
					if(sub){
						fruits[x]=fruits[x]-sub;
						if(!fruits[x])
							days[x]=i+1;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(!days[i])
				cout<<"-1 ";
			else
				cout<<days[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}



