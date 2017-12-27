/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_AdaGrad.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_AdaGrad_jniNew(JNIEnv *env, jobject thisj, jfloat eta, jfloat eps) {
  return to_jlong(new optimizers::AdaGrad(eta, eps));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_AdaGrad_jniEta(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::AdaGrad>(handle).eta();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_AdaGrad_jniEps(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::AdaGrad>(handle).eps();
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
