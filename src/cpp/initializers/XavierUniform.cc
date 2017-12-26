/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_initializers_XavierUniform.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_initializers_XavierUniform_jniNew(JNIEnv *env, jobject thisj, jfloat scale) {
  return to_jlong(new initializers::XavierUniform(scale));
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
