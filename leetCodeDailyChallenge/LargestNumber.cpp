class Solution {
public:
    static bool mycmp(string a,string b){
        string total1 = a + b;
        string total2 = b + a;
        return total1 > total2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto i:nums){
            snums.push_back(to_string(i));
        }
        sort(snums.begin(),snums.end(),mycmp);

        if(snums[0] == "0"){
            return "0";
        }

        string ans = "";
        for(auto str:snums){
            ans = ans + str;
        }
        return ans;
    }
};