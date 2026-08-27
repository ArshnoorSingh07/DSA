class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i < n)
        {
            if(ratings[i] == ratings[i-1]){
                i++;
                sum += 1;
                continue;
            }
            int peak=1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down > peak){
                sum+=down-peak;
            }
        }

        return sum;


        // int n = ratings.size();
        // vector<int>left(n);

        // left[0] = 1;
        // for(int i = 1; i<n; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     }else{
        //         left[i] = 1;
        //     }
        // }

        // int curr = 1;
        // int right = 1;
        // int sum = max(1, left[n-1]);

        // for(int i = n-2; i>=0; i--)
        // {
        //     if(ratings[i] > ratings[i+1]){
        //         curr = right +1;
        //         right = curr;
        //     }
        //     else{
        //         curr= 1;
        //         right =1;
        //     }
        //     sum += max(left[i], curr);
        // }
        // return sum; 
    }
};