class Solution {
public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) return false;
        int arr[2] = {0, 0}, *p = arr, cnt = 0;

        for (int i = 0; i < a.size(); ++i) {
        	if (a[i] != b[i]) {
        		++cnt;
        		if (cnt <= 2) {
        			*p++ = i;
        		} else {
        			return false;
        		}
        	}
        }
		
		if (cnt) {
			return a[arr[0]] == b[arr[1]] && a[arr[1]] == b[arr[0]];
		}


		return false;
    }
};