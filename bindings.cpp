#include <pybind11/pybind11.h>
#include "build/control.h"

namespace py = pybind11;

PYBIND11_MODULE(pycontrol, m) {
    m.def("pycontrol_hello", &control::hello);
}