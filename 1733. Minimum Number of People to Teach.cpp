class Solution {
private:
// Helper function to check if two users share at least one common language
    bool haveCommonLanguage(int user1, int user2, vector<vector<int>>& languages){
        for (int language1 : languages[user1 - 1]) {  
            for (int language2 : languages[user2 - 1]) {  
                if (language1 == language2) {
                    return true;  
                }
            }
        }
        return false;  
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Set to store users who cannot communicate with at least one friend
        unordered_set<int> usersNeedingHelp;
      
        for (auto& friendship : friendships) {
            int user1 = friendship[0];
            int user2 = friendship[1];
          
            if (!haveCommonLanguage(user1, user2, languages)) {
                usersNeedingHelp.insert(user1);
                usersNeedingHelp.insert(user2);
            }
        }
      
        if (usersNeedingHelp.empty()) {
            return 0;
        }
      
        vector<int> languageCount(n + 1, 0); 
      
        for (int userId : usersNeedingHelp) {
            for (int& languageId : languages[userId - 1]) {  
                ++languageCount[languageId];
            }
        }
        int maxUsersKnowingLanguage = *max_element(languageCount.begin(), languageCount.end());
      
        return usersNeedingHelp.size() - maxUsersKnowingLanguage;
    }
};

// different approach
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<char>> matrix(m + 1, vector<char>(n + 1, false));
        for (int i = 0; i < m; i++) {
            for (const auto& language : languages[i]) {
                matrix[i + 1][language] = true;
            }
        }
        vector<char> learn(m + 1, false);
        for (const auto& friendship : friendships) {
            bool can_communicate = false;
            for (int i = 1; i <= n; i++) {
                if (matrix[friendship[0]][i] && matrix[friendship[1]][i]) {
                    can_communicate = true;
                    break;
                }
            }
            if (!can_communicate) {
                learn[friendship[0]] = true;
                learn[friendship[1]] = true;
            }
        }
        int minimum_learnings = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int learnings = 0;
            for (int j = 1; j <= m; j++) {
                if (learn[j] && !matrix[j][i]) {
                    learnings++;
                }
            }
            minimum_learnings = min(minimum_learnings, learnings);
        }
        return minimum_learnings;
    }
};
