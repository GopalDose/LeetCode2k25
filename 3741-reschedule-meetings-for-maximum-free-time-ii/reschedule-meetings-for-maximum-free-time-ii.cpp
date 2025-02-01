class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> G(n + 1, 0);
        G[0] = startTime[0]; 
        for (int i = 1; i < n; i++){
            G[i] = (long long)startTime[i] - endTime[i - 1];
        }
        G[n] = (long long)eventTime - endTime[n - 1];
        
        long long orig = 0;
        for (long long gap : G)
            orig = max(orig, gap);
        
        int m = G.size(); 
        vector<long long> pre(m), suf(m);
        pre[0] = G[0];
        for (int i = 1; i < m; i++){
            pre[i] = max(pre[i - 1], G[i]);
        }
        suf[m - 1] = G[m - 1];
        for (int i = m - 2; i >= 0; i--){
            suf[i] = max(suf[i + 1], G[i]);
        }
        
        long long ans = orig;
        for (int i = 0; i < n; i++){
            long long du = (long long)endTime[i] - startTime[i];
            long long dumm = 0; 
            long long tp = 0;  
            
            if (i == 0) {
                
                long long A = startTime[1];  
                long long B = (2 < m ? suf[2] : 0);
                dumm = max(A, B);
                tp = (dumm == A ? B : A);
            }
            else if (i == n - 1) {
                
                long long A = (long long)eventTime - endTime[n - 2];
                long long B = pre[n - 2];
                dumm = max(A, B);
                tp = (dumm == A ? B : A);
            }
            else {
                long long A = pre[i - 1];
                long long B = (long long)startTime[i + 1] - endTime[i - 1];
                long long C = (i + 2 < m ? suf[i + 2] : 0);
                dumm = max({A, B, C});
                if (dumm == B)
                    tp = max(A, C);
                else
                    tp = B;
            }
            long long temp = (tp >= du ? dumm : max(0LL, dumm - du));
            ans = max(ans, temp);
        }
        return (int)ans;
    }
};
