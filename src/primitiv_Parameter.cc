/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Parameter.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniNew(JNIEnv *env, jobject thisj) {
  return to_jlong(new Parameter());
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniNewWithValues(JNIEnv *env, jobject thisj, jlong shape, jfloatArray value, jlong device) {
  JNIFloatArrayAccess value_access(env, value);
  std::vector<float> value_vec = value_access.get_vector();
  return to_jlong(new Parameter(to_object<Shape>(shape), value_vec, to_object_ptr<Device>(device)));
}

// JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniNewWithInitializer(JNIEnv *env, jobject thisj, jlong shape, jlong initializer, jlong device) {
//
// }

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_object_ptr<Parameter>(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniInitWithValues(JNIEnv *env, jobject thisj, jlong handle, jlong shape, jfloatArray value, jlong device) {
  JNIFloatArrayAccess value_access(env, value);
  std::vector<float> value_vec = value_access.get_vector();
  to_object<Parameter>(handle).init(to_object<Shape>(shape), value_vec, to_object_ptr<Device>(device));
}

// JNIEXPORT void JNICALL Java_primitiv_Parameter_jniInitWithInitializer(JNIEnv *env, jobject thisj, jlong handle, jlong shape, jlong initializer, jlong device);

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniLoad(JNIEnv *env, jobject thisj, jlong handle, jstring path, jboolean with_stats, jlong device) {
  JNIStringAccess path_access(env, path);
  to_object<Parameter>(handle).load(path_access.get_string(), with_stats, to_object_ptr<Device>(device));
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniSave(JNIEnv *env, jobject thisj, jlong handle, jstring path, jboolean with_stats) {
  const char* cpath = env->GetStringUTFChars(path, nullptr);
  to_object<Parameter>(handle).save(cpath, with_stats);
}

JNIEXPORT jboolean JNICALL Java_primitiv_Parameter_jniValid(JNIEnv *env, jobject thisj, jlong handle) {
  return to_object<Parameter>(handle).valid();
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniResetGradients(JNIEnv *env, jobject thisj, jlong handle) {
  to_object<Parameter>(handle).reset_gradient();
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_jniAddStats(JNIEnv *env, jobject thisj, jlong handle, jstring name, jlong shape) {
  JNIStringAccess name_access(env, name);
  to_object<Parameter>(handle).add_stats(name_access.get_string(), to_object<Shape>(shape));
}

JNIEXPORT jboolean JNICALL Java_primitiv_Parameter_jniHasStats(JNIEnv *env, jobject thisj, jlong handle, jstring name) {
  JNIStringAccess name_access(env, name);
  return to_object<Parameter>(handle).has_stats(name_access.get_string());
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniShape(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(new Shape(to_object<Parameter>(handle).shape()));
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniDevice(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(&to_object<Parameter>(handle).device());
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniValue(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(&to_object<Parameter>(handle).value());
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniGradient(JNIEnv *env, jobject thisj, jlong handle) {
  return to_jlong(&to_object<Parameter>(handle).gradient());
}

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_jniStats(JNIEnv *env, jobject thisj, jlong handle, jstring name) {
  JNIStringAccess name_access(env, name);
  return to_jlong(&to_object<Parameter>(handle).stats(name_access.get_string()));
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
