
/**
 * Author:  Aashish Raj

 * Created: 17-05-2021 14:47:03

 * Completed: 
 
 * Description: https://www.youtube.com/watch?v=rbKcTM3RREw

 */


#include <bits/stdc++.h>
using namespace std;
#define int long long


struct edge{
	int s,d,w;
};

struct pset{
	int rank,par;
};


bool comp(edge a,edge b){
	return a.w<b.w;
}

int findfun(int p,pset parent[]){
	if(p==parent[p].par)
		return p;
	return parent[p].par=findfun(parent[p].par,parent);// path compression
}

void form_cluster(int a,int b,pset parent[]){
	if(parent[a].rank > parent[b].rank){// smaller rank element becomes
		parent[b].par=parent[a].par;	// the child and bigger element, parent
	}
	else{
		parent[a].par=parent[b].par;
		if(parent[a].rank == parent[b].rank){
			parent[b].rank++;
		}
	}
}

bool iscycle(int a,int b,pset parent[]){
	int par_a=findfun(a,parent);
	int par_b=findfun(b,parent);
	
	if(par_a==par_b){// they are in same cluster
		return true;
	}

	form_cluster(par_a,par_b,parent);
	return false;
}


void kruskal_mst(int v,int e,edge edges[]){
	// sort wrt weight
	sort(edges,edges+e,comp);
	
	//creating the parent array with rank compression
	pset parent[v];
	for(int i=0;i<v;i++){
		parent[i].rank=0;
		parent[i].par=i;
	}
	
	int count=0;
	int curr=0;
	edge ans[v-1];
	while(count<v && curr<e){
		if(!(iscycle(edges[curr].s,edges[curr].d,parent))){
			//we are including the edge in the mst
			ans[count++]=edges[curr];
		}
		curr++;
	}

	// for(int i=0;i<v;i++){
	// 	cout<<parent[i].rank<<" "<<parent[i].par<<endl;
	// }
	
	for(int i=0;i<v-1;i++){
        int a=ans[i].s,b=ans[i].d;
		cout<<min(a,b)<<" "<<max(a,b)<<" "<<ans[i].w<<endl;
	}
}



void fun(){
	int n,e;
	cin>>n>>e;
	struct edge arr[e]; 
	for(int i=0;i<e;i++){
		cin>>arr[i].d>>arr[i].s>>arr[i].w;
	}
	kruskal_mst(n,e,arr);
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


