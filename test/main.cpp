#include <iostream>
#include <string>
#include "CMDFactory.h"

using namespace std;

int main(int argc, const char * argv[])
{
    CMDFactory *cmdFactory = CMDFactory::Singleton();
#ifdef _DEBUG
    cmdFactory->ListAllCMDs();
#endif

    return 0;
}
