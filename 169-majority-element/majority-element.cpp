class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(auto x : nums){
            mp[x]++;
        }
        for(auto i : mp){
            if(i.second>n/2) return i.first;
        }
        return -1;
    }
};