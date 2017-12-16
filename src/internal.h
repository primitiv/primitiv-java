/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#ifndef PRIMITIV_INTERNAL_H_
#define PRIMITIV_INTERNAL_H_

namespace primitiv {

namespace jni {

inline jlong to_j(void *instance) {
  return reinterpret_cast<jlong>(instance);
}

class JNIIntArrayAccess {
  JNIIntArrayAccess() = delete;

public:
  JNIIntArrayAccess(JNIEnv *env, jintArray array)
    : env_(env)
    , array_(array)
    , array_ptr_(env->GetIntArrayElements(array_, 0))
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

}  // namespace jni

}  // namespace primitiv

#endif  // JPRIMITIV_INTERNAL_H_
