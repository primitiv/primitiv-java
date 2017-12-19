/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Device.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_devices_Naive_jniNew(JNIEnv *env, jobject thisj) {
  return to_jlong(new devices::Naive());
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
