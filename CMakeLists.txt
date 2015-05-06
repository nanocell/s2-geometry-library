
cmake_minimum_required(VERSION 3.0)

find_package(PythonLibs)
find_package(Boost 1.58.0 COMPONENTS python3)
find_package(OpenSSL)

include_directories(
	./geometry
	./thirdparty
)

add_definitions(-DNDEBUG -DS2_USE_EXACTFLOAT -DARCH_K8)
set(CMAKE_CXX_FLAGS "-std=c++0x")

add_library(google_util_geometry_s2cellid 
	SHARED
	geometry/s1angle.cc
	geometry/s2.cc
	geometry/s2cellid.cc
	geometry/s2latlng.cc
)

add_library(google_util_coding 
	SHARED
	geometry/util/coding/coder.cc
	geometry/util/coding/varint.cc	
)

add_library(google_util_geometry_s2 
	SHARED
	geometry/s1interval.cc
	geometry/s2cap.cc
	geometry/s2cell.cc
	geometry/s2cellunion.cc
	geometry/s2edgeindex.cc
	geometry/s2edgeutil.cc
	geometry/s2latlngrect.cc
	geometry/s2loop.cc
	geometry/s2pointregion.cc
	geometry/s2polygon.cc
	geometry/s2polygonbuilder.cc
	geometry/s2polyline.cc
	geometry/s2r2rect.cc
	geometry/s2region.cc
	geometry/s2regioncoverer.cc
	geometry/s2regionintersection.cc
	geometry/s2regionunion.cc
)


add_library(google_util_math SHARED
	geometry/util/math/mathutil.cc
	# geometry/util/math/mathlimits.cc
	geometry/util/math/exactfloat/exactfloat.cc
)

add_library(google_base SHARED
	geometry/base/int128.cc
	geometry/base/strtoint.cc
	geometry/base/logging.cc
	geometry/base/stringprintf.cc	
)

add_library(google_strings SHARED
	geometry/strings/ascii_ctype.cc
	geometry/strings/split.cc
	geometry/strings/stringprintf.cc
	geometry/strings/strutil.cc	
)

message("Python:  ${PYTHONLIBS_FOUND}")
message("Boost:   ${Boost_FOUND}")
message("OpenSSL: ${OPENSSL_FOUND}")


if (PYTHONLIBS_FOUND AND Boost_FOUND)
	string(REPLACE "." ";" VERSION_LIST ${PYTHONLIBS_VERSION_STRING})
	list(GET VERSION_LIST 0 PYTHON_VERSION_MAJOR)
	list(GET VERSION_LIST 1 PYTHON_VERSION_MINOR)
	set(PYTHON_VERSION_STRING "${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

	message("----------")
	message("PythonLibs: (${PYTHON_VERSION_STRING})")
	message("  inc: ${PYTHON_INCLUDE_DIRS}")
	message("  lib: ${PYTHON_LIBRARIES}")
	message("----------")
	message("Boost: (${Boost_VERSION})")
	message("  inc: ${Boost_INCLUDE_DIRS}")
	message("  lib: ${Boost_LIBRARIES}")
	message("----------")
	message("OpenSSL: (${OPENSSL_VERSION})")
	message("  inc: ${OPENSSL_INCLUDE_DIRS}")
	message("  lib: ${OPENSSL_LIBRARIES}")
	message("----------")

	include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

	# Python Bindings for geometry_s2 library
	file(GLOB geometry_s2_py_cpp "python-bindings/*.cpp")
	add_library(geometry_s2 SHARED
		${geometry_s2_py_cpp}
	)
	set_target_properties(geometry_s2 PROPERTIES PREFIX "")

	target_link_libraries(geometry_s2 
		${PYTHON_LIBRARIES} 
		${Boost_LIBRARIES} 
		${OPENSSL_LIBRARIES}
		google_base
		google_strings
		google_util_geometry_s2
		google_util_geometry_s2cellid
		google_util_coding
		google_util_math
		z
	)

	install(TARGETS
	geometry_s2

	DESTINATION
	lib/python${PYTHON_VERSION_STRING}/site-packages
	)

endif (PYTHONLIBS_FOUND AND Boost_FOUND)

install(TARGETS
	google_base
	google_strings
	google_util_geometry_s2cellid
	google_util_geometry_s2
	google_util_coding
	google_util_math
	
	DESTINATION 
	lib
)
