#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v_c;

stack<int> st;
int n;

void dfs(int vertex,v_c matrix[],int visited[]){
    
    v_c key = matrix[vertex];
    
    for(int i=0;i<key.size();i++)
    {
        if(!visited[key.at(i)]){
            
            visited[key.at(i)] = 1;
            dfs(key.at(i),matrix,visited);
        }
    }
    //cout<<vertex<<endl;
    st.push(vertex);
}
void reverse(v_c matrix[],v_c matrix_rev[]){
    
    for(int i=0;i<n;i++){
        
        v_c key = matrix[i];
        
        for(int j=0;j<key.size();j++){
            int b = key.at(j);
            matrix_rev[b].push_back(i);
        }
    }
    
}

void dfs(int vertex,v_c matrix[],int visited[],v_c* component){
    
    v_c key = matrix[vertex];
    
    for(int i=0;i<key.size();i++)
    {
        if(!visited[key.at(i)]){
            
            visited[key.at(i)] = 1;
            
            (*component).push_back(key.at(i));
            
            dfs(key.at(i),matrix,visited,component);
        }
    }
    
}

bool compare(pair<v_c,int> a, pair<v_c,int> b){
    return a.second<b.second;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //int n;
    cin>>n;
    
    v_c matrix[n];
    
    for(int i=0;i<n;i++){
        int a; cin>>a;
        while(a!=-1){
            matrix[i].push_back(a);
            cin>>a;
        }
    }
    
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    //visited[0] = 1;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i,matrix,visited);
        }
    }
    
    v_c matrix_rev[n];
    reverse(matrix,matrix_rev);
    
    vector<v_c> comp; int counter = 0;
    
    for(int i=0;i<n;i++)
        visited[i] = 0;
    
    while(!st.empty()){
        int a = st.top();
        //cout<<a<<endl;
        st.pop();
        if(!visited[a]){
            
            visited[a] = 1;
            v_c component;
            component.push_back(a);
            dfs(a,matrix_rev,visited,&component);
            
            comp.push_back(component);
        }
    }
    
    int number = comp.size();
    
    pair<v_c,int> arr[number];
    
    for(int i=0;i<number;i++){
        v_c temp = comp.at(i);
        int k = temp.size();
        
        int a = *min_element(temp.begin(),temp.begin()+k);
        
        arr[i] = make_pair(temp,a);
    }
    
    sort(arr,arr+number,compare);
    
    unordered_map<int,int> dict;
    
    v_c matrix3[number];
    
    for(int i=0;i<number;i++)
    {
        v_c a = arr[i].first;
        for(int j=0; j<a.size(); j++)
            dict[a.at(j)] = i;
    }
    
    for(int i=0;i<number;i++){
        
        int marking[number];
        
        for(int l=0;l<number;l++)
            marking[l] = 0;
        marking[i] = 1;
        
        v_c a = arr[i].first;
        
        for(int j=0; j<a.size();j++){
            
            int k = a.at(j);
            
            for(int p=0;p<matrix[k].size();p++){
                int b = matrix[k].at(p);
                
                if(dict[b]!=i && marking[dict[b]]==0){
                    matrix3[i].push_back(dict[b]);
                    marking[dict[b]] = 1;
                }
                
            }
        }
    }
    
    for(int i=0;i<number;i++){
        v_c a = matrix3[i];
        int k = a.size();
        sort(a.begin(),a.begin()+k);
        matrix3[i] = a;
    }
    
    cout<<number<<endl;
    
    for(int i=0;i<number;i++){
        v_c a = matrix3[i];
        
        for(int j=0;j<a.size();j++){
            
            cout<<a.at(j)<<" ";
        }
        
        cout<<"-1"<<endl;
    }
    
    return 0;
    
    
}

