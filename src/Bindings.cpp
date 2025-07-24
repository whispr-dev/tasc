#include <pybind11/pybind11.h>
#include "TASCGrid.h"

namespace py = pybind11;

PYBIND11_MODULE(TASCEmu, m) {
    py::class_<TASCGrid>(m, "TASCGrid")
        .def(py::init<int,int>())
        .def("set_cell_tag", &TASCGrid::setCellTag)
        .def("transport_data", &TASCGrid::transportData)
        .def("step", &TASCGrid::step)
        .def("get_cell_stack_top", &TASCGrid::getCellStackTop);
}
