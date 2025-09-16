/*
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
    Example 1:
    
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
*/
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool isBroken[26] = {false};

        for (char letter : brokenLetters) {
            isBroken[letter - 'a'] = true;
        }

        int typeableWordCount = 0;
        vector<string> words = split(text, ' ');

        for (const string& word : words) {
            bool canTypeWord = true;

            for (char character : word) {
                if (isBroken[character - 'a']) {
                    canTypeWord = false;
                    break;
                }
            }
          
            if (canTypeWord) {
                typeableWordCount++;
            }
        }
      
        return typeableWordCount;
    }

private:
    vector<string> split(const string& inputString, char delimiter) {
        vector<string> result;
        string currentWord;
        for (char currentChar : inputString) {
            if (currentChar == delimiter) {
                result.push_back(currentWord);
                currentWord.clear();
            } 
            else {
                currentWord.push_back(currentChar);
            }
        }

        result.push_back(currentWord);
      
        return result;
    }
};
