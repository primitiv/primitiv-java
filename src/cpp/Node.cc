/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Device.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Node_jniNew(JNIEnv *env, jclass cls) {
  return to_jlong(new Node());
}

JNIEXPORT void JNICALL Java_primitiv_Node_jniDelete(JNIEnv *env, jclass cls, jlong handle) {
  delete to_object_ptr<Node>(handle);
}

JNIEXPORT jboolean JNICALL Java_primitiv_Node_jniValid(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Node>(handle).valid();
}

JNIEXPORT jlong JNICALL Java_primitiv_Node_jniGraph(JNIEnv *env, jclass cls, jlong handle) {
  return to_jlong(&to_object<Node>(handle).graph());
}

JNIEXPORT jint JNICALL Java_primitiv_Node_jniOperatorId(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Node>(handle).operator_id();
}

JNIEXPORT jint JNICALL Java_primitiv_Node_jniValueId(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Node>(handle).value_id();
}

JNIEXPORT jlong JNICALL Java_primitiv_Node_jniShape(JNIEnv *env, jclass cls, jlong handle) {
  return to_jlong(new Shape(to_object<Node>(handle).shape()));
}

JNIEXPORT jlong JNICALL Java_primitiv_Node_jniDevice(JNIEnv *env, jclass cls, jlong handle) {
  return to_jlong(&to_object<Node>(handle).device());
}

JNIEXPORT jfloat JNICALL Java_primitiv_Node_jniToFloat(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Node>(handle).to_float();
}

JNIEXPORT jfloatArray JNICALL Java_primitiv_Node_jniToArray(JNIEnv *env, jclass cls, jlong handle) {
  const std::vector<float> v = to_object<Node>(handle).to_vector();
  jfloatArray result = env->NewFloatArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetFloatArrayRegion(result, 0, v.size(), v.data());
  return result;
}

JNIEXPORT jintArray JNICALL Java_primitiv_Node_jniArgmax(JNIEnv *env, jclass cls, jlong handle, jint dim) {
  const std::vector<uint32_t> v = to_object<Node>(handle).argmax(dim);
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const int32_t *>(v.data()));
  return result;
}

JNIEXPORT jintArray JNICALL Java_primitiv_Node_jniArgmin(JNIEnv *env, jclass cls, jlong handle, jint dim) {
  const std::vector<uint32_t> v = to_object<Node>(handle).argmin(dim);
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const int32_t *>(v.data()));
  return result;
}

JNIEXPORT void JNICALL Java_primitiv_Node_jniBackward(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Node>(handle).backward();
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
