/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Device.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT void JNICALL Java_primitiv_Graph_jniSetDefault(JNIEnv *env, jclass cls, jlong handle) {
  Graph::set_default(to_object<Graph>(handle));
}

JNIEXPORT jlong JNICALL Java_primitiv_Graph_jniNew(JNIEnv *env, jclass cls) {
  return to_jlong(new Graph());
}

JNIEXPORT void JNICALL Java_primitiv_Graph_jniDelete(JNIEnv *env, jclass cls, jlong handle) {
  delete to_object_ptr<Graph>(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Graph_jniClear(JNIEnv *env, jclass cls, jlong handle) {
  to_object<Graph>(handle).clear();
}

JNIEXPORT jlong JNICALL Java_primitiv_Graph_jniForward(JNIEnv *env, jclass cls, jlong handle, jlong node) {
  return to_jlong(new Tensor(to_object<Graph>(handle).forward(to_object<Node>(node))));
}

JNIEXPORT void JNICALL Java_primitiv_Graph_jniBackward(JNIEnv *env, jclass cls, jlong handle, jlong node) {
  to_object<Graph>(handle).backward(to_object<Node>(node));
}

JNIEXPORT jlong JNICALL Java_primitiv_Graph_jniGetShape(JNIEnv *env, jclass cls, jlong handle, jlong node) {
  return to_jlong(new Shape(to_object<Graph>(handle).get_shape(to_object<Node>(node))));
}

JNIEXPORT jlong JNICALL Java_primitiv_Graph_jniGetDevice(JNIEnv *env, jclass cls, jlong handle, jlong node) {
  return to_jlong(&to_object<Graph>(handle).get_device(to_object<Node>(node)));
}

JNIEXPORT jstring JNICALL Java_primitiv_Graph_jniDump(JNIEnv *env, jclass cls, jlong handle, jstring format) {
  jstring result;
  JNIStringAccess format_access(env, format);
  result = env->NewStringUTF(to_object<Graph>(handle).dump(format_access.get_string()).c_str());
  return result;
}

JNIEXPORT jint JNICALL Java_primitiv_Graph_jniNumOperators(JNIEnv *env, jclass cls, jlong handle) {
  return to_object<Graph>(handle).num_operators();
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
