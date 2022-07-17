class Solution {
public:
    int find_gcd(int x,int y)
    {
      if(x==0)
        return y;
      if(y==0)
        return x;
      if(x>y)
        return find_gcd(x%y,y);
      return find_gcd(x,y%x);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size(),m=numsDivide.size();
        int gcd=numsDivide[0],ans=0;
        for(int i=1;i<m;i++)
          gcd=find_gcd(gcd,numsDivide[i]);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
          if(gcd%nums[i]==0)
            return ans;
          else
            ans++;
        }
      return -1;
    }
};
