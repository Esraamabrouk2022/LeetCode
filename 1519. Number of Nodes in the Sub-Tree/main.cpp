class Solution {
public:

    vector<int> countSubTrees(int n, vector<vector<int>>&edges, string labels) {
      vector<vector<int>>tree(n);
     for(auto &edge:edges){
         tree[edge[0]].push_back(edge[1]);
         tree[edge[1]].push_back(edge[0]);
        }
         vector<int> ans(n);
         Dfs(0,-1,ans,tree,labels);
        return ans;
    }
    vector<int> Dfs(int node,int par,vector<int>&ans, vector<vector<int>>&tree,string &labels){
       vector<int>ret(26);
        ret[labels[node]-'a']++;
         for(auto child:tree[node]){
              if(child!=par){
             vector<int> subtree=Dfs(child,node,ans,tree,labels);
             for(int i=0;i<26;i++){
                 ret[i]+=subtree[i];
             }
            }
         }
         ans[node]=ret[labels[node]-'a'];
         return ret;
    }
};
