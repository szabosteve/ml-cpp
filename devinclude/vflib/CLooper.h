/*
 * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
 * or more contributor license agreements. Licensed under the Elastic License;
 * you may not use this file except in compliance with the Elastic License.
 */
#ifndef INCLUDED_ml_vflib_CLooper_h
#define INCLUDED_ml_vflib_CLooper_h

#include <vflib/ImportExport.h>

#include <stddef.h>

namespace ml {
namespace vflib {
class CIncrementer;

//! \brief
//! Class for measuring function call overhead.
//!
//! DESCRIPTION:\n
//! Class for measuring function call overhead within a shared
//! library.
//!
//! IMPLEMENTATION DECISIONS:\n
//! These functions are in their own translation unit to:
//! a) Prevent the compiler from choosing to inline functions
//!    other than the intended one
//! b) To ensure that the object code of these loops is in the
//!    intended library
//!
class VFLIB_EXPORT CLooper {
public:
    //! Loop calling the inlined incrementer
    static size_t inlinedLibraryCallLoop(CIncrementer& incrementer, size_t count, size_t val);

    //! Loop calling the non-virtual incrementer
    static size_t nonVirtualLibraryCallLoop(CIncrementer& incrementer, size_t count, size_t val);

    //! Loop calling the virtual incrementer
    static size_t virtualLibraryCallLoop(CIncrementer& incrementer, size_t count, size_t val);
};
}
}

#endif // INCLUDED_ml_vflib_CLooper_h
