/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#ifndef PRIMITIV_INTERNAL_H_
#define PRIMITIV_INTERNAL_H_

#include <primitiv/primitiv.h>

namespace primitiv {

namespace jni {

inline jlong to_jlong(void *instance) {
  return reinterpret_cast<jlong>(instance);
}

inline Parameter *to_parameter_ptr(jlong pointer) {
  return reinterpret_cast<Parameter *>(pointer);
}

inline Parameter &to_parameter(jlong pointer) {
  return *reinterpret_cast<Parameter *>(pointer);
}

inline Shape *to_shape_ptr(jlong pointer) {
  return reinterpret_cast<Shape *>(pointer);
}

inline Shape &to_shape(jlong pointer) {
  return *reinterpret_cast<Shape *>(pointer);
}

inline Device *to_device_ptr(jlong pointer) {
  return reinterpret_cast<Device *>(pointer);
}

inline Device &to_device(jlong pointer) {
  return *reinterpret_cast<Device *>(pointer);
}

class JNIIntArrayAccess {
  JNIIntArrayAccess() = delete;

public:
  JNIIntArrayAccess(JNIEnv *env, jintArray array)
    : env_(env)
    , array_(array)
    , array_ptr_(env_->GetIntArrayElements(array_, 0))
    , size_(env_->GetArrayLength(array_)) {
  }

  ~JNIIntArrayAccess() {
    env_->ReleaseIntArrayElements(array_, array_ptr_, 0);
  }

  jint *data() { return array_ptr_; }
  jsize size() { return size_; }
  std::vector<jint> get_vector() {
    std::vector<jint> v(array_ptr_, array_ptr_ + size_);
    return v;
  }
  std::vector<uint32_t> get_vector_unsigned() {
    std::vector<uint32_t> v(reinterpret_cast<uint32_t*>(array_ptr_),
                            reinterpret_cast<uint32_t*>(array_ptr_) + size_);
    return v;
  }

private:
  JNIEnv *env_;
  jintArray array_;
  jint *array_ptr_;
  jsize size_;

};  // class JNIIntArrayAccess

class JNIFloatArrayAccess {
  JNIFloatArrayAccess() = delete;

public:
  JNIFloatArrayAccess(JNIEnv *env, jfloatArray array)
    : env_(env)
    , array_(array)
    , array_ptr_(env_->GetFloatArrayElements(array_, 0))
    , size_(env_->GetArrayLength(array_)) {
  }

  ~JNIFloatArrayAccess() {
    env_->ReleaseFloatArrayElements(array_, array_ptr_, 0);
  }

  jfloat *data() { return array_ptr_; }
  jsize size() { return size_; }
  std::vector<jfloat> get_vector() {
    std::vector<jfloat> v(array_ptr_, array_ptr_ + size_);
    return v;
  }

private:
  JNIEnv *env_;
  jfloatArray array_;
  jfloat *array_ptr_;
  jsize size_;

};  // class JNIFloatArrayAccess

class JNIStringAccess {
  JNIStringAccess() = delete;

public:
  JNIStringAccess(JNIEnv *env, jstring string)
    : env_(env)
    , string_(string)
    , char_ptr_(env_->GetStringUTFChars(string_, 0))
    , size_(env_->GetStringUTFLength(string_)) {
  }

  ~JNIStringAccess() {
    env_->ReleaseStringUTFChars(string_, char_ptr_);
  }

  const char *data() { return char_ptr_; }
  jsize size() { return size_; }
  std::string get_string() {
    std::string s(char_ptr_);
    return s;
  }

private:
  JNIEnv *env_;
  jstring string_;
  const char *char_ptr_;
  jsize size_;

};  // class JNIStringAccess

}  // namespace jni

}  // namespace primitiv

#endif  // JPRIMITIV_INTERNAL_H_
