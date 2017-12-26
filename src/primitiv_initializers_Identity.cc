/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_initializers_Identity.h"

#include <memory>

#include <jni.h>
#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_initializers_Identity_jniNew(JNIEnv *env, jobject thisj) {
  return to_jlong(new initializers::Identity());
}

}  // extern "C"

}  // namespace jni

}  // namespace primitiv
