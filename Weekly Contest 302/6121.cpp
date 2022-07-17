class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
      int ans=-1;
      for(int i=0;i<nums.size();i++)
      {
        int sum=0,val=nums[i];
        while(val)
        {
          sum+=val%10;
          val/=10;
        }
        if(mp.find(sum)!=mp.end())
        {
          ans=max(ans,nums[i]+nums[mp[sum]]);
          if(nums[mp[sum]]<nums[i])
            mp[sum]=i;
        }
        else
          mp[sum]=i;
      }
      return ans;
    }
};
