//
// Created by wuteng on 2020/5/31.
//


#ifndef CLIHELPER_IPARAMPARSER_H
#define CLIHELPER_IPARAMPARSER_H


#include "ParamSet.h"

class IParamParser {
public:
    IParamParser(){}
    ~IParamParser(){}

    virtual void Parse(char *argv, ParamSet *paramSet);
};


#endif //CLIHELPER_IPARAMPARSER_H
