/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_initializers_Normal.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_initializers_Normal_jniNew(JNIEnv *env, jobject thisj, jfloat mean, jfloat sd) {
  return to_jlong(new initializers::Normal(mean, sd));
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
