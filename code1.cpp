#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ArrayChallenge(string strArr[], int arrLength, string ChallengeToken) {
    vector<string> cache;  // Initialize a vector to represent the cache
    const int maxCacheSize = 5;  // Maximum cache size

    for (int i = 0; i < arrLength; i++) {
        string element = strArr[i];
        auto it = find(cache.begin(), cache.end(), element);
        if (it != cache.end()) {
            // If the element is already in the cache, move it to the front
            cache.erase(it);
            cache.insert(cache.begin(), element);
        } else {
            // If the element is not in the cache, add it to the front
            cache.insert(cache.begin(), element);

            // If the cache size exceeds the maximum, remove the least recently used element
            if (cache.size() > maxCacheSize) {
                cache.pop_back();
            }
        }
    }

    // Construct the final cache state as a string
    string cacheState = "";
    for (const string& item : cache) {
        cacheState += item + "-";
    }
    cacheState.pop_back();  // Remove the trailing hyphen

    // Reverse the cacheState string to get the correct order
    reverse(cacheState.begin(), cacheState.end());

    // Concatenate the ChallengeToken to the cacheState
    cacheState += ChallengeToken;

    // Replace every third character with "X"
    for (int i = 2; i < cacheState.length(); i += 3) {
        cacheState[i] = 'X';
    }

    return cacheState;  // Return the final cache state as a string
}

int main(void) {
    // Example input
    string A[] = {"A", "B", "A", "C", "A", "B"};
    int arrLength = sizeof(A) / sizeof(*A);
    string ChallengeToken = "yzcksg10a4";
    cout << ArrayChallenge(A, arrLength, ChallengeToken) << endl;
    return 0;
}
