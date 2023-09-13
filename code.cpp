#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

std::string ArrayChallenge(std::vector<std::string> strArr) {
    std::list<std::string> cache;
    std::unordered_map<std::string, std::list<std::string>::iterator> cacheMap;
    std::vector<std::string> result;

    for (const std::string& str : strArr) {
        if (cacheMap.find(str) != cacheMap.end()) {
            // Move the accessed item to the front of the cache
            cache.erase(cacheMap[str]);
            cache.push_front(str);
        } else {
            // Check if the cache is at its limit, and remove the least recently used item
            if (cache.size() >= 5) {
                cacheMap.erase(cache.back());
                cache.pop_back();
            }
            // Add the new item to the cache
            cache.push_front(str);
            cacheMap[str] = cache.begin();
        }

        result.push_back(str);
    }

    std::string output;
    for (const std::string& str : result) {
        if (!output.empty()) {
            output += "-";
        }
        output += str;
    }

    return output;
}

int main() {
    std::vector<std::string> input1 = {"A", "B", "C", "D", "A", "E", "D", "Z"};
    std::cout << ArrayChallenge(input1) << std::endl;  // Output: C-A-B

    std::vector<std::string> input2 = {"A", "B", "A", "C", "A", "B"};
    std::cout << ArrayChallenge(input2) << std::endl;  // Output: E-D-Q-Z-C

    std::vector<std::string> input3 = {"A", "B", "C", "D", "E", "D", "Q", "Z", "C"};
    std::cout << ArrayChallenge(input3) << std::endl;  // Output: E-D-Q-Z-C

    return 0;
}
