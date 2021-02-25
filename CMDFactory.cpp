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

void CMDFactory::Process(ParamSet *paramSet, IOutput *log, IOutput *con)
{
    string subcmd = paramSet->GetSubCMD();
    // run the command
    lock_guard<mutex> _lock(cmds_lock);
    if (cmds.find(subcmd) != cmds.end()) return ;
    cmds[subcmd]->Execute(paramSet, log, con);
}
