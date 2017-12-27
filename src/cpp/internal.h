/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#ifndef PRIMITIV_INTERNAL_H_
#define PRIMITIV_INTERNAL_H_

#include <primitiv/primitiv.h>

namespace primitiv {

namespace jni {

inline jlong to_jlong(void *instance) {
  return reinterpret_cast<jlong>(instance);
}

template<class T>
inline T *to_object_ptr(jlong pointer) {
  return reinterpret_cast<T *>(pointer);
}

template<class T>
inline T &to_object(jlong pointer) {
  return *reinterpret_cast<T *>(pointer);
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
    std::vector<jint> v_old = get_vector();
    std::vector<uint32_t> v(v_old.begin(), v_old.end());
    return v;
  }

private:
  JNIEnv *env_;
  jintArray array_;
  jint *array_ptr_;
  jsize size_;

};  // class JNIIntArrayAccess

class JNILongArrayAccess {
  JNILongArrayAccess() = delete;

public:
  JNILongArrayAccess(JNIEnv *env, jlongArray array)
    : env_(env)
    , array_(array)
    , array_ptr_(env_->GetLongArrayElements(array_, 0))
    , size_(env_->GetArrayLength(array_)) {
  }

  ~JNILongArrayAccess() {
    env_->ReleaseLongArrayElements(array_, array_ptr_, 0);
  }

  jlong *data() { return array_ptr_; }
  jsize size() { return size_; }
  std::vector<jlong> get_vector() {
    std::vector<jlong> v(array_ptr_, array_ptr_ + size_);
    return v;
  }
  std::vector<uint64_t> get_vector_unsigned() {
    std::vector<jlong> v_old = get_vector();
    std::vector<uint64_t> v(v_old.begin(), v_old.end());
    return v;
  }

private:
  JNIEnv *env_;
  jlongArray array_;
  jlong *array_ptr_;
  jsize size_;

};  // class JNILongArrayAccess

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
