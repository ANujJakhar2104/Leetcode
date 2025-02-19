class ProductOfNumbers {
public:
    vector<int> answer;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0){
            answer.clear();
        }
        else{
            int n =1;
            if (answer.empty()){
                answer.push_back(num);
            }
            else{
                answer.push_back(num * answer.back());
            }
        }
    }
    
    int getProduct(int k) {
        int n = answer.size();
        if (n==0 || k>n) return 0;
        if (k==n) return answer.back();
        return answer.back() / answer[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */