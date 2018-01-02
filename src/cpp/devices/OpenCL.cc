/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_devices_OpenCL.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_devices_OpenCL_jniNew(JNIEnv *env, jobject thisj, jint platform_id, jint device_id) {
  return to_jlong(new devices::OpenCL(platform_id, device_id));
}

JNIEXPORT jint JNICALL Java_primitiv_devices_OpenCL_jniNumPlatforms(JNIEnv *env, jclass cls) {
    return devices::OpenCL::num_platforms();
}

JNIEXPORT jint JNICALL Java_primitiv_devices_OpenCL_jniNumDevices(JNIEnv *env, jclass cls, jint platform_id) {
    return devices::OpenCL::num_devices(platform_id);
}

JNIEXPORT jboolean JNICALL Java_primitiv_devices_OpenCL_jniCheckSupport(JNIEnv *env, jclass cls, jint platform_id, jint device_id) {
    return devices::OpenCL::check_support(platform_id, device_id);
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
