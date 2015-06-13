
# S2 Geometry Library

## Building S2 Geometry Library with Python Bindings

### Tested on:

- OSX Yosemite (10.10.3), gcc-5.1.0
- ArchLinux 64bit, gcc-5.1.0

### Build Python bindings and install into the python prefix
This method is useful for building/installing into a Python Virtual Environment.

    mkdir build
    cd build
    cmake .. -DBUILD_PYTHON_BINDINGS=ON -DCMAKE_INSTALL_PREFIX=/usr/local
    make install

### Build Python bindings and install into the install prefix
This method is useful is you want to build/install into a custom managed location.

    mkdir build
    cd build
    cmake .. -DBUILD_PYTHON_BINDINGS=ON -DCMAKE_INSTALL_PREFIX=/usr/local
    make install

### Example of building on OSX with Python installed via Homebrew

	mkdir build
	cd build
	_pyexec=/usr/local/bin/python3
	_pylib=/usr/local/Cellar/python3/3.4.3/Frameworks/Python.framework/Versions/3.4/lib/libpython3.4.dylib
	_pyinc=/usr/local/Cellar/python3/3.4.3/Frameworks/Python.framework/Versions/3.4/include/python3.4m
	_pyver=3.4.3

	_osx_flags=-DUSE_CLANG=ON -DPYTHON_INCLUDE_DIR=/usr/local/Cellar/python3/3.4.3/Frameworks/Python.framework/Versions/3.4/Headers -DPYTHON_LIBRARY=/usr/local/Cellar/python3/3.4.3/Frameworks/Python.framework/Versions/3.4/lib/libpython3.4.dylib -DPython_FRAMEWORKS=/usr/local/Cellar/python3/3.4.3/Frameworks/Python.framework

	cmake .. $_osx_flags -DBUILD_PYTHON_BINDINGS=ON -DCMAKE_INSTALL_PREFIX=$HOME/local/s2_geometry -DPYTHON_EXECUTABLE=$_pyexec -DPYTHON_LIBRARY=$_pylib -DPYTHON_INCLUDE_DIR=$_pyinc -DPYTHONLIBS_VERSION_STRING=$_pyver "$@"

### Build options

* BUILD_PYTHON_BINDINGS: (Default: ON) Build python bindings for S2 Geometry Library
* USE_CLANG: (Default: OFF) Build with Clang compiler

Other useful options:

* PYTHON_EXECUTABLE: Path to python executable
* PYTHON_INCLUDE_DIR: Path to include directory
* PYTHON_LIBRARY: Path to python library file

## Testing Python Bindings

    python -c 'import s2_geometry as s2; print(s2.S2LatLng( s2.S1Angle.Degrees(180), s2.S1Angle.Degrees(15) ))'
