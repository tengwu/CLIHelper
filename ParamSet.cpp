//
// Created by wuteng on 2021/2/25.
//

#include "ParamSet.h"

std::string ParamSet::GetSubCMD()
{
    return subCMD;
}
void ParamSet::SetSubCMD(std::string &subCMD)
{
    this->subCMD = subCMD;
}

void ParamSet::Set(std::string &argName)
{
    paramsSeted.insert(argName);
}

void ParamSet::Set(std::string &argName, std::string &argValue)
{
    params[argName] = argValue;
}

std::string ParamSet::Get(std::string &argName)
{
    return params[argName];
}

bool ParamSet::IsSet(std::string &argName)
{
    return paramsSeted.find(argName) != paramsSeted.end();
}

