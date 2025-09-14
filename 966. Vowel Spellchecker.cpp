class Solution {
    // maps are used for constant time(O(1)) look up 
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

private:
    // Case 1
    // convert string to lower case.
    string toLower(string str){
        for(char &ch: str){
            ch = tolower(ch);
        }
        return str;
    }
    // Case 2
    // IMP: replace vowels with '$' for easier matching(in case of vowle error only).  
    string replaceVowel(string str){
        for(char &ch: str){
            if(ch == 'a'|| ch == 'e'||ch == 'i'|| ch == 'o'||ch == 'u'){
                ch = '$';
            }
        }
        return str;
    }

// function to check if query is in wordlisty or not ?
    string checkForMatch(string &query){
        if(exactSet.count(query)) return query;

        string lowerCase = toLower(query);
        if(caseMap.count(lowerCase)) return caseMap[lowerCase];

        string vowelCase = replaceVowel(lowerCase);
        if(vowelMap.count(vowelCase)) return vowelMap[vowelCase];

        return "";
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;

        // convert wordlist for easier string matching with queries
        for(const string& word : wordlist){
            exactSet.insert(word);

            string lowerCase = toLower(word);
            if(caseMap.find(lowerCase) == caseMap.end()){
                caseMap[lowerCase] = word;
            }

            string vowelCase = replaceVowel(lowerCase);
            if(vowelMap.find(vowelCase) == vowelMap.end()){
                vowelMap[vowelCase] = word;
            }
        }

        for(string& query : queries){
            res.push_back(checkForMatch(query));
        }

        return res;
    }
};
