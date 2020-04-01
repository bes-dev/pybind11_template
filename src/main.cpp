#include <pybind11/pybind11.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv_wrapper/ndarray_converter.h"

namespace py = pybind11;

class Example {
public:
    Example() {}
    virtual std::string hello() {
        return std::string("hello world");
    }
};

class PyExample : public Example {
public:
    using Example::Example;

    std::string hello() override {
        PYBIND11_OVERLOAD_PURE(
            std::string,
            Example,
            hello,
        );
    }
};

PYBIND11_MODULE(class_wrapper, m) {
    py::class_<Example, PyExample>(m, "Example")
        .def(py::init<>())
        .def("hello", &Example::hello);
}
