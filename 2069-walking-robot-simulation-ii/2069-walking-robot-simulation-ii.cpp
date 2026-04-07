class Robot {
public:
    int x =0,y=0;
    int m , n;
    int curr = 90;
    Robot(int width, int height) {
        m = width;
        n = height;
    }
    
    void step(int num) {
        int perimeter = 2 * (m + n - 2);
        num %= perimeter;
        if (num == 0) num = perimeter;
        while(num != 0){
            curr %= 360;
            if (curr == 0){
                if (y+1 != n) {y += 1; num -= 1;}
                else { curr += 270; curr %= 360; }

            }else if (curr == 90){
                if (x+1 != m) {x += 1; num -= 1;}
                else { curr += 270; curr %= 360; }

            }else if (curr == 180){
                if (y-1 >= 0) {y -= 1; num -= 1; }
                else { curr += 270; curr %= 360; }
            }
            else {
                if (x-1 >= 0){ x -= 1; num -= 1;}
                else { curr += 270; curr %= 360; }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        curr %= 360;
        if (curr == 0) return "North";
        else if (curr == 90) return "East";
        else if (curr == 180) return "South";
        else return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */