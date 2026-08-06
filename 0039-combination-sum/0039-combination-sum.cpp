#include <vector>

class Solution {
private:
    void backtrack(int index, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base Case 1: Target reached, add combination to result
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Base Case 2: Out of bounds or target exceeded
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        // Choice 1: Include the current element candidates[index]
        // Stay at 'index' because the same element can be reused unlimited times
        current.push_back(candidates[index]);
        backtrack(index, target - candidates[index], candidates, current, result);
        
        // Backtrack: Undo the choice to explore the skip branch
        current.pop_back();

        // Choice 2: Skip the current element and move to the next index
        backtrack(index + 1, target, candidates, current, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        backtrack(0, target, candidates, current, result);
        
        return result;
    }
};