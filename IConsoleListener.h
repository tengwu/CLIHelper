//
// Created by wuteng on 2020/5/31.
//
/*!
 * @file 监听用户按键、命令补全等
 */

#ifndef CLIHELPER_ICONSOLELISTENER_H
#define CLIHELPER_ICONSOLELISTENER_H


#include "IOutput.h"

class IConsoleListener {
private:
    IOutput *log;
    IOutput *con;

public:
    IConsoleListener(){}
    ~IConsoleListener(){};

    virtual void MainLoop(int argc, char **argv);

    inline virtual void SetLog(IOutput *log) {
        this->log = log;
    }

    inline virtual void SetCon(IOutput *con) {
        this->con = con;
    }
};


#endif //CLIHELPER_ICONSOLELISTENER_H
