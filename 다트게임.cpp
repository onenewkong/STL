// 2018 KAKAO BLIND RECRUITMENT [1차] 다트 게임
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0, x = 0, a, b;
    vector<int> s;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (isalpha(dartResult[i]))
        {
            a = dartResult[i - 1] - '0';
            if (a == 0 && (dartResult[i - 2] - '0') == 1)
                a = 10;

            if (dartResult[i] == 'S')
                b = 1;
            if (dartResult[i] == 'D')
                b = 2;
            if (dartResult[i] == 'T')
                b = 3;

            x = pow(a, b);

            if (dartResult[i + 1] == '*')
            {
                x *= 2;
                if (!s.empty())
                    s[s.size() - 1] *= 2;
            }

            if (dartResult[i + 1] == '#')
                x *= -1;

            s.push_back(x);
        }
    }

    for (int i = 0; i < s.size(); i++)
        answer += s[i];

    return answer;
}