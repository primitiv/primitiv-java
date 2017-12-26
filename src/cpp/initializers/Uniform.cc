/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_initializers_Uniform.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_initializers_Uniform_jniNew(JNIEnv *env, jobject thisj, jfloat lower, jfloat upper) {
  return to_jlong(new initializers::Uniform(lower, upper));
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
