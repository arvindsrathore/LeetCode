// https://leetcode.com/problems/integer-to-english-words/description/

class Solution {
public:
    void removeSpaces(string &str) {
        int n = str.length();
        int i = 0, j = -1;
        bool spaceFound = false;

        while (++j < n && str[j] == ' ');

        while (j < n) {
            if (str[j] != ' ') {
                if ((str[j] == '.' || str[j] == ',' || str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ')
                    str[i - 1] = str[j++];
                else
                    str[i++] = str[j++];
                spaceFound = false;
            } else if (str[j++] == ' ') {
                if (!spaceFound) {
                    str[i++] = ' ';
                    spaceFound = true;
                }
            }
        }

        if (i <= 1)
            str.erase(str.begin() + i, str.end());
        else
            str.erase(str.begin() + i - 1, str.end());
    }

    map<int,string> mp;
    string f(int n){
        if(n==0)    return "";
        string num = to_string(n);
        string ans = "";
        if(num.size()==1){
            return mp[num[0]-'0'];
        }
        if(num.size()==3)ans = ans + mp[num[0]-'0'] + " Hundred ";
        if(num.size()==2)   num = "0" + num;
        if(num[1]<='1'){
            int now = (num[1]-'0')*10+(num[2]-'0');
            ans = ans + mp[now];
        }
        else{
            int now = (num[1]-'0')*10;
            ans = ans + mp[now] ;
            if(num[2]!='0'){
            now = (num[2]-'0');
            ans = ans + " " + mp[now];}
        }
        return ans;
    }
    string numberToWords(int n) {
        if(n==0)    return "Zero";
        mp[1] = "One";  mp[11] = "Eleven";
        mp[2] = "Two";  mp[12] = "Twelve";
        mp[3] = "Three";    mp[13] = "Thirteen";
        mp[4] = "Four"; mp[14] = "Fourteen";
        mp[5] = "Five"; mp[15] = "Fifteen";
        mp[6] = "Six";  mp[16] = "Sixteen";
        mp[7] = "Seven";    mp[17] = "Seventeen";
        mp[8] = "Eight";    mp[18] = "Eighteen";
        mp[9] = "Nine"; mp[19] = "Nineteen";
        mp[10] = "Ten";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";

        string ans = "";
        string o = f((n%1000000000000)/1000000000);
        string p = f((n%1000000000)/1000000);
        string q = f((n%1000000)/1000);
        string r = f(n%1000);
        if(o.size())    ans = ans + o + " Billion ";
        if(p.size())    ans = ans + p + " Million ";
        if(q.size())    ans = ans + q + " Thousand ";
        if(r.size())    ans = ans + r;
        ans+=" ";
        removeSpaces(ans);
        return ans;
    }
};