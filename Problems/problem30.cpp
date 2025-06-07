#include <vector>
#include <unordered_map>
#include <string>
#include <ranges>
#include <print>

namespace problem30
{
    using namespace std;

    vector<int> findSubstring(string s, vector<string> &&words)
    {
        vector<int> results;
        unordered_map<string_view, int> wordFreq;
        for (const auto &word : words)
            ++wordFreq[word];

        size_t wordSize = words[0].length();
        string_view inputString{s};

        for (size_t i = 0; i < wordSize; ++i)
        {
            unordered_map<string_view, int> wordFreqCnt;
            size_t left = i;
            size_t right = i;
            size_t totalCnt = 0;

            while (right < inputString.length())
            {
                auto const &wordCrt = inputString.substr(right, wordSize);
                right += wordSize;

                if (auto const &wordOriginalFreqIterator = wordFreq.find(wordCrt);
                    wordOriginalFreqIterator != wordFreq.end())
                {
                    auto &wordFreqCntRef = ++wordFreqCnt[wordCrt];
                    ++totalCnt;
                    while (wordFreqCntRef > wordOriginalFreqIterator->second)
                    {
                        --wordFreqCnt[inputString.substr(left, wordSize)];
                        --totalCnt;
                        left += wordSize;
                    }

                    if (totalCnt == words.size())
                    {
                        results.push_back(left);
                    }
                }
                else
                {
                    left = right;
                    totalCnt = 0;
                    wordFreqCnt.clear();
                }
            }
        }

        return results;
    }
}