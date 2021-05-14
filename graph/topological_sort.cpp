/**
 * Author:  Aashish Raj

 * Created: 14-05-2021 17:28:30

 * Completed: 
 
 * Description: 

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


void topologicalSort(vector<int> edges[],int sv,bool *visited,stack<int> &s){
	
    // cout<<sv<<" ";
	visited[sv]=true;
    for(int i=0;i<edges[sv].size();i++){
    	int neighbour=edges[sv][i];
		if(!visited[neighbour])
            topologicalSort(edges,neighbour,visited,s);
    }
    s.push(sv);
    // cout<<sv<<" ";
}

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
        // edges[to].push_back(from);
    }
    //sorting the adjencency list
    for(int i=0;i<v;i++){
		sort(edges[i].begin(),edges[i].end());
    }

    // for(int i=0;i<v;i++){
    // 	for(int j:edges[i])
    // 		cout<<j<<" ";
    // 	cout<<endl;
    // }




    bool *visited = new bool[v];
    for(int i=0;i<v;i++)visited[i]=false;
    
    //starting vertex
	// int sv=0;
    // dfs(edges,sv,visited);


    //need to consider for discontinuous graph
    stack<int> s;
    for(int i=0;i<v;i++){
    	if(!visited[i])
        	topologicalSort(edges,i,visited,s);
    }
   
    // cout<<endl<<"->";
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
    }
    cout<<endl;
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

