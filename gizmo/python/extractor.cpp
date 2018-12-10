#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <memory>

#include "extractor.h"

namespace py = pybind11;

using namespace std;


void initExtractorWrapper(py::module &m)
{
	py::class_<Extractor, shared_ptr<Extractor>> extractor(m, "Extractor");
	extractor.def(py::init<std::shared_ptr<Demux>>());
	extractor.def("getStreamsInfo", &Extractor::getStreamsInfo);
	extractor.def("selectTimeWindow", &Extractor::selectTimeWindow);
	extractor.def("connectEosCallback", &Extractor::connectEosCallback);
	extractor.def("connectErrorCallback", &Extractor::connectErrorCallback);
	extractor.def("start", &Extractor::start);
	extractor.def("stop", &Extractor::stop);
	extractor.def("isRunning", &Extractor::isRunning);
}
