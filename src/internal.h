/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#ifndef PRIMITIV_INTERNAL_H_
#define PRIMITIV_INTERNAL_H_

inline jlong to_j(void *instance) {
  return reinterpret_cast<jlong>(instance);
}

#endif  // JPRIMITIV_INTERNAL_H_