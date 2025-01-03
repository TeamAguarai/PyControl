#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "build/control.h" // este archivo solo existe despues de ejecutar build.sh

namespace py = pybind11;

PYBIND11_MODULE(pycontrol, m) {
    m.doc() = "Bindings for control library";

    m.def("hello", &control::hello);

    // Conversion class
    py::class_<control::Conversion>(m, "Conversion")
        .def(py::init<>())
        .def("isDefined", &control::Conversion::isDefined)
        .def("define", &control::Conversion::define)
        .def("convert", &control::Conversion::convert);

    // Drive class
    py::class_<control::Drive>(m, "Drive")
        .def(py::init<>())
        .def("run", &control::Drive::run)
        .def("stop", &control::Drive::stop)
        .def("definePid", &control::Drive::definePid)
        .def("defineTransferFunction", &control::Drive::defineTransferFunction)
        .def("defineMotor", &control::Drive::defineMotor)
        .def("defineVelocimeter", &control::Drive::defineVelocimeter);

    // GPIO namespace
    py::module_ gpio = m.def_submodule("gpio", "GPIO bindings");
    gpio.def("setupGpioPinout", &control::gpio::setupGpioPinout);
    gpio.def("pwmWrite", &control::gpio::pwmWrite);
    gpio.def("pinMode", &control::gpio::pinMode);
    gpio.def("digitalWrite", &control::gpio::digitalWrite);
    gpio.def("digitalRead", &control::gpio::digitalRead);
    gpio.def("delay", &control::gpio::delay);
    gpio.def("onInterrupt", &control::gpio::onInterrupt);
    gpio.def("stopOnInterrupt", &control::gpio::stopOnInterrupt);
    gpio.def("reset", &control::gpio::reset);

    // LowPass class
    py::class_<control::LowPass>(m, "LowPass")
        .def(py::init<>())
        .def("defineAlpha", &control::LowPass::defineAlpha)
        .def("filter", &control::LowPass::filter);

    // Motor class
    py::class_<control::Motor>(m, "Motor")
        .def(py::init<>())
        .def("definePin", &control::Motor::definePin)
        .def("definePulseWidthRange", &control::Motor::definePulseWidthRange)
        .def("setPulseWidth", &control::Motor::setPulseWidth)
        .def("cleanup", &control::Motor::cleanup);

    // PID class
    py::class_<control::PID>(m, "PID")
        .def(py::init<>())
        .def("setGains", &control::PID::setGains)
        .def("setParameters", &control::PID::setParameters)
        .def("calculate", &control::PID::calculate);

    // PulseWidth class
    py::class_<control::PulseWidth>(m, "PulseWidth")
        .def(py::init<>())
        .def("define", &control::PulseWidth::define)
        .def("isDefined", &control::PulseWidth::isDefined)
        .def("validate", &control::PulseWidth::validate);

    // Velocimeter class
    py::class_<control::Velocimeter>(m, "Velocimeter")
        .def(py::init<>())
        .def("definePin", &control::Velocimeter::definePin)
        .def("defineWheelDiameter", &control::Velocimeter::defineWheelDiameter)
        .def("defineAlpha", &control::Velocimeter::defineAlpha)
        .def("getUpdateTimeInterval", &control::Velocimeter::getUpdateTimeInterval)
        .def("getSpeed", &control::Velocimeter::getSpeed)
        .def("getDistance", &control::Velocimeter::getDistance)
        .def("resetDistance", &control::Velocimeter::resetDistance)
        .def("waitForUpdate", &control::Velocimeter::waitForUpdate)
        .def("start", &control::Velocimeter::start)
        .def("cleanup", &control::Velocimeter::cleanup);

    // Writer class
    py::class_<control::Writer>(m, "Writer")
        .def(py::init<std::string, std::string, std::string>())
        .def("write_row", &control::Writer::write_row)
        .def("close", &control::Writer::close);
}
