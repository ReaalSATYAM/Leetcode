class Spreadsheet {
public:
    // Used instead of a 2d matrix
    unordered_map<string, int> sheet;
    Spreadsheet(int rows) {
        // Sheet is already declared outside
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value; // simply  set the store cell -> value
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;// reset the cell. if you want to use erase function here, then you need change solve function accordingly 
    }
    int solve(string a){
        // check if 'a' is a number or not ?
        if(isdigit(a[0])){
            return stoi(a);
        }
        return sheet[a];
    }
    int getValue(string formula) {
        string s = formula.substr(1);// remove '=' sign
        int plusIndex = s.find('+');
        string left = s.substr(0, plusIndex);// before '+'
        string right = s.substr(plusIndex+1);// after '+'

        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
