// Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
int main() {
    int n = 3, r = 2;
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    cout<<res;
    return 0;
}

