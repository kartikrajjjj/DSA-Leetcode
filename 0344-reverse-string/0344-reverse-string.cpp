//recurssive solution
class Solution {
public:

    void reversalString( int i, int j , vector<char>& s){
    if(i==j || i>j) return ;
    swap(s[i],s[j]);
    reversalString(i+1,j-1,s);
    }

    void reverseString(vector<char>& s) {
        reversalString(0,s.size()-1,s);
    }
};