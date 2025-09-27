class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        // Create a priority queue to store the potential increase in ratio and class counts
        priority_queue<pair<double,int>> pq;
        
        for(int i = 0; i < n; i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain, i});
        }

        while(extraStudents--){
            auto top = pq.top();
            pq.pop();
            int idx = top.second;

            classes[idx][0]++;
            classes[idx][1]++;

            int pass = classes[idx][0];
            int total = classes[idx][1];
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain, idx});
        }

        // Calculate the final average ratio
        double ans = 0.0;
        for(auto &c : classes){
            ans += (double)c[0] / c[1];
        }

        return ans / n;
    }
};


// Different style
class Solution {
private:
    double calculateGain(int pass, int total){
        return (double)(pass+1)/(total+1) - double(pass)/total;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for(auto it: classes){
            maxHeap.push({calculateGain(it[0], it[1]), {it[0], it[1]}});
        }
        while(extraStudents--){
            auto topElement = maxHeap.top();
            maxHeap.pop();
            int pass = topElement.second.first;
            int total = topElement.second.second;
            maxHeap.push({calculateGain(pass+1, total+1), {pass+1, total+1}});
        }
        double totalPassRatio = 0;
        while(!maxHeap.empty()){
            auto topElement = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)topElement.second.first/topElement.second.second; 
        }
        return totalPassRatio/classes.size();
    }
};
