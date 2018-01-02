/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_devices_CUDA.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_devices_CUDA_jniNew(JNIEnv *env, jobject thisj, jint device_id) {
  return to_jlong(new devices::CUDA(device_id));
}

JNIEXPORT jint JNICALL Java_primitiv_devices_CUDA_jniNumDevices(JNIEnv *env, jclass cls) {
    return devices::CUDA::num_devices();
}

JNIEXPORT jboolean JNICALL Java_primitiv_devices_CUDA_jniCheckSupport(JNIEnv *env, jclass cls, jint device_id) {
    return devices::CUDA::check_support(device_id);
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
