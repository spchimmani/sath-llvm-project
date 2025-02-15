//===-- Internal header for assert ------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_ASSERT_ASSERT_H
#define LLVM_LIBC_SRC_ASSERT_ASSERT_H

#include "src/assert/__assert_fail.h"

// There is no header guard here since assert is intended to be capable of being
// included multiple times with NDEBUG defined differently, causing different
// behavior.

#undef assert

#ifdef NDEBUG
#define assert(e) (void)0
#else
#define assert(e)                                                              \
  ((e) ? (void)0                                                               \
       : LIBC_NAMESPACE::__assert_fail(#e, __FILE__, __LINE__,                 \
                                       __PRETTY_FUNCTION__))
#endif // NDEBUG

#endif // LLVM_LIBC_SRC_ASSERT_ASSERT_H
