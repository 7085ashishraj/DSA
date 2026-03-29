class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        if(s1==s2) return true;
        // only 2 cases possible
        swap(s1[0],s1[2]);
        if(s1==s2)return true;

        swap(s1[0],s1[2]); //again back in original state

        swap(s1[1],s1[3]);
        if(s1==s2)return true;

        //since 1 and 3 already swappped above just swap 0 and 2 again and check if its equal
        swap(s1[0], s1[2]);
        
        return (s1==s2);
    }
};