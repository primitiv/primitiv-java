/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_SGD.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_SGD_jniNew(JNIEnv *env, jobject thisj, jfloat eta) {
  return to_jlong(new optimizers::SGD(eta));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_SGD_jniEta(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::SGD>(handle).eta();
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
