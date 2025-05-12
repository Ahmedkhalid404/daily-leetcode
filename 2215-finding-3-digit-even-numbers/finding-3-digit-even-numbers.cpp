class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = int(digits.size());
        set<int> evenNumbers;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                for (int k = j + 1; k < n; k++) {
                    vector<int> combinations;
                    combinations.reserve(6);

                    combinations.push_back((digits[i] * 10 + digits[j]) * 10 +
                                           digits[k]);
                    combinations.push_back((digits[i] * 10 + digits[k]) * 10 +
                                           digits[j]);
                    combinations.push_back((digits[j] * 10 + digits[i]) * 10 +
                                           digits[k]);
                    combinations.push_back((digits[j] * 10 + digits[k]) * 10 +
                                           digits[i]);
                    combinations.push_back((digits[k] * 10 + digits[i]) * 10 +
                                           digits[j]);
                    combinations.push_back((digits[k] * 10 + digits[j]) * 10 +
                                           digits[i]);

                    for (auto& it : combinations) {
                        if (it & 1)
                            continue;

                        if (floor(log10(it) + 1) != 3)
                            continue;

                        evenNumbers.insert(it);
                    }
                }
            }
        }

        return vector<int>(evenNumbers.begin(), evenNumbers.end());
    }
};