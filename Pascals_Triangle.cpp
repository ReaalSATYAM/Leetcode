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

