/**
 * Author:  Aashish Raj

 * Created: 14-05-2021 14:46:46

 * Completed: 14-05-2021 15:42:22
 
 * Description: DFS

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long



void dfs(vector<int> edges[],int sv,bool *visited){
	cout<<sv<<" ";
	visited[sv]=true;
    for(int i=0;i<edges[sv].size();i++){
    	int neighbour=edges[sv][i];
		if(!visited[neighbour])
            dfs(edges,neighbour,visited);
    }
}


void fun(){

	int v, e;
    cin >>v>>e;

	vector<int> edges[v];
	
	//creating adjencency list
	for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
		edges[from].push_back(to);
    	// undirected
        edges[to].push_back(from);
    }
    //sorting the adjencency list
    for(int i=0;i<v;i++){
		sort(edges[i].begin(),edges[i].end());
    }



    bool *visited = new bool[v];
    for(int i=0;i<v;i++)visited[i]=false;
    
    //starting vertex
	// int sv=0;
    // dfs(edges,sv,visited);


    //need to consider for discontinuous graph
    for(int i=0;i<v;i++){
    	if(!visited[i])
        	dfs(edges,i,visited);
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

