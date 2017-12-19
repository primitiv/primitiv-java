/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Device.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT void JNICALL Java_primitiv_Device_jniSetDefault(JNIEnv *env, jclass cls, jlong handle) {
  Device::set_default(to_device(handle));
}

JNIEXPORT void JNICALL Java_primitiv_Device_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_device_ptr(handle);
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
