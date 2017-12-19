/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Shape.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniNew(JNIEnv *env, jobject thisj) {
  Shape *shape = new Shape();
  return to_jlong(shape);
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniNewWithDims(JNIEnv *env, jobject thisj, jintArray dims, jint batch) {
  JNIIntArrayAccess dims_access(env, dims);
  std::vector<uint32_t> dims_vec = dims_access.get_vector_unsigned();
  return to_jlong(new Shape(dims_vec, batch));
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniDelete(JNIEnv *env, jobject thisj, jlong shape) {
  delete to_shape_ptr(shape);
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniGetitem(JNIEnv *env, jobject thisj, jlong shape, jint dim) {
  return static_cast<jint>(to_shape(shape)[dim]);
}

JNIEXPORT jintArray JNICALL Java_primitiv_Shape_jniDims(JNIEnv *env, jobject thisj, jlong shape) {
  const std::vector<uint32_t> v = to_shape(shape).dims();
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const jint*>(v.data()));
  return result;
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniDepth(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(to_shape(shape).depth());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniBatch(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(to_shape(shape).batch());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniVolume(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(to_shape(shape).volume());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniLowerVolume(JNIEnv *env, jobject thisj, jlong shape, jint dim) {
  return static_cast<jint>(to_shape(shape).lower_volume(dim));
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniSize(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(to_shape(shape).size());
}

JNIEXPORT jstring JNICALL Java_primitiv_Shape_jniToString(JNIEnv *env, jobject thisj, jlong shape) {
  jstring result;
  result = env->NewStringUTF(to_shape(shape).to_string().c_str());
  return result;
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniEqual(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(to_shape(shape) == to_shape(rhs));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniNotEqual(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(to_shape(shape) != to_shape(rhs));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasBatch(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(to_shape(shape).has_batch());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasCompatibleBatch(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(to_shape(shape).has_compatible_batch(to_shape(rhs)));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsScalar(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(to_shape(shape).is_scalar());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsRowVector(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(to_shape(shape).is_row_vector());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsMatrix(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(to_shape(shape).is_matrix());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasSameDims(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(to_shape(shape).has_same_dims(to_shape(rhs)));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasSameLooDims(JNIEnv *env, jobject thisj, jlong shape, jlong rhs, jint dim) {
  return static_cast<jboolean>(to_shape(shape).has_same_loo_dims(to_shape(rhs), dim));
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniResizeDim(JNIEnv *env, jobject thisj, jlong shape, jint dim, jint m) {
  return to_jlong(new Shape(to_shape(shape).resize_dim(dim, m)));
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniResizeBatch(JNIEnv *env, jobject thisj, jlong shape, jint batch) {
  return to_jlong(new Shape(to_shape(shape).resize_batch(batch)));
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniUpdateDim(JNIEnv *env, jobject thisj, jlong shape, jint dim, jint m) {
  to_shape(shape).update_dim(dim, m);
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniUpdateBatch(JNIEnv *env, jobject thisj, jlong shape, jint batch) {
  to_shape(shape).update_batch(batch);
}

}

}  // namespace jni

}  // namespace primitiv
