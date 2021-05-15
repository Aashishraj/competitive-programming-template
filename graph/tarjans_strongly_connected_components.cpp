/**
 * Author:  Aashish Raj

 * Created: 15-05-2021 13:03:27

 * Completed: 
 
 * Description: tarjans_algorithm
 				it is a point that disconnects
 				the graph on removal

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


void tarjans(int sv,int disc[],int low[],vector<int> edges[],vector<vector<int>> &scc,stack<int> &s,bool instack[],int &time){
	disc[sv]=low[sv]=++time;
	s.push(sv);
	instack[sv]=true;

	for(int i=0;i<edges[sv].size();i++){
		int neighbour=edges[sv][i];
		if(disc[neighbour]==-1){// unvisited
			tarjans(neighbour,disc,low,edges,scc,s,instack,time);
			low[sv]=min(low[sv],low[neighbour]);
		}
		else if(instack[neighbour]){// backegde
			low[sv]=min(low[sv],disc[neighbour]);
		}
	}

	// scc code starts
	vector<int> vec;
	if(low[sv]==disc[sv]){// sv is the headnode of scc
		while(!s.empty()){
			int ele=s.top();
			vec.push_back(ele);
			instack[ele]=false;
			s.pop();
			if(ele==sv){
				break;
			}
		}
		scc.push_back(vec);
	}
}

void strongly_connected(int v,vector<int> edges[]){
	int disc[v],low[v];

    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
    	disc[i]=low[i]=-1;
    	visited[i]=false;
    }
    stack<int> s;
	int time=0;
	vector<vector<int>> scc;
	for(int i=0;i<v;i++){
    	if(disc[i]==-1)
        	tarjans(i,disc,low,edges,scc,s,visited,time);
    }

    //sort if you want
	for(int i=0;i<scc.size();i++){
	    sort(scc[i].begin(),scc[i].end());
	}   
	 sort(scc.begin(),scc.end());



    for(int i=0;i<scc.size();i++){
        for(int j=0;j<scc[i].size();j++){
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
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
        
    }
    //sorting the adjencency list
    for(int i=0;i<v;i++){
		sort(edges[i].begin(),edges[i].end());
    }


    strongly_connected(v,edges);
    //starting vertex
	// int sv=0;
    // dfs(edges,sv,visited);


    //need to consider for discontinuous graph
    
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

