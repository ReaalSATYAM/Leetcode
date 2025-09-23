class Solution {
private:
    vector<string> createTokens(string str){
        stringstream ss(str);
        string token = "";
        vector<string> tokens;
        while(getline(ss, token, '.'))
            tokens.push_back(token);
        return tokens;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = createTokens(version1);
        vector<string> v2 = createTokens(version2);

        int m = v1.size(), n = v2.size(), i = 0;
        while(i < m || i < n){
            int a = i < m? stoi(v1[i]): 0;
            int b = i < n? stoi(v2[i]): 0;

            if(a < b) return -1;
            else if(a > b) return 1;
            else i++;
        }
        return 0;
    }
};
