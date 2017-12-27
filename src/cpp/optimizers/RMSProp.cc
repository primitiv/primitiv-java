/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_RMSProp.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_RMSProp_jniNew(JNIEnv *env, jobject thisj, jfloat eta, jfloat alpha, jfloat eps) {
  return to_jlong(new optimizers::RMSProp(eta, alpha, eps));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_RMSProp_jniEta(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::RMSProp>(handle).eta();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_RMSProp_jniAlpha(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::RMSProp>(handle).alpha();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_RMSProp_jniEps(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::RMSProp>(handle).eps();
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
