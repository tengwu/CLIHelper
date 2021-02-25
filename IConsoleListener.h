//
// Created by wuteng on 2020/5/31.
//
/*!
 * @file 监听用户按键、命令补全等
 */

#ifndef CLIHELPER_ICONSOLELISTENER_H
#define CLIHELPER_ICONSOLELISTENER_H


class IConsoleListener {
public:
    IConsoleListener(){}
    ~IConsoleListener(){};

    virtual void MainLoop(int argc, char **argv);
};


#endif //CLIHELPER_ICONSOLELISTENER_H
