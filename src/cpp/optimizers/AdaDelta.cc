/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_AdaDelta.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_AdaDelta_jniNew(JNIEnv *env, jobject thisj, jfloat rho, jfloat eps) {
  return to_jlong(new optimizers::AdaDelta(rho, eps));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_AdaDelta_jniRho(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::AdaDelta>(handle).rho();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_AdaDelta_jniEps(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::AdaDelta>(handle).eps();
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
