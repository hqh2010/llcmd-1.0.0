#include <iostream>

#include "basecmd/llInvoker.h"

int main(int argc, char **argv)
{
    llInvoker *p = new llInvoker();
    // 调试参数也可以在 vs code中指定
    // int argcd = 3;
    // char *argvd[] = {"path", "--help", "123"};
    // cout << "调试参数 argv[1]=" << argvd[1] << ", argv[2]=" << argvd[2] << endl;
    int ret = p->runCmd(argc, argv);
    delete p;
    return ret;
}
