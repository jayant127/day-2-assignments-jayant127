#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
int maxArea(vector<int>& height) { 
    int left = 0, right = height.size() - 1; 
    int maxWater = 0; 
    while (left < right) { 
        int width = right - left; 
        int currentHeight = min(height[left], height[right]); 
        int area = width * currentHeight; 
        maxWater = max(maxWater, area); 
        if (height[left] < height[right]) { 
            left++; 
        } else { 
            right--; 
        } 
    } 
 
    return maxWater; 
} 
int main() { 
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; 
    cout << "Maximum area of water the container can store: " << maxArea(height) 
<< endl; 
return 0; 
}