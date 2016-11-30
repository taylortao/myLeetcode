class Solution {
public:
    bool static compare(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses  <= 0 || prerequisites.size() == 0) {
            return true;
        }
        sort(prerequisites.begin(), prerequisites.end(), compare);
        vector<int> taken(numCourses, 0);
        stack<int> courses;
        // topological sort
        for (int i=0; i<numCourses; i++) {
            if (taken[i] == 0) {
                if (!topologicalSort(prerequisites, taken, courses, i)) {
                    // has circle
                    return false;
                }
            }
        }
        return true;
    }
    
    bool topologicalSort(const vector<pair<int, int>>& prerequisites, vector<int>& taken, stack<int>& courses, int ind) {
        taken[ind] ++;
        int dp = binaryFindClass(prerequisites, ind);
        if (dp >= 0) {
            while (dp < prerequisites.size() && prerequisites[dp].second == ind) {
                int flg = taken[prerequisites[dp].first];
                if (flg == 0) {
                    if (!topologicalSort(prerequisites, taken, courses, prerequisites[dp].first)) {
                        return false;
                    }
                }
                else if (flg == 1) {
                    return false;
                }
                dp ++;
            }
        }
        taken[ind] ++;
        courses.push(ind);
        return true;
    }
    
    int binaryFindClass(const vector<pair<int, int>>& prerequisites, int id) {
        int st = 0, ed = prerequisites.size()-1;
        while (st + 1 < ed) {
            int mid = st + ((ed - st)>>1);
            if (prerequisites[mid].second >= id) {
                ed = mid;
            }
            else {
                st = mid;
            }
        }
        return prerequisites[st].second == id ? st : (prerequisites[ed].second == id ? ed : -1);
    }
};
