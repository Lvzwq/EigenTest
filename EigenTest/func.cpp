//
// Created by zwenqiang on 15/11/27.
//

#include "func.h"

void split_str(std::string longStr, std::vector<std::string> &v) {
    std::istringstream iss(longStr);
    while (iss) {
        std::string sub;
        iss >> sub;
        v.push_back(sub);
    }
}
