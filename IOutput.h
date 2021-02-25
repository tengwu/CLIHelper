//
// Created by wuteng on 2020/5/31.
//

/*!
 * @file 内容输出
 */
#ifndef CLIHELPER_IOUTPUT_H
#define CLIHELPER_IOUTPUT_H


class IOutput {
public:
    IOutput(){}
    ~IOutput(){}

    virtual void Output(const char *fmt, ...);
};


#endif //CLIHELPER_IOUTPUT_H
