#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
class Solution { 
public: 
    int minimumWorkingTime(vector<int>& jobs, int k) { 
        vector<int> workloads(k, 0); 
        int result ; 
        sort(jobs.rbegin(), jobs.rend());  
        backtrack(jobs, 0, workloads, k, result); 
        return result; 
    } 
private: 
    void backtrack(vector<int>& jobs, int index, vector<int>& workloads, int k, 
int& result) { 
        if (index == jobs.size()) { 
            result = min(result, *max_element(workloads.begin(), workloads.end())); 
            return; 
        } 
        int currentJob = jobs[index]; 
        for (int i = 0; i < k; ++i) { 
            if (workloads[i] + currentJob >= result) continue;  
            if (i > 0 && workloads[i] == workloads[i - 1]) continue;  
            workloads[i] += currentJob; 
            backtrack(jobs, index + 1, workloads, k, result); 
            workloads[i] -= currentJob; 
            if (workloads[i] == 0) break; 
        } 
    } 
}; 
int main() { 
    Solution solution; 
    vector<int> jobs = {3, 2, 3}; 
    int k = 3; 
    cout << "Minimum possible maximum working time: " << 
    solution.minimumWorkingTime(jobs, k) << endl; 
    return 0; 
}