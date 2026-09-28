class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int ans=0;
        int i=0;

        while(i<s.size()){
            if(s[i]=='('){
                count+=1;
                ans=max(ans,count);
            }
            if(s[i]==')'){
                count-=1;
                ans=max(ans,count);
            }
            i++;
        }
        return ans;
    }
};