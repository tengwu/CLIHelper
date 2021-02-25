//
// Created by wuteng on 2020/5/31.
//

#include "ICMDBase.h"
#include <cstdio>

class TestCMDHelp : public ICMDBase {
public:
    TestCMDHelp():
        ICMDBase("help", "-h", "Display the help info.")
    {}

    void HelpInfo() override {
        printf("This is help info of cmd %s|%s.\n", name.c_str(), short_name.c_str());
    }

    void Execute() override {
        printf("You execute the cmd %s|%s\n", name.c_str(), short_name.c_str());
    }
};

static TestCMDHelp testCMDHelp;