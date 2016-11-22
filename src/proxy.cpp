#include "proxy.h"

#include <stdexcept>
#include <Python.h>
#include <cstdio>

namespace Namaki{
namespace Proxy{
void start(){

    auto program = Py_DecodeLocale("./proxy/bin/python", nullptr);

    if (program == nullptr){
        throw std::runtime_error("Fatal error cannot decode ");
    }
    auto file_name = "proxy/run.py";
    FILE *f = fopen(file_name, "r");

    Py_SetProgramName(program);
    Py_Initialize();
    //add proxy dir to the sys.path
    PyRun_SimpleString("import sys, os\n"
            "path = os.path.join(os.getcwd(), 'proxy')\n"
            "sys.path.append(path)"
        );
    auto return_code = PyRun_SimpleFile(f, file_name);
    if (return_code != 0 ){
        throw std::runtime_error("run.py unable to run");
    }
    Py_Finalize();
    PyMem_RawFree(program);
    fclose(f);
}
}
}
