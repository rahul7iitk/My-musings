#include <bits/stdc++.h>

using namespace std;
#define big unsigned long long
const  big INF = 4294967296; // 2 to the power 32

/*bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
} */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t; // test cases
    
    while(t-->0){
        int price; cin>>price;
        int vertices; cin>>vertices; // vertices 
        int streets; cin>>streets; // streets are nothing but edges
        
        vector<pair<int,int>> city[vertices];  // city is the name of the graph, with 'vertices' and 'streets' as edges
        
        for(int i=0;i<streets;i++){
            
            int city_a,city_b, length;
            
            cin>>city_a>>city_b>>length; // one indexing so decrementing
            city_a--; city_b--;
            
            city[city_a].push_back(make_pair(city_b,length)); // undirected graph , weighted  graph, so making connections
            city[city_b].push_back(make_pair(city_a,length));
        }
        
       int visited[vertices]; int parent[vertices]; // visited and parent arrays , as usual
       
       for(int i=0;i<vertices;i++){
           visited[i] = 0;
           parent[i] = -1;
       }
       
       priority_queue<pair<big,int>, vector<pair<big,int>> , greater<pair<big,int>> > que; // this syntax is default for minimum priority queue , don't change
      
      vector<pair<big,int>> pq(vertices , make_pair(0,0)); // this vector is for storing the weights of the vertices
      
      for(int i=0;i<vertices;i++) // standard MST procedure , no need to change
        pq[i]=make_pair(INF,i);
        
      pq[0].first = 0;    
        
      que.push(pq[0]);
      parent[0] = 0;
      
      int last = 0; // last is the last node to exit out from MST
      
      while(!que.empty()){
          
          int key = que.top().second;
         
          last = key;
          
          que.pop();
          
          visited[key] = 1;
          
          for(int i=0;i<city[key].size();i++){
             // cout<<pq[city[key].at(i).first].second<<endl;
              
              if(visited[city[key].at(i).first]==0 && pq[city[key].at(i).first].first>city[key].at(i).second)
              {
                  //cout<<"Hello "<<key<<" "<<city[key].at(i).first<<endl;
                  pq[city[key].at(i).first].first = city[key].at(i).second;
                  que.push(pq[city[key].at(i).first]);
                  parent[city[key].at(i).first] = key;
              }
          }
      }
      // from here the code evaluates the minimum total path length of the graph
      int start = last; big total_cost = 0;
      
     // for(int i=0;i<vertices;i++)
      //  cout<<parent[i]<<endl;
     
      for(int i=0;i<vertices;i++){ // this code will just calculate the path length between a vertex and its parent in the MST formed 
          
          if(parent[i]!=i){ 
              for(int j=0;j<city[i].size();j++){

                  if(city[i].at(j).first==parent[i]){
                      total_cost+=city[i].at(j).second;
                      break;
                  }
              }
          }
      }
      //cout<<start<<endl;
      total_cost *= price;
      
      cout<<total_cost<<endl; 
      
    }
    return 0;
	
}
