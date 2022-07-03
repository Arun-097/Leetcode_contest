class Solution {
public:
    string decodeMessage(string key, string message) {
      int n=key.size(),m=message.size();
      string lower="abcdefghijklmnopqrstuvwxyz";
      unordered_map<char,char> mp;
      char ch='a';
      int j=0;
      for(int i=0;i<n;i++)
      {
        
        if(key[i]!=' ' && mp.find(key[i])==mp.end())
        {
         
          mp[key[i]]=lower[j++];
          
        }
          
      }
      // for(auto it:mp)
      //   cout<<it.first<<it.second<<"  ";
      string ans="";
      for(int i=0;i<m;i++)
      {
        if(message[i]==' ')
        {
          ans+=' ';
        }
        else
        {
          ans+=mp[message[i]];
        }
      }
      return ans;
    }
};
