/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Tensor.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniNew(JNIEnv *env, jobject thisj) {
  return to_jlong(new Tensor());
}

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniNewFromTensor(JNIEnv *env, jobject thisj, jlong tensor) {
  return to_jlong(new Tensor(to_object<Tensor>(tensor)));
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_object_ptr<Tensor>(handle);
}

JNIEXPORT jboolean JNICALL Java_primitiv_Tensor_jniValid(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Tensor>(handle).valid();
}

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniShape(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(new Shape(to_object<Tensor>(handle).shape()));
}

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniDevice(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(&to_object<Tensor>(handle).device());
}

JNIEXPORT jfloat JNICALL Java_primitiv_Tensor_jniToFloat(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Tensor>(handle).to_float();
}

JNIEXPORT jfloatArray JNICALL Java_primitiv_Tensor_jniToArray(JNIEnv *env, jobject thisj, jlong handle) {
  const std::vector<float> v = to_object<Tensor>(handle).to_vector();
  jfloatArray result = env->NewFloatArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetFloatArrayRegion(result, 0, v.size(), v.data());
  return result;
}

JNIEXPORT jintArray JNICALL Java_primitiv_Tensor_jniArgmax(JNIEnv *env, jobject thisj, jlong handle, jint dim) {
  const std::vector<uint32_t> v = to_object<Tensor>(handle).argmax(dim);
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const int32_t *>(v.data()));
  return result;
}

JNIEXPORT jintArray JNICALL Java_primitiv_Tensor_jniArgmin(JNIEnv *env, jobject thisj, jlong handle, jint dim) {
  const std::vector<uint32_t> v = to_object<Tensor>(handle).argmin(dim);
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const int32_t *>(v.data()));
  return result;
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniReset(JNIEnv *env, jobject thisj, jlong handle, jfloat k) {
  to_object<Tensor>(handle).reset(k);
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniResetByArray(JNIEnv *env, jobject thisj, jlong handle, jfloatArray values) {
  JNIFloatArrayAccess values_access(env, values);
  to_object<Tensor>(handle).reset_by_array(values_access.data());
}

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniReshape(JNIEnv *env, jobject thisj, jlong handle, jlong new_shape) {
  return to_jlong(new Tensor(to_object<Tensor>(handle).reshape(to_object<Shape>(new_shape))));
}

JNIEXPORT jlong JNICALL Java_primitiv_Tensor_jniFlatten(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(new Tensor(to_object<Tensor>(handle).flatten()));
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniInplaceMultiplyConst(JNIEnv *env, jobject thisj, jlong handle, jfloat k) {
  to_object<Tensor>(handle) *= k;
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniInplaceAdd(JNIEnv *env, jobject thisj, jlong handle, jlong x) {
  to_object<Tensor>(handle) += to_object<Tensor>(x);
}

JNIEXPORT void JNICALL Java_primitiv_Tensor_jniInplaceSubtract(JNIEnv *env, jobject thisj, jlong handle, jlong x) {
  to_object<Tensor>(handle) -= to_object<Tensor>(x);
}

}

}  // namespace jni

}  // namespace primitiv
