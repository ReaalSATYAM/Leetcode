// Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
int main() {
    int n = 3, r = 2;// For zero based indexing, decrease 'n' and 'r' by one(n-1, r-1)!
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    cout<<res; // 3
    return 0;
}

// Given the row number n. Print the n-th row of Pascal’s triangle.
int main() {
    int n = 10;// this will print the 11th row
    long long res = 1;
    cout<<res<<" ";
    for(int i = 0; i < n; i++){
        res = res*(n-i);
        res = res/(i+1);
        cout<<res<<" ";
    }
    return 0;
}

// Given the number of rows n. Print the first n rows of Pascal’s triangle.
//Leetcode solution
class Solution {
private:
    vector<int> generateRow(int row){
        long long res = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int col = 0; col < row; col++){
            res = res*(row-col);
            res = res/(col+1);
            temp.push_back(res);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }

};

//Easier version
int main() {
    int n = 10;
    
    for(int i = 0; i <= n; i++){
        long long res = 1;
        cout<<res<<" ";
        for(int j = 0; j< i; j++){
            res = res*(i-j);
            res = res/(j+1);
            cout<<res<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
