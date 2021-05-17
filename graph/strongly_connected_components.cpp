/**
 * Author:  Aashish Raj

 * Created: 15-05-2021 12:02:37

 * Completed: 
 
 * Description: Strongly connected components 
                kausaraju's algo, https://www.youtube.com/watch?v=RpgcYiky7uw&t=190s

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


// run dfs on the reversed graph ( same graph with counter direction of edges)
void dfs(vector<int> edges[],int sv,bool *visited,vector<int> &vec){
    vec.push_back(sv);
    visited[sv]=true;
    for(int i=0;i<edges[sv].size();i++){
        int neighbour=edges[sv][i];
        if(!visited[neighbour])
            dfs(edges,neighbour,visited,vec);
    }
}

void strongly_connected_component(int v,vector<int> edges[],vector<int> reversed_edges[],vector<vector<int>> &scc){
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)visited[i]=false;
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i])
            topologicalSort(edges,i,visited,s);
    }
    for(int i=0;i<v;i++)visited[i]=false;
    
    while(!s.empty()){
        int element=s.top();
        s.pop();
        if(!visited[element]){
            vector<int> vec;
            dfs(reversed_edges,element,visited,vec);
            scc.push_back(vec);
        }
    }
}


void fun(){

	int v, e;
    cin >>v>>e;

	vector<int> edges[v];
	//creating adjencency list for reversed edges
    vector<int> reversed_edges[v];
	for(int i=0;i<e;i++){
        int from,to;
      
        cin>>from>>to;
		//directed
     
        edges[from].push_back(to);
    	
        reversed_edges[to].push_back(from);
    }
    //sorting the adjencency list
    for(int i=0;i<v;i++){
		sort(edges[i].begin(),edges[i].end());
        sort(reversed_edges[i].begin(),reversed_edges[i].end());
    }


    vector<vector<int>> scc;
    strongly_connected_component(v,edges,reversed_edges,scc);
    for(int i=0;i<scc.size();i++){
        for(int j=0;j<scc[i].size();j++){
            cout<<(scc[i][j])<<" ";
        }
        cout<<endl;
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

