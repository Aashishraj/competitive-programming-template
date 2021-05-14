/**
 * Author:  Aashish Raj

 * Created: 14-05-2021 14:47:13

 * Completed: 14-05-2021 15:05:19
 
 * Description: bfs

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


void bfs(vector<int> edges[],int sv,bool visited[]){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
		int element=q.front();
        q.pop();
        cout<<element<<" ";
        for(int i=0;i<edges[element].size();i++){
			if(!visited[edges[element][i]]){
                q.push(edges[element][i]);
                //avoid adding multiple neighbours
                visited[edges[element][i]]=true;
            }
        }
    }
}


void fun(){
	int v,e;
    cin>>v>>e;
    vector<int> edges[v];

	for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
		edges[from].push_back(to);
    	// undirected
        edges[to].push_back(from);
    }

    for(int i=0;i<v;i++){
		sort(edges[i].begin(),edges[i].end());
    }


    // for(int i=0;i<v;i++){
    // 	for(int j:edges[i])
    // 		cout<<j<<" ";
    // 	cout<<endl;
    // }

    
    bool visited[v];
    memset(visited,false,sizeof(visited));
    
    //need to consider for discontinuous graph
    for(int i=0;i<v;i++){
    	if(!visited[i])
        	bfs(edges,i,visited);
    }
   
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		fun();
	}
	return 0;
}

