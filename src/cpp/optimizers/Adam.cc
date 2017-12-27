/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_optimizers_Adam.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_optimizers_Adam_jniNew(JNIEnv *env, jobject thisj, jfloat alpha, jfloat beta1, jfloat beta2, jfloat eps) {
  return to_jlong(new optimizers::Adam(alpha, beta1, beta2, eps));
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_Adam_jniAlpha(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::Adam>(handle).alpha();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_Adam_jniBeta1(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::Adam>(handle).beta1();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_Adam_jniBeta2(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::Adam>(handle).beta2();
}

JNIEXPORT jfloat JNICALL Java_primitiv_optimizers_Adam_jniEps(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<optimizers::Adam>(handle).eps();
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
