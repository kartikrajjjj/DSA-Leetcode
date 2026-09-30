class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char i : s){
            if(i=='*'){
                if(!ans.empty()) ans.pop_back();
            }
            else ans.push_back(i);
        }
        return ans;
        
    }
};