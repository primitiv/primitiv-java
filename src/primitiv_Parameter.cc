/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Parameter.h"

#include <primitiv/parameter.h>

#include "internal.h"

namespace primitiv {

namespace jni {

#define CAST_TO_PARAMETER(x) reinterpret_cast<Parameter*>(x)
#define CAST_TO_CONST_PARAMETER(x) reinterpret_cast<const Parameter*>(x)

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Parameter_allocate(JNIEnv * env, jobject thisj) {
  return to_j(new Parameter());
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_delete(JNIEnv * env, jobject thisj, jlong handle) {
  delete CAST_TO_PARAMETER(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Parameter_save(JNIEnv * env, jobject thisj, jlong handle, jstring path, jboolean with_stats) {
  const char* cpath = env->GetStringUTFChars(path, nullptr);
  CAST_TO_PARAMETER(handle)->save(cpath, with_stats);
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
