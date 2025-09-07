/*
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/
char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    int jump = (numRows - 1) * 2;
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < n; j += jump) {
            res[index++] = s[j];
            if (i > 0 && i < numRows - 1) {
                int zigzag = j + jump - 2 * i;
                if (zigzag < n) {
                    res[index++] = s[zigzag];
                }
            }
        }
    }
    res[index] = '\0';
    return res;
}
