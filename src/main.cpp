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
    virtual void imshow(std::string title, cv::Mat& img) {
        cv::imshow(title, img);
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
    void imshow(std::string title, cv::Mat& img) override {
        PYBIND11_OVERLOAD_PURE(
            void, /* Return type */
            Example,      /* Parent class */
            imshow,          /* Name of function in C++ (must match Python name) */
            title, img      /* Argument(s) */
        );
    }
};

PYBIND11_MODULE(class_wrapper, m) {
    py::class_<Example, PyExample>(m, "Example")
        .def(py::init<>())
        .def("hello", &Example::hello)
        .def("imshow", &Example::imshow);
}
