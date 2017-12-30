/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_Model.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_Model_jniNew(JNIEnv *env, jobject thisj) {
  return to_jlong(new Model());
}

JNIEXPORT void JNICALL Java_primitiv_Model_jniDelete(JNIEnv *env, jobject thisj, jlong handle) {
  delete to_object_ptr<Model>(handle);
}

JNIEXPORT void JNICALL Java_primitiv_Model_jniLoad(JNIEnv *env, jobject thisj, jlong handle, jstring path, jboolean with_stats, jlong device) {
  JNIStringAccess path_access(env, path);
  to_object<Model>(handle).load(path_access.get_string(), with_stats, to_object_ptr<Device>(device));
}

JNIEXPORT void JNICALL Java_primitiv_Model_jniSave(JNIEnv *env, jobject thisj, jlong handle, jstring path, jboolean with_stats) {
  JNIStringAccess path_access(env, path);
  to_object<Model>(handle).save(path_access.get_string(), with_stats);
}

JNIEXPORT void JNICALL Java_primitiv_Model_jniAddParameter(JNIEnv *env, jobject thisj, jlong handle, jstring name, jlong param) {
  JNIStringAccess name_access(env, name);
  to_object<Model>(handle).add(name_access.get_string(), to_object<Parameter>(param));
}

JNIEXPORT void JNICALL Java_primitiv_Model_jniAddModel(JNIEnv *env, jobject thisj, jlong handle, jstring name, jlong model) {
  JNIStringAccess name_access(env, name);
  to_object<Model>(handle).add(name_access.get_string(), to_object<Model>(model));
}

JNIEXPORT jlong JNICALL Java_primitiv_Model_jniGetParameter(JNIEnv *env, jobject thisj, jlong handle, jobjectArray names) {
  return to_jlong(&to_object<Model>(handle).get_parameter(to_string_vector(env, names)));
}

JNIEXPORT jlong JNICALL Java_primitiv_Model_jniGetSubmodel(JNIEnv *env, jobject thisj, jlong handle, jobjectArray names) {
  return to_jlong(&to_object<Model>(handle).get_submodel(to_string_vector(env, names)));
}

JNIEXPORT jobject JNICALL Java_primitiv_Model_jniGetAllParameters(JNIEnv *env, jobject thisj, jlong handle) {
  jclass hashmap_class = env->FindClass("java/util/HashMap");
  jclass long_class = env->FindClass("java/lang/Long");
  if (hashmap_class == NULL || long_class == NULL)
  {
    return NULL;
  }
  std::map<std::vector<std::string>, Parameter*> param_map = to_object<Model>(handle).get_all_parameters();
  jmethodID hashmap_init = env->GetMethodID(hashmap_class, "<init>", "(I)V");
  jmethodID hashmap_put = env->GetMethodID(hashmap_class, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
  jmethodID long_init = env->GetMethodID(long_class, "<init>", "(J)V");
  jobject instance = env->NewObject(hashmap_class, hashmap_init, param_map.size());
  for (auto& kv : param_map) {
    jobject param_handle = env->NewObject(long_class, long_init, kv.second);
    env->CallObjectMethod(instance, hashmap_put, to_jstring_array(env, kv.first), param_handle);
  }
  return instance;
}

JNIEXPORT jobject JNICALL Java_primitiv_Model_jniGetTrainableParameters(JNIEnv *env, jobject thisj, jlong handle) {
  jclass hashmap_class = env->FindClass("java/util/HashMap");
  jclass long_class = env->FindClass("java/lang/Long");
  if (hashmap_class == NULL || long_class == NULL)
  {
    return NULL;
  }
  std::map<std::vector<std::string>, Parameter*> param_map = to_object<Model>(handle).get_trainable_parameters();
  jmethodID hashmap_init = env->GetMethodID(hashmap_class, "<init>", "(I)V");
  jmethodID hashmap_put = env->GetMethodID(hashmap_class, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
  jmethodID long_init = env->GetMethodID(long_class, "<init>", "(J)V");
  jobject instance = env->NewObject(hashmap_class, hashmap_init, param_map.size());
  for (auto& kv : param_map) {
    jobject param_handle = env->NewObject(long_class, long_init, kv.second);
    env->CallObjectMethod(instance, hashmap_put, to_jstring_array(env, kv.first), param_handle);
  }
  return instance;
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
