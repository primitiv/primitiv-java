/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_MomentumSGD.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_MomentumSGD_jniNew(JNIEnv *env, jobject thisj, jfloat eta, jfloat momentum) {
  return to_jlong(new optimizers::MomentumSGD(eta, momentum));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_MomentumSGD_jniEta(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::MomentumSGD>(handle).eta();

}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_MomentumSGD_jniMomentum(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::MomentumSGD>(handle).momentum();

}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
