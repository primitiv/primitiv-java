#include <primitiv/shape.h>
#include <iostream>
#include "primitiv_Shape.h"

#include "internal.h"

namespace primitiv {

extern "C" {

#define AS_SHAPE_PTR(x) (reinterpret_cast<Shape *>(x))
#define AS_SHAPE(x) (*reinterpret_cast<Shape *>(x))

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniNew(JNIEnv *env, jobject thisj) {
  Shape *shape = new Shape();
  return to_j(shape);
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniNewWithDims(JNIEnv *env, jobject thisj, jintArray dims, jint n, jint batch) {
  const uint32_t *dims_arr = reinterpret_cast<uint32_t *>(env->GetIntArrayElements(dims, 0));
  std::vector<uint32_t> v(dims_arr, dims_arr + n);
  Shape *shape = new Shape(v, batch);
  return to_j(shape);
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniDelete(JNIEnv *env, jobject thisj, jlong shape) {
  delete AS_SHAPE_PTR(shape);
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniGetitem(JNIEnv *env, jobject thisj, jlong shape, jint dim) {
  return static_cast<jint>(AS_SHAPE(shape)[dim]);
}

JNIEXPORT jintArray JNICALL Java_primitiv_Shape_jniDims(JNIEnv *env, jobject thisj, jlong shape) {
  const std::vector<uint32_t> v = AS_SHAPE(shape).dims();
  jintArray result = env->NewIntArray(v.size());
  if (result == nullptr) {
    return NULL;
  }
  env->SetIntArrayRegion(result, 0, v.size(), reinterpret_cast<const jint*>(v.data()));
  return result;
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniDepth(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(AS_SHAPE(shape).depth());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniBatch(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(AS_SHAPE(shape).batch());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniVolume(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(AS_SHAPE(shape).volume());
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniLowerVolume(JNIEnv *env, jobject thisj, jlong shape, jint dim) {
  return static_cast<jint>(AS_SHAPE(shape).lower_volume(dim));
}

JNIEXPORT jint JNICALL Java_primitiv_Shape_jniSize(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jint>(AS_SHAPE(shape).size());
}

JNIEXPORT jstring JNICALL Java_primitiv_Shape_jniToString(JNIEnv *env, jobject thisj, jlong shape) {
  jstring result;
  result = env->NewStringUTF(AS_SHAPE(shape).to_string().c_str());
  return result;
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniEqual(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(AS_SHAPE(shape) == AS_SHAPE(rhs));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniNotEqual(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(AS_SHAPE(shape) != AS_SHAPE(rhs));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasBatch(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(AS_SHAPE(shape).has_batch());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasCompatibleBatch(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(AS_SHAPE(shape).has_compatible_batch(AS_SHAPE(rhs)));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsScalar(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(AS_SHAPE(shape).is_scalar());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsRowVector(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(AS_SHAPE(shape).is_row_vector());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniIsMatrix(JNIEnv *env, jobject thisj, jlong shape) {
  return static_cast<jboolean>(AS_SHAPE(shape).is_matrix());
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasSameDims(JNIEnv *env, jobject thisj, jlong shape, jlong rhs) {
  return static_cast<jboolean>(AS_SHAPE(shape).has_same_dims(AS_SHAPE(rhs)));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Shape_jniHasSameLooDims(JNIEnv *env, jobject thisj, jlong shape, jlong rhs, jint dim) {
  return static_cast<jboolean>(AS_SHAPE(shape).has_same_loo_dims(AS_SHAPE(rhs), dim));
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniResizeDim(JNIEnv *env, jobject thisj, jlong shape, jint dim, jint m) {
  return to_j(new Shape(AS_SHAPE(shape).resize_dim(dim, m)));
}

JNIEXPORT jlong JNICALL Java_primitiv_Shape_jniResizeBatch(JNIEnv *env, jobject thisj, jlong shape, jint batch) {
  return to_j(new Shape(AS_SHAPE(shape).resize_batch(batch)));
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniUpdateDim(JNIEnv *env, jobject thisj, jlong shape, jint dim, jint m) {
  AS_SHAPE(shape).update_dim(dim, m);
}

JNIEXPORT void JNICALL Java_primitiv_Shape_jniUpdateBatch(JNIEnv *env, jobject thisj, jlong shape, jint batch) {
  AS_SHAPE(shape).update_batch(batch);
}

}

}
