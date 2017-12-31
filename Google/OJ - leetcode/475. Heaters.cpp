/* brilliant idea | binary search */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        // find max of all house distances to nearest heater
        int m = houses.size();
        int n = heaters.size();
        if (m == 0) return 0;
        vector<int> v(m, INT_MAX);
        int i = 0;
        int j = 0;
        while (i < m && j < n) { // distance to the nearest rhs heater
            if (houses[i] <= heaters[j]) {
                v[i] = min(heaters[j] - houses[i], v[i]);
                i ++;
            } else {
                j ++;
            }
        }
        i = m - 1; j = n - 1;
        while (i >= 0 && j >= 0) { // distance to the nearest rhs heater
            if (houses[i] >= heaters[j]) {
                v[i] = min(houses[i] - heaters[j], v[i]);
                i --;
            } else {
                j --;
            }
        }
        return *max_element(v.begin(), v.end());
    }
};

/* below is a JAVA solution using binary search for getting the nearest two heaters for each house 
 * Time Complexity is logarithm slower */
public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int result = Integer.MIN_VALUE;
        
        for (int house : houses) {
            int index = Arrays.binarySearch(heaters, house);
            if (index < 0) {
        	index = -(index + 1);
            }
            int dist1 = index - 1 >= 0 ? house - heaters[index - 1] : Integer.MAX_VALUE;
            int dist2 = index < heaters.length ? heaters[index] - house : Integer.MAX_VALUE;
        
            result = Math.max(result, Math.min(dist1, dist2));
        }
        
        return result;
    }
}
