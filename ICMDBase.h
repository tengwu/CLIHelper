//
// Created by wuteng on 2020/5/31.
//

#ifndef CMDHELPER_ICMDBASE_H
#define CMDHELPER_ICMDBASE_H

#include <string>

class ICMDBase {
public:
    ICMDBase() {}
    ICMDBase(const char *name, const char *short_name, const char *description);

    ~ICMDBase();

    /*!
     * @brief HelpInfo info
     */
    virtual void HelpInfo() {};

    /*!
     * @brief The implementation of the command.
     */
    virtual void Execute() {};

protected:
    std::string name;
    std::string short_name;
    std::string description;
};


#endif //CMDHELPER_ICMDBASE_H
