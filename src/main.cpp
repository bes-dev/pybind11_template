#include <pybind11/pybind11.h>
#include <iostream>
#include <opencv2/core/core.hpp>

namespace py = pybind11;

class Example {
public:
    Example() {}
    virtual std::string hello() {
        cv::Mat img(1000, 1000, CV_8U);
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
