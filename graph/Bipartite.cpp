#include <bits/stdc++.h>
using namespace std;



//using dfs recursion ( can be done with bfs too but it will be more long and complex than dfs)

 bool Bipartite(int sv,bool visited[],vector<vector<int> >& graph, int color[] ,int curr_color) {
	visited[sv]=true;
	color[sv]=curr_color;
	for(int i=0;i<graph[sv].size();i++){
		int neighbour=graph[sv][i];
		if(!visited[neighbour] && !Bipartite(neighbour,visited,graph,color,curr_color^1)){
			return false;
		}
		else{
			if(color[sv]==color[neighbour])
				return false;
		}
	}
	return true;
}

bool isBipartite(vector<vector<int> >& graph) {
	int e=graph.size();
	bool *visited=new bool[e];
	fill(visited, visited+e, false);
	int *color=new int[e];
	fill(color, color+e, 0);
    bool ans=true;
	for(int i=0;i<e;i++){
        if(!visited[i])
            ans = ans && Bipartite(i,visited,graph,color,0);
    }
    return ans;
}


//using bfs
/*

bool check_bipartite(int sv,vector<vector<int> > &v,bool *visited){
	set<int> s[2];
	queue<int> q;
	s[0].insert(sv);
	q.push(sv);
	visited[sv]=true;
	while(!q.empty()){
		int val=q.front();
		q.pop();
		int curSet=s[0].count(val)>0?0:1;
		for(int i=0;i<v[val].size();i++){
			int nei=v[val][i];
			if(s[0].count(nei)==0 && s[1].count(nei)==0){// neighbour element is not present in any set
				s[1-curSet].insert(nei);// insert in oppsite set of current set
				q.push(nei);
				visited[nei]=true;
			}
			else if(s[curSet].count(nei)>0)// if neighbour element is present in the same set then false
				return false;
		}
	}
	return true;
}
    
bool isBipartite(vector<vector<int> >& graph) {
	int e=graph.size();
	bool *visited=new bool[e];
	fill(visited, visited+e, false);
	bool ans=true;
	for(int i=0;i<e;i++){
        if(!visited[i])
            ans = ans && check_bipartite(i,graph,visited);
        
    }
    return ans;
}

*/



int main(){
	int e;// no of edges
	cin>>e; 	
	vector< vector<int> > v(e);
	//undireted graph adjecency list
	for(int i=0;i<e;i++){
		int s,d;
		cin>>s>>d;
		s--;d--;// if the vectices are starting from 1 (and not 0)
		v[s].push_back(d);
		v[d].push_back(s);
	}
	//running the funciton Bipartite
	if(isBipartite(v)){
		cout<<"Yes it is Bipartite and all the vertices and be alternately coloured into two colours"<<endl;
	}
	else{
		cout<<"not possible to alternately colour the vertices with two colours"<<endl;
	}
}
