//
// Created by wuteng on 2020/5/31.
//

#include "ICMDBase.h"
#include "CMDFactory.h"

ICMDBase::ICMDBase(const char *name, const char *short_name, const char *description) {
    this->name = name;
    this->short_name = short_name;
    CMDFactory::Singleton()->RegisterCMD(this->name, this);
    if (short_name != nullptr)
        CMDFactory::Singleton()->RegisterCMD(this->short_name, this);
    if (description != nullptr)
        this->description = description;
}

ICMDBase::~ICMDBase() {
    CMDFactory::Singleton()->UnregisterCMD(this->name);
    if (this->short_name.length() != 0)
        CMDFactory::Singleton()->UnregisterCMD(this->short_name);
}
