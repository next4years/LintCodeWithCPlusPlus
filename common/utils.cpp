
#include "utils.h"
#include <sstream>

std::string Utils::printVector(std::vector<int> vec) {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1) {
            oss << ", ";
        }
    }
    return oss.str();
}
