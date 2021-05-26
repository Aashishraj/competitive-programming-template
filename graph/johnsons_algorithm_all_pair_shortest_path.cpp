/**
 * Author:  Aashish Raj

 * Created: 17-05-2021 15:45:15

 * Completed: 26-05-2021 16:19:30
 
 * Description: All pair shortest path in O(v*v*log(v) + v*e)
                https://www.geeksforgeeks.org/johnsons-algorithm/

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


typedef pair<int,int> pa;

void printpath(int par[],int i){
    if(par[i]==i){
        return;
    }
    printpath(par,par[i]);
    cout<<par[i]<<" ";
}



int* bellmanford(int v,vector<pair<int,int> > edges[]){
    int parent[v];
    int* weight=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=-1;   
        weight[i]=INT_MAX;
    }
    int sv=v-1;
    parent[sv]=sv;
    weight[sv]=0;
    //iterate v-1 times
    for(int k=0;k<v-1;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<edges[i].size();j++){
                int vertex1=i;
                int vertex2=edges[i][j].first;
                int w= edges[i][j].second;
                if( weight[vertex1]!=INT_MAX && w + weight[vertex1] < weight[vertex2]){
                    parent[vertex2]= vertex1;
                    weight[vertex2]= w + weight[vertex1];
                }
            }       
        }
        
    }


    for(int i=0;i<v;i++){
            for(int j=0;j<edges[i].size();j++){
                int vertex1=i;
                int vertex2=edges[i][j].first;
                int w= edges[i][j].second;
                if( weight[vertex1]!=INT_MAX && w + weight[vertex1] < weight[vertex2]){
                    cout<<"graph contains negative weight cycle"<<endl;
                    // return;
                }
            }       
    }

    return weight;
     //for each vertex weight
    // for(int i=0;i<v;i++){
    //     cout<<i<<" "<<weight[i]<<endl;
    // }

    //printing path
}

void Dijkstras(int sv,int v,vector<pair<int,int> > edges[]){
    bool visited[v];
    memset(visited,false,sizeof(visited));
    
    priority_queue< pa,vector<pa>, greater<pa> > q; 
    
    // starting vertex 0 as source
    
    //parent of each vertex and its minimum weight
    int par[v],weight[v];

    
    // every weight infinity
    for(int i=0;i<v;i++)weight[i]=INT_MAX;
    
    par[sv]=sv;
    weight[sv]=0;
    q.push({weight[sv],sv});



    while(!q.empty()){
        // take element having smallest weight and unvisited
        // from the queue

        int v_minw=q.top().second;// the node
        q.pop();

        visited[v_minw]=true;
        
        
        for(int i=0;i<edges[v_minw].size();i++){
            
            int nei=edges[v_minw][i].first;
            // weight of the edge connecting v_minw and nei
            int w=edges[v_minw][i].second;
            
            if(!visited[nei]){
                // fixing minimum weight for the neighbour
                if( w + weight[v_minw] < weight[nei] && w>=0){ 
                    weight[nei]= w + weight[v_minw];
                    par[nei]=v_minw;
                    q.push({weight[nei],nei});// first weight as sorted wrt to first element
                }
            }
            
        }

    }
    // cout<<sv<<endl;
    //for each vertex weight
    for(int i=0;i<v;i++){
        int a=i,b=par[i];
        cout<<weight[i]<<" ";
    
    }
    cout<<endl;
    //printing path
    // for(int i=0;i<v;i++){
    //     printpath(par,i);
    //     cout<<i<<endl;
    // }
}


void updateWeight(int v, vector<pair<int,int> > edges[],int *h){
    for(int i=0;i<v;i++){  
        for(int j=0;j<edges[i].size();j++){
            int u=i,v=edges[i][j].first;
            int w=edges[i][j].second;
            int new_w= w + h[u] - h[v];
            edges[i][j].second=new_w;
        }   
    }
}

void fun(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int> > edges[v],dummyedges[v+1];
    for(int i=0;i<e;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        edges[from].push_back({to,weight});
        //undirected
        // edges[to].push_back({from,weight});
        
        dummyedges[from].push_back({to,weight});  
        // dummyedges[to].push_back({from,weight});
        
    }
    for(int i=0;i<v;i++){
        dummyedges[v].push_back({i,0});
    }
    int *h=bellmanford(v+1,dummyedges);
    // cout<<"h"<<endl;
    // for(int i=0;i<v;i++){
    //     cout<<h[i]<<" ";
    // }
    // cout<<endl;
    updateWeight(v,edges,h);
//     cout<<"weight"<<endl;
    
//     for(int i=0;i<v;i++){
//         for(int j=0;j<edges[i].size();j++){
//             int u=i,v=edges[i][j].first;
//             int w=edges[i][j].second;
//             cout<<u<<" "<<v<<" "<<w<<endl;
//         }   
//     }
    for(int i=0;i<v;i++)
        Dijkstras(i,v,edges);

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