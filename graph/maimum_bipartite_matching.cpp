/**
 * Author:  Aashish Raj

 * Created: 25-05-2021 14:06:55

 * Completed: 29-05-2021 12:14:07
 
 * Description: https://www.geeksforgeeks.org/maximum-bipartite-matching/

 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

//adjacency matrix
bool dfs(int sv,vector<vector<int>> &edges,bool visited[],int par[]){
	
	//for the vertex sv, which job it can take
	for(int job=0;job<edges[sv].size();job++){
		if(edges[sv][job]>0 && (!visited[job])){
			visited[job]=true;
			//already job given
			if(par[job]<0  || dfs(par[job],edges,visited,par)){
				par[job]=sv;
				return true;
			}
		}
	}
	return false;
}


int mbm(vector<vector<int>>&G){
	int m=G.size();
        int n=G[0].size();
        int count=0;
        bool visited[n];
        int par[n];
        for(int i=0;i<n;i++)par[i]=-1;
        
        for(int i=0;i<m;i++){
            for(int i=0;i<n;i++)visited[i]=false;
        
            if(dfs(i,G,visited,par)){
                count++;
            
                // cout<<i<<true<<endl;
            }
           
        }	    
        // for(int i=0;i<n;i++)
            // cout<<par[i]<<" ";
        // cout<<endl;
        return count;
}


// vector<vector<int>> listToMatrix()


void fun(){
    int m, n;
	cin >> m >> n;
	vector<vector<int>>G(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			cin >> G[i][j];
	}
    cout<<mbm(G)<<endl;
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