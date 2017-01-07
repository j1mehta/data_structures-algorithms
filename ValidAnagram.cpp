#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
//Valid Anagram from Leetcode using multiset.
// Inefficient since complexity = O(nLogn).
// This is because multiset.find has complexity of logN which needs to be done for all elements. Accepted.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        multiset<char> m;
        for (int i = 0; i < s.size(); i++) {
            m.insert(s[i]);
        }

        for (int j = 0; j < t.size(); j++) {
            if (m.find(t[j]) == m.end()) {
                //cout << m.count(t[j]) << t[j] <<endl;
                return false;
            } else {
                auto itr = m.find(t[j]);
                m.erase(itr);
            }
            return true;
        }
    }
    };

