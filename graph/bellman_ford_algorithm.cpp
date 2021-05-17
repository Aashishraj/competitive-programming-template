/**
 * Author:  Aashish Raj

 * Created: 17-05-2021 17:25:23

 * Completed: 
 
 * Description: 	shortest path of all vertex from a source node
 					works with negative weights 
 					https://www.youtube.com/watch?v=-mOEd_3gTK0

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


void printpath(int par[],int i){
	if(par[i]==i){
		return;
	}
	printpath(par,par[i]);
	cout<<par[i]<<" ";
}

void bellmanford(int v,vector<pair<int,int> > edges[]){
	int parent[v];
	int weight[v];
	for(int i=0;i<v;i++){
		parent[i]=-1;	
		weight[i]=INT_MAX;
	}
	int sv=0;
	parent[sv]=sv;
	weight[sv]=0;
	//iterate v-1 times
	for(int k=0;k<v-1;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<edges[i].size();j++){
				int vertex1=i;
				int vertex2=edges[i][j].first;
				int w= edges[i][j].second;
				if( w + weight[vertex1] < weight[vertex2]){
					parent[vertex2]= vertex1;
					weight[vertex2]= w + weight[vertex1];
				}
			}		
		}
		
	}
	 //for each vertex weight
    for(int i=0;i<v;i++){
        cout<<i<<" "<<weight[i]<<endl;
    }

    //printing path
    for(int i=0;i<v;i++){
        printpath(parent,i);
        cout<<i<<endl;
    }
}

void fun(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> > edges[v];
    for(int i=0;i<e;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        edges[from].push_back({to,weight});
        //undirected
        edges[to].push_back({from,weight});  
    }
    bellmanford(v,edges); 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		fun();
	}
	return 0;
}
