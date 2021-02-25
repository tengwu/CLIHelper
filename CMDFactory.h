//
// Created by wuteng on 2020/5/31.
//

#ifndef CMDHELPER_CMDFACTORY_H
#define CMDHELPER_CMDFACTORY_H

#include <map>
#include <string>
#include <mutex>
#include "ICMDBase.h"
#include "IOutput.h"

class CMDFactory {
public:
    static CMDFactory *instance;
    static std::mutex singleton_lock;

    /*!
     * @brief Get a single instance of CMDFactory class.
     *
     * @return The pointer to the single CMDFactory instance.
     */
    static CMDFactory *Singleton()
    {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> _lock(singleton_lock);
            if (instance == nullptr) {
                CMDFactory *_instance = new CMDFactory();
                if (_instance)
                    instance = _instance;
            }
        }
        return instance;
    }

    CMDFactory() {
        this->out = new IOutput();
    }

    /*!
     * @brief Register a command to CMDFactory.
     *
     * @param name The name of the command.
     * @param cmd The pointer to the implementation of the command.
     */
    void RegisterCMD(const std::string &name, ICMDBase *cmd);

    /*!
     * @brief Unregister a command from CMDFactory.
     * @param name The name of the command.
     */
    void UnregisterCMD(const std::string &name);

    /*!
     * @brief Run a command.
     *
     * @param argc The size of argv.
     * @param argv Start from subcommand name. For example, we have a docker
     *             command 'docker cp src dest' whose subcommand is cp.
     *             Argv is an array of {"cp", "src", "dest"}, and argc is 3.
     */
    void Process(int argc, const char **argv);

#ifdef _DEBUG
    /*!
     * @brief FOR DEBUG! List all the commands in the system.
     */
    inline void ListAllCMDs() {
        for (auto iter = cmds.begin(); iter != cmds.end(); iter++) {
            out->Output("cmd name: %s\n", iter->first.c_str());
            out->Output("help: ");
            iter->second->HelpInfo();
            out->Output("execute: ");
            iter->second->Execute();
        }
    }
#endif

private:
    using CMD_MAP = std::map<std::string, ICMDBase *>;
    CMD_MAP cmds;
    std::mutex cmds_lock; // readers-writer lock

    IOutput *out;
};


#endif //CMDHELPER_CMDFACTORY_H
