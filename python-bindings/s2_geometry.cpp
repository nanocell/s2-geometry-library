
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/noncopyable.hpp>

#include <s1angle.h>
#include <s2latlng.h>
#include <s2region.h>
#include <s2cellid.h>
#include <s2cell.h>
#include <s2cellunion.h>
#include <s2latlngrect.h>


using namespace boost::python;

void s2cellunion__init_from_cell_ids__wrapper(S2CellUnion* c, boost::python::list pylist)
{
    std::vector<S2CellId> v;
    for (int i = 0; i < len(pylist); ++i)
    {
        v.push_back( boost::python::extract<S2CellId>(pylist[i]) );
    }

    c->Init(v);
}



boost::python::list s2cellunion__cell_ids__wrapper(S2CellUnion* c)
{
    const std::vector<S2CellId>& cellids = c->cell_ids();

    std::vector<S2CellId>::const_iterator it;
    boost::python::list l;

    for (it = cellids.begin(); it != cellids.end(); ++it)
    {
        l.append(*it);
    }

    // boost::python::object get_iter = boost::python::iterator<std::vector<S2CellId> >();
    // boost::python::object iter = get_iter(cellids);
    
    return l;
}

// wrapper to convert the unsigned id to a signed value
// to match the Java S2 Geometry library implementation.
signed long long get_cell_signed_id(S2CellId& c)
{
    return static_cast<signed long long>(c.id());
}

BOOST_PYTHON_MODULE(s2_geometry)
{
    class_<S1Angle>("S1Angle", init<>())
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

    class_<S2CellId>("S2CellId", init<>())
        .def(init<uint64>())

        .def("child_begin",       static_cast<S2CellId (S2CellId::*)() const>(&S2CellId::child_begin))
        .def("child_begin_level", static_cast<S2CellId (S2CellId::*)(int) const>(&S2CellId::child_begin))
        .def("child_end",         static_cast<S2CellId (S2CellId::*)() const>(&S2CellId::child_end))
        .def("child_end_level",   static_cast<S2CellId (S2CellId::*)(int) const>(&S2CellId::child_end))

        .def("next", &S2CellId::next)
        .def("prev", &S2CellId::prev)

        .def("Begin", &S2CellId::Begin)
        .def("End", &S2CellId::End)

        .def("id", &get_cell_signed_id)
        // .def("id", &S2CellId::id)
        .def("is_leaf", &S2CellId::is_leaf)

        .def("is_valid", &S2CellId::is_valid)

        .def("to_string", &S2CellId::ToString)

        .def("range_min", &S2CellId::range_min)
        .def("range_max", &S2CellId::range_max)
    ;

    class_<S2Cell>("S2Cell", init<S2CellId>())
        // .def(init<S2Point>())
        .def(init<S2LatLng>())

        .def("id", &S2Cell::id)
        

        .def("get_vertex", &S2Cell::GetVertex)        
        .def("get_center", &S2Cell::GetCenter)
    ;

    class_<S2CellUnion, boost::noncopyable>("S2CellUnion")
        // .def("init_from_cell_ids", static_cast<void (S2CellUnion::*)(std::vector<S2CellId> const&)>(&S2CellUnion::Init))
        .def("init_from_cell_ids", &s2cellunion__init_from_cell_ids__wrapper)
        .def("num_cells", &S2CellUnion::num_cells)
        .def("cell_ids", s2cellunion__cell_ids__wrapper)
    ;

    class_<S2Point>("S2Point")
        .def("x", static_cast<S2Point::BaseType (S2Point::*)() const>(&S2Point::x))
        .def("y", static_cast<S2Point::BaseType (S2Point::*)() const>(&S2Point::y))
        .def("z", static_cast<S2Point::BaseType (S2Point::*)() const>(&S2Point::z))
    ;

    
    bool (S2LatLngRect::*intersects_cell)(S2Cell const&) const = &S2LatLngRect::Intersects;

    class_<S2LatLngRect>("S2LatLngRect", init<>())
        .def(init<S2LatLng, S2LatLng>())

        .def("intersects_cell", intersects_cell)
        .def("area", &S2LatLngRect::Area)
        .def("lat_lo", &S2LatLngRect::lat_lo)
        .def("lat_hi", &S2LatLngRect::lat_hi)
        .def("lng_lo", &S2LatLngRect::lng_lo)
        .def("lng_hi", &S2LatLngRect::lng_hi)
    ;
}

