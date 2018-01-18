/* leetcode solution */
/* for each i, check j of line (i, j) and its pair<int, int> repr */
/* NOTE: 1. vertical line cases 2. same point cases */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
        if(points.size()<2) return points.size();
        
        int result=0;
        
        for(int i=0; i<points.size(); i++) {
            
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;
            
            for(int j=i+1; j<points.size(); j++) {
                
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    
                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {
                    
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);
                    
                    a/=gcd;
                    b/=gcd;
                    
                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }

                localmax=max(vertical, localmax);
            }
            
            result=max(result, localmax+overlap+1);
        }
        
        return result;
    }

private:
    int GCD(int a, int b) {
        
        if(b==0) return a;
        else return GCD(b, a%b);
    }
};