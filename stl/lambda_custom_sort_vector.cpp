class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(pair<int,int> i:m)
            v.push_back(i);
        sort(begin(v),end(v),[](pair<int,int> a,pair<int,int> b){
           return a.second>b.second; 
        });
        vector<int> ans;
        for(pair<int,int> i:v){
            if(k==0)
                break;
            ans.push_back(i.first);
            k--;
        }
        return ans;
    }
};
