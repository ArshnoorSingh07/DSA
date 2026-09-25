class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k < 0 || k >n){
            return -1;
        }

        if(k == 0){
            return 0;
        }

        if(k == n){
            int sum = 0;
            for(auto &it: cardPoints){
                sum+=it;
            }
            return sum;
        }
        

        int currentScore = 0;
        for(int i = 0; i<k; i++)
        {
            currentScore += cardPoints[i];
        }
        
        int maxScore = currentScore;
        int rightIndex = n-1;

        for(int i = k-1; i>=0; i--){
            currentScore -= cardPoints[i];
            currentScore += cardPoints[rightIndex--];
            maxScore = max(currentScore, maxScore);
        }

        return maxScore;

        

    }
};