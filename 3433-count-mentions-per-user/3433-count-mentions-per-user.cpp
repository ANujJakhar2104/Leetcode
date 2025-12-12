// class Solution {
// public:
//     vector<int> countMentions(int n , vector<vector<string>>& events) {
//         vector<int> mention(n , 0);

//         vector<int> online(n , 0);
//         sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b){
//             return stoi(a[1]) < stoi(b[1]);
//         });


//         for(auto it : events){
//             string mess = it[0];
//             string time = it[1];
//             string ids = it[2];

//             if (mess == "MESSAGE"){
//                 if (ids == "HERE"){
//                     for(int i=0 ; i<n ;i++){
//                         if (online[i] == 0) mention[i]++;
//                         else if(stoi(time)-online[i] >= 60){
//                             mention[i]++;
//                             online[i] = 0;
//                         }
//                     }
//                 }
//                 else if (ids == "ALL"){
//                     for(int i=0 ; i<n ;i++){
//                         mention[i]++;
//                     }
//                 }
//                 else{
//                     for (int i = 0; i < ids.length() ; i++) {
//                         if (isdigit(ids[i])) {
//                             int num = 0;
//                             while (i < ids.length() && isdigit(ids[i])){
//                                 num = num * 10 + (ids[i] - '0');
//                                 i++;
//                             }
//                             mention[num]++;
//                             online[num] = 0;
//                         }
//                     }
//                 }
//             }
//             else {
//                 online[stoi(ids)] = stoi(time);
//             }
//         }
//         return mention;
//     }
// };


class Solution {
public:
    vector<int> countMentions(int n , vector<vector<string>>& events) {
        vector<int> mention(n , 0);
        vector<int> online(n , 0);

        priority_queue<
            pair<pair<int,int>, string>,
            vector<pair<pair<int,int>, string>>,
            greater<pair<pair<int,int>, string>>
        > pq;

        for (auto it : events) {
            string mess = it[0];
            string time = it[1];
            string ids = it[2];

            int t = stoi(time);

            if (mess == "OFFLINE") {
                pq.push({{t , 0}, ids});
            }
            else {
                pq.push({{t , 1}, ids});
            }
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top.first.first;
            int mess = top.first.second;
            string ids = top.second;

            if (mess == 1) {
                if (ids == "HERE") {
                    for (int i = 0; i < n; i++) {
                        if (online[i] == 0) mention[i]++;
                        else if (time - online[i] >= 60) {
                            mention[i]++;
                            online[i] = 0;
                        }
                    }
                }
                else if (ids == "ALL") {
                    for (int i = 0; i < n; i++) {
                        mention[i]++;
                    }
                }
                else {
                    for (int i = 0; i < ids.length(); i++) {
                        if (isdigit(ids[i])) {
                            int num = 0;
                            while (i < ids.length() && isdigit(ids[i])) {
                                num = num * 10 + (ids[i] - '0');
                                i++;
                            }
                            mention[num]++;
                        }
                    }
                }
            }
            else {
                online[stoi(ids)] = time;
            }
        }

        return mention;
    }
};

