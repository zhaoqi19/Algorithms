class Solution {
public:
    int div(int a, int b){
        if(a < b) return 0;
        int ans = 1;
        int acc = b;
        while(a - acc >= acc){
            ans += ans;
            acc += acc;
        }
        return ans + div(a - acc, b);
    }

    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        else if(divisor == 1) return dividend;
        else if(divisor == -1) return (dividend == INT_MIN)? INT_MAX : -dividend;
        
        int a = dividend;
        int b = divisor;
        int ans = 0;
        bool flag = (a > 0 && b > 0 || a < 0 && b < 0); //同符号时为真
        
        if(b == INT_MIN){ //处理b为特殊值的情况
            return (a == INT_MIN)? 1 : 0;
        }
        if(a == INT_MIN){ //处理a为特殊值的情况
            a = (flag)? a - b : a + b;
            ++ans;
        } 
        a = (a > 0)? a : -a; 
        b = (b > 0)? b : -b;
        ans += div(a, b);
        if(!flag) ans = -ans;
        return ans;
    }
};
