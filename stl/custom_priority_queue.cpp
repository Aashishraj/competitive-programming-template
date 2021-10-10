class Solution {
public:
    struct comp{
      bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second<b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;
        
        for(pair<int,int> i:m)
            q.push(i);
        
        vector<int> ans;
        while(k--){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
