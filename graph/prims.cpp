/**
 * Author:  Aashish Raj

 * Created: 16-05-2021 13:08:45

 * Completed: 17-05-2021 14:15:23
 
 * Description: algorithm https://www.youtube.com/watch?v=mqKPgW3C5ps

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


typedef pair<int,int> pa;



void prims_mst(int v,vector<pair<int,int> > edges[]){
    bool visited[v];
    memset(visited,false,sizeof(visited));
    
    priority_queue< pa,vector<pa>, greater<pa> > q; 
    
    // starting vertex 0 as source
    q.push({0,0});

    //parent of each vertex and its minimum weight
    int par[v],weight[v];


    par[0]=-1;
    weight[0]=0;

    // every weight infinity
    for(int i=1;i<v;i++)weight[i]=INT_MAX;
    


    while(!q.empty()){
        // take element having smallest weight and unvisited
        // from the queue

        int v_minw=q.top().second;// the node
        q.pop();
//      cout<<v_minw<<endl;
        visited[v_minw]=true;
        
        
        for(int i=0;i<edges[v_minw].size();i++){
            
            int nei=edges[v_minw][i].first;
            // weight of the edge connecting v_minw and nei
            int w=edges[v_minw][i].second;
            
            if(!visited[nei]){
                // fixing minimum weight for the neighbour
                if( w < weight[nei] && w>0){ 
                    weight[nei]=w;
                    par[nei]=v_minw;
                    q.push({w,nei});// first weight as sorted wrt to first element
                }
            }
        }

    }

    for(int i=1;i<v;i++){
        int a=i,b=par[i];
        cout<<min(a,b)<<" "<<max(a,b)<<" "<<weight[i]<<endl;
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
    prims_mst(v,edges); 
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

