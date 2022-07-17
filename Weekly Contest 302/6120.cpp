vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
      for(auto it:nums)
        mp[it]++;
      int p=0,l=0;
      for(auto it:mp)
      {
        p+=it.second/2;
        l+=it.second%2;
      }
      return {p,l};
    }
