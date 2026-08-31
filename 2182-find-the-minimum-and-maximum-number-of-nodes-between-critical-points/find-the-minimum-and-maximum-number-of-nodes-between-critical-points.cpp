class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> positions;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != NULL) {
            if ((curr->val > prev->val &&
                 curr->val > curr->next->val) ||
                (curr->val < prev->val &&
                 curr->val < curr->next->val)) {

                positions.push_back(index);
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (positions.size() < 2)
            return {-1, -1};

        int minimumDistance = INT_MAX;

        for (int i = 1; i < positions.size(); i++) {
            minimumDistance = min(
                minimumDistance,
                positions[i] - positions[i - 1]
            );
        }

        int maximumDistance =
            positions.back() - positions.front();

        return {minimumDistance, maximumDistance};
    }
};