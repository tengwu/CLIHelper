//
// Created by wuteng on 2021/2/25.
//

#ifndef CLIHELPER_PARAMSET_H
#define CLIHELPER_PARAMSET_H


#include <set>
#include <map>
#include <string>

class ParamSet {
private:
    std::map<std::string, std::string> params; // TODO: map<string, ParamValue> params;
    std::set<std::string> paramsSeted;

public:
    ParamSet(){}
    ~ParamSet(){}

    void Set(std::string &argName);
    void Set(std::string &argName, std::string &argValue);
    std::string Get(std::string &argName);
    bool IsSet(std::string &argName);
};


#endif //CLIHELPER_PARAMSET_H
