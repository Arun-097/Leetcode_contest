class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
          priority_queue<pair<string,int>> pq;
          int k=queries[i][0],s=queries[i][1];
          for(int j=0;j<n;j++)
          {
            string str=nums[j].substr(nums[j].size()-s);
            if(pq.size()<k)
              pq.push({str,j});
            else
            {
              if(pq.top().first>str)
              {
                pq.pop();
                pq.push({str,j});
              }
            }
          }
          ans[i]=pq.top().second;
        }
      return ans;
    }
};
