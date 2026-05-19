class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(auto i:s){
            if(isalnum(i))
                t.push_back(tolower(i));
        }
        s=t;
        reverse(t.begin(),t.end());
        return (s==t);
    }
};