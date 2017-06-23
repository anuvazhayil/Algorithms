int dfs(int n, int currN, int sum){

    if((int)sqrt(currN) * (int)sqrt(currN) == currN){
        sum += currN;
        if(sum == n)
            return 1;
        if(sum < n){
            int result;
            for(int i = 0; i < currN; i++){
                result = dfs(n, currN-i, sum);
                if(result)
                    return result+1;
            }
        }
    }
    return 0;
}

class Solution {
public:
    int numSquares(int n) {
        int result;
        if((int)sqrt(n)*(int)sqrt(n) == n)
            return 1;
        for(int i = 1; i < n; i++){
            if((int)sqrt(n-i)*(int)sqrt(n-i) == n-i){
                result = dfs(n, n-i, 0);
                return result;
            }
        }
    }
};
