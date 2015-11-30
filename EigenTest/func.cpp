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


/**判断是否为整数**/
bool is_number(std::string str) {
    int index = 0;
    if (str.c_str()[0] == 45 || str.c_str()[0] == 43) {
        index++;
    }
    for (; index < str.length(); index++) {
        if (str.c_str()[index] < '0' || str.c_str()[index] > '9')
            return false;
    }
    return true;
}
