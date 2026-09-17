class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefix=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int toFind=prefix-k;
            if(mp.find(toFind)!=mp.end()){
                count+=mp[toFind];
            }
            mp[prefix]+=1;
        }
        return count;
    }
};