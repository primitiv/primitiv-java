/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Initializer.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT void JNICALL Java_primitiv_Initializer_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_object_ptr<Initializer>(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Initializer_jniApply(JNIEnv *env, jobject thisj, jlong handle, jlong tensor) {
  to_object<Initializer>(handle).apply(to_object<Tensor>(tensor));
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
