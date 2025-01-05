#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "build/pampas.h" // este archivo solo existe despues de ejecutar build.sh

namespace py = pybind11;

PYBIND11_MODULE(pypampas, m) {
    m.doc() = "Bindings for pampas library";

    m.def("hello", &pampas::hello);

    // Conversion class
    py::class_<pampas::Conversion>(m, "Conversion")
        .def(py::init<>())
        .def("isDefined", &pampas::Conversion::isDefined)
        .def("define", &pampas::Conversion::define)
        .def("convert", &pampas::Conversion::convert);

    // Drive class
    py::class_<pampas::Drive>(m, "Drive")
        .def(py::init<>())
        .def("run", &pampas::Drive::run)
        .def("stop", &pampas::Drive::stop)
        .def("definePid", &pampas::Drive::definePid)
        .def("defineTransferFunction", &pampas::Drive::defineTransferFunction)
        .def("defineMotor", &pampas::Drive::defineMotor)
        .def("defineVelocimeter", &pampas::Drive::defineVelocimeter);

    // GPIO namespace
    py::module_ gpio = m.def_submodule("gpio", "GPIO bindings");
    gpio.def("setupGpioPinout", &pampas::gpio::setupGpioPinout);
    gpio.def("pwmWrite", &pampas::gpio::pwmWrite);
    gpio.def("pinMode", &pampas::gpio::pinMode);
    gpio.def("digitalWrite", &pampas::gpio::digitalWrite);
    gpio.def("digitalRead", &pampas::gpio::digitalRead);
    gpio.def("delay", &pampas::gpio::delay);
    gpio.def("onInterrupt", &pampas::gpio::onInterrupt);
    gpio.def("stopOnInterrupt", &pampas::gpio::stopOnInterrupt);
    gpio.def("reset", &pampas::gpio::reset);

    // LowPass class
    py::class_<pampas::LowPass>(m, "LowPass")
        .def(py::init<>())
        .def("defineAlpha", &pampas::LowPass::defineAlpha)
        .def("filter", &pampas::LowPass::filter);

    // Motor class
    py::class_<pampas::Motor>(m, "Motor")
        .def(py::init<>())
        .def("definePin", &pampas::Motor::definePin)
        .def("definePulseWidthRange", &pampas::Motor::definePulseWidthRange)
        .def("setPulseWidth", &pampas::Motor::setPulseWidth)
        .def("cleanup", &pampas::Motor::cleanup);

    // PID class
    py::class_<pampas::PID>(m, "PID")
        .def(py::init<>())
        .def("setGains", &pampas::PID::setGains)
        .def("setParameters", &pampas::PID::setParameters)
        .def("calculate", &pampas::PID::calculate);

    // PulseWidth class
    py::class_<pampas::PulseWidth>(m, "PulseWidth")
        .def(py::init<>())
        .def("define", &pampas::PulseWidth::define)
        .def("isDefined", &pampas::PulseWidth::isDefined)
        .def("validate", &pampas::PulseWidth::validate);

    // Velocimeter class
    py::class_<pampas::Velocimeter>(m, "Velocimeter")
        .def(py::init<>())
        .def("definePin", &pampas::Velocimeter::definePin)
        .def("defineWheelDiameter", &pampas::Velocimeter::defineWheelDiameter)
        .def("defineAlpha", &pampas::Velocimeter::defineAlpha)
        .def("getUpdateTimeInterval", &pampas::Velocimeter::getUpdateTimeInterval)
        .def("getSpeed", &pampas::Velocimeter::getSpeed)
        .def("getDistance", &pampas::Velocimeter::getDistance)
        .def("resetDistance", &pampas::Velocimeter::resetDistance)
        .def("waitForUpdate", &pampas::Velocimeter::waitForUpdate)
        .def("start", &pampas::Velocimeter::start)
        .def("cleanup", &pampas::Velocimeter::cleanup);

    // Writer class
    py::class_<pampas::Writer>(m, "Writer")
        .def(py::init<std::string, std::string, std::string>())
        .def("write_row", &pampas::Writer::write_row)
        .def("close", &pampas::Writer::close);
}
