class Spreadsheet {
private:
    vector<vector<int>> spread;

    void find(int& x, int& y , const string& cell) {
        y = cell[0] - 'A'; 
        x = 0;
        for (int i = 1; i < cell.size(); i++) {
            x = x * 10 + (cell[i] - '0');
        }
        x--; // 0-index
    }

    bool isNumber(const string& s) {
        for (char c : s) if (!isdigit(c)) return false;
        return true;
    }

    int getValueOf(const string& token) {
        if (isNumber(token)) {
            return stoi(token);
        } else {
            int x=0, y=0;
            find(x, y, token);
            return spread[x][y];
        }
    }

public:
    Spreadsheet(int rows) { 
        spread.resize(rows, vector<int>(26, 0)); 
    }

    void setCell(string cell, int value) {
        int x=0, y=0;
        find(x, y, cell);
        spread[x][y] = value;
    }

    void resetCell(string cell) {
        setCell(cell , 0);
    }

    int getValue(string formula) {
        int pos = formula.find('+');
        string first = formula.substr(1, pos-1);
        string second = formula.substr(pos+1);

        return getValueOf(first) + getValueOf(second);
    }
};
