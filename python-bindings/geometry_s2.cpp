
#include <boost/python.hpp>
#include <s1angle.h>
#include <s2latlng.h>

using namespace boost::python;

BOOST_PYTHON_MODULE(geometry_s2)
{
    class_<S1Angle>("S1Angle")
        .def("Degrees", &S1Angle::Degrees)
        .def("Radians", &S1Angle::Radians)
        
        .def("radians", &S1Angle::radians)
        .def("degrees", &S1Angle::degrees)
        // .def("set", &World::set)
    ;

    class_<S2LatLng>("S2LatLng")
    		.def(init<S1Angle, S1Angle>())
        .def("FromDegrees", &S2LatLng::FromDegrees)
        .def("FromRadians", &S2LatLng::FromRadians)

        .def("lat", &S2LatLng::lat)
        .def("lng", &S2LatLng::lng)
        
        .def("is_valid", &S2LatLng::is_valid)
        
    ;
}

