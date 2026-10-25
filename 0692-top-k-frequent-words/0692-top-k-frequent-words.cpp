class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (const string& word : words) {
            freq[word]++;
        }

        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };

        priority_queue<pair<string, int>,
                       vector<pair<string, int>>,
                       decltype(cmp)> pq(cmp);

        for (const auto& entry : freq) {
            pq.push({entry.first, entry.second});
        }

        vector<string> result;

        while (k--) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};