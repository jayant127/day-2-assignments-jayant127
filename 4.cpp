#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std; 
class Solution { 
public: 
    int maxHappyGroups(int batchSize, vector<int>& groups) { 
        vector<int> modCount(batchSize, 0); 
        for (int g : groups) { 
            modCount[g % batchSize]++; 
        } 
        int happyGroups = modCount[0];  
        for (int i = 1; i <= batchSize / 2; ++i) { 
            if (i == batchSize - i) {  
                happyGroups += modCount[i] / 2; 
            } else { 
                int pairs = min(modCount[i], modCount[batchSize - i]); 
                happyGroups += pairs; 
                modCount[i] -= pairs; 
                modCount[batchSize - i] -= pairs; 
            } 
        } 
        return happyGroups + dfs(modCount, batchSize, 0); 
    } 
private: 
    unordered_map<string, int> memo; 
    int dfs(vector<int>& modCount, int batchSize, int remainder) { 
        string key = to_string(remainder) + "," + to_string_vector(modCount); 
        if (memo.find(key) != memo.end()) return memo[key]; 
        int result = 0; 
        bool hasRemaining = false; 
 
        for (int i = 1; i < modCount.size(); ++i) { 
            if (modCount[i] > 0) { 
                hasRemaining = true; 
                modCount[i]--; 
                result = max(result, (remainder == 0 ? 1 : 0) + dfs(modCount, batchSize, 
(remainder + i) % batchSize)); 
                modCount[i]++; 
            } 
        } 
        if (!hasRemaining) { 
            result = 0; // No remaining groups 
        } 
        memo[key] = result; 
        return result; 
    } 
    string to_string_vector(const vector<int>& vec) { 
        string result; 
        for (int val : vec) { 
            result += to_string(val) + ","; 
        } 
        return result; 
    } 
}; 
int main() { 
    Solution solution; 
    int batchSize = 3; 
    vector<int> groups = {1, 2, 3, 4, 5, 6}; 
    cout << "Maximum Happy Groups: " << solution.maxHappyGroups(batchSize, 
groups) << endl; 
    return 0; 
} 
