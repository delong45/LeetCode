class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int sum = s[i] - '0';
                while (i + 1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9') {
                    sum = sum * 10 + s[i+1] - '0';
                    i++;
                }
                result += sum * sign;
            }
            if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            if (s[i] == ')') {
                result = result * st.top();
                st.pop();
                result += st.top();
                st.pop();

            }
            if (s[i] == '+') {
                sign = 1;
            }
            if (s[i] == '-') {
                sign = -1;
            }
        }
        return result;
    }
};
