/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Optimizer.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_object_ptr<Optimizer>(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniLoad(JNIEnv *env, jobject thisj, jlong handle, jstring path) {
  JNIStringAccess path_access(env, path);
  to_object<Optimizer>(handle).load(path_access.get_string());
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniSave(JNIEnv *env, jobject thisj, jlong handle, jstring path) {
  JNIStringAccess path_access(env, path);
  to_object<Optimizer>(handle).save(path_access.get_string());
}

JNIEXPORT jint JNICALL Java_primitiv_Optimizer_jniGetEpoch(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Optimizer>(handle).get_epoch();
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniSetEpoch(JNIEnv *env, jobject thisj, jlong handle, jint epoch) {
  to_object<Optimizer>(handle).set_epoch(epoch);
}

JNIEXPORT jfloat JNICALL Java_primitiv_Optimizer_jniGetLearningRateScaling(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Optimizer>(handle).get_learning_rate_scaling();
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniSetLearningRateScaling(JNIEnv *env, jobject thisj, jlong handle, jfloat scale) {
  to_object<Optimizer>(handle).set_learning_rate_scaling(scale);
}

JNIEXPORT jfloat JNICALL Java_primitiv_Optimizer_jniGetWeightDecay(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Optimizer>(handle).get_weight_decay();
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniSetWeightDecay(JNIEnv *env, jobject thisj, jlong handle, jfloat strength) {
  to_object<Optimizer>(handle).set_weight_decay(strength);
}

JNIEXPORT jfloat JNICALL Java_primitiv_Optimizer_jniGetGradientClipping(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Optimizer>(handle).get_gradient_clipping();
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniSetGradientClipping(JNIEnv *env, jobject thisj, jlong handle, jfloat threshold) {
  to_object<Optimizer>(handle).set_gradient_clipping(threshold);
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniAdd(JNIEnv *env, jobject thisj, jlong handle, jlong param) {
  to_object<Optimizer>(handle).add(to_object<Parameter>(param));
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniResetGradients(JNIEnv *env, jobject thisj, jlong handle) {
  to_object<Optimizer>(handle).reset_gradients();
}

JNIEXPORT void JNICALL Java_primitiv_Optimizer_jniUpdate(JNIEnv *env, jobject thisj, jlong handle) {
  to_object<Optimizer>(handle).update();
}

}

}  // namespace jni

}  // namespace primitiv
