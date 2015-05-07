
#ifndef _BASE_MACROS2_H_
#define _BASE_MACROS2_H_

// An older, politically incorrect name for the DISALLOW_COPY_AND_ASSIGN.
// Prefer DISALLOW_COPY_AND_ASSIGN for new code.
#define DISALLOW_EVIL_CONSTRUCTORS(TypeName) DISALLOW_COPY_AND_ASSIGN(TypeName)

// A macro to disallow all the implicit constructors, namely the
// default constructor, copy constructor and operator= functions.
//
// This should be used in the private: declarations for a class
// that wants to prevent anyone from instantiating it. This is
// especially useful for classes containing only static methods.
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName();                                    \
  DISALLOW_COPY_AND_ASSIGN(TypeName)

#endif
