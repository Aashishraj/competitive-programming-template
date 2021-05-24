/**
 * Author:  Aashish Raj

 * Created: 23-05-2021 16:42:12

 * Completed: 24-05-2021 15:15:13
 
 * Description: all pair shortest path https://www.youtube.com/watch?v=LwJdNfdLF9s

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long

void findPath(int x,int y,int **path){
	if(path[x][y]==-1){
		return;
	}
	findPath(x,path[x][y],path);	
	cout<<path[x][y]<<"->";
}

void FloydWarshall(int v,int **edges){
	int distance[v][v];
	int **path=new int*[v];
    for(int i=0;i<v;i++){
    	path[i]=new int[v];
    }
    
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(edges[i][j]!=INT_MAX && i!=j){
				path[i][j]=i;
			}
			else{
				path[i][j]=-1;
			}
			distance[i][j]=edges[i][j];
		}
	}

	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){

				if(distance[i][k]==INT_MAX || distance[k][j]==INT_MAX)
					continue;
				if(distance[i][j]>distance[i][k]+distance[k][j]){
					distance[i][j]=distance[i][k]+distance[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<distance[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<path[i][j]<< " ";
		}
		cout<<endl;
	}

	int a=3,b=2;
	findPath(a,b,path);
	cout<<b;
}

void fun(){
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
    	edges[i]=new int[v];
    	for(int j=0;j<v;j++){
    		edges[i][j]=INT_MAX;
    	}	
    }
    for(int i=0;i<v;i++)
    	edges[i][i]=0;

    for(int i=0;i<e;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        edges[from][to]=weight;
        //undirected  
    }

    for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<edges[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;

    FloydWarshall(v,edges); 
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

