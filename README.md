
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

### Build options

* BUILD_PYTHON_BINDINGS: (Default: ON) Build python bindings for S2 Geometry Library
* USE_CLANG: (Default: OFF) Build with clang compiler

## Testing Python Bindings

    python -c 'import s2_geometry as s2; print(s2.S2LatLng( s2.S1Angle.Degrees(180), s2.S1Angle.Degrees(15) ))'
