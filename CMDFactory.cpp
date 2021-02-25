//
// Created by wuteng on 2020/5/31.
//

#include "CMDFactory.h"
#include "ICMDBase.h"
#include <iostream>
using namespace std;

CMDFactory *CMDFactory::instance = nullptr;
std::mutex CMDFactory::singleton_lock;

void CMDFactory::RegisterCMD(const std::string &name, ICMDBase *cmd)
{
    lock_guard<mutex> _lock(cmds_lock);
    if (cmds.find(name) == cmds.end())
        cmds[name] = cmd;
}

void CMDFactory::UnregisterCMD(const std::string &name)
{
    lock_guard<mutex> _lock(cmds_lock);
    if (cmds.find(name) != cmds.end())
        cmds.erase(name);
}

void CMDFactory::Process(int argc, const char **argv)
{
    cout << "argc: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    // 1. parse the arguments


    // 2. run the command

}
