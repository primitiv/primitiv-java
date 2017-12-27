/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#include "primitiv_functions.h"

#include <primitiv/primitiv.h>

#include "internal.h"

namespace primitiv {

namespace jni {

extern "C" {

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPositive(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::positive(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniNegative(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::negative(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniAddNodeConst(JNIEnv *env, jclass cls, jlong x, jfloat k) {
  return to_jlong(new Node(functions::add(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniAddConstNode(JNIEnv *env, jclass cls, jfloat k, jlong x) {
  return to_jlong(new Node(functions::add(k, to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniAddNodeNode(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::add(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSubtractNodeConst(JNIEnv *env, jclass cls, jlong x, jfloat k) {
  return to_jlong(new Node(functions::subtract(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSubtractConstNode(JNIEnv *env, jclass cls, jfloat k, jlong x) {
  return to_jlong(new Node(functions::subtract(k, to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSubtractNodeNode(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::subtract(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMultiplyNodeConst(JNIEnv *env, jclass cls, jlong x, jfloat k) {
  return to_jlong(new Node(functions::multiply(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMultiplyConstNode(JNIEnv *env, jclass cls, jfloat k, jlong x) {
  return to_jlong(new Node(functions::multiply(k, to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMultiplyNodeNode(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::multiply(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniDivideNodeConst(JNIEnv *env, jclass cls, jlong x, jfloat k) {
  return to_jlong(new Node(functions::divide(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniDivideConstNode(JNIEnv *env, jclass cls, jfloat k, jlong x) {
  return to_jlong(new Node(functions::divide(k, to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniDivideNodeNode(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::divide(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPowNodeConst(JNIEnv *env, jclass cls, jlong x, jfloat k) {
  return to_jlong(new Node(functions::pow(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPowConstNode(JNIEnv *env, jclass cls, jfloat k, jlong x) {
  return to_jlong(new Node(functions::pow(k, to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPowNodeNode(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::pow(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniInput(JNIEnv *env, jclass cls, jlong shape, jfloatArray data, jlong dev, jlong g) {
  JNIFloatArrayAccess data_access(env, data);
  std::vector<float> data_vec = data_access.get_vector();
  return to_jlong(new Node(functions::input_node(to_object<Shape>(shape), data_vec, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniParameter(JNIEnv *env, jclass cls, jlong param, jlong g) {
  return to_jlong(new Node(functions::parameter_node(to_object<Parameter>(param), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniCopy(JNIEnv *env, jclass cls, jlong x, jlong dev) {
  return to_jlong(new Node(functions::copy(to_object<Node>(x), to_object_ptr<Device>(dev))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPick(JNIEnv *env, jclass cls, jlong x, jintArray ids, jint dim) {
  JNIIntArrayAccess data_access(env, ids);
  std::vector<uint32_t> data_vec = data_access.get_vector_unsigned();
  return to_jlong(new Node(functions::pick(to_object<Node>(x), data_vec, dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSlice(JNIEnv *env, jclass cls, jlong x, jint dim, jint lower, jint upper) {
  return to_jlong(new Node(functions::slice(to_object<Node>(x), dim, lower, upper)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniConcat(JNIEnv *env, jclass cls, jlongArray x_ptrs, jint dim) {
  JNILongArrayAccess x_ptrs_access(env, x_ptrs);
  std::vector<jlong> x_ptrs_vec = x_ptrs_access.get_vector();
  std::vector<Node> x_vec(x_ptrs_vec.size());
  for (size_t i = 0; i < x_ptrs_vec.size(); ++i) {
    x_vec[i] = to_object<Node>(x_ptrs_vec[i]);
  }
  return to_jlong(new Node(functions::concat(x_vec, dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniReshape(JNIEnv *env, jclass cls, jlong x, jlong new_shape) {
  return to_jlong(new Node(functions::reshape(to_object<Node>(x), to_object<Shape>(new_shape))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniFlatten(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::flatten(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniTranspose(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::transpose(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMatmul(JNIEnv *env, jclass cls, jlong a, jlong b) {
  return to_jlong(new Node(functions::matmul(to_object<Node>(a), to_object<Node>(b))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSqrt(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::sqrt(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniExp(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::exp(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniLog(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::log(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniTanh(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::tanh(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSigmoid(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::sigmoid(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSoftplus(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::softplus(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSin(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::sin(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniCos(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::cos(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniTan(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::tan(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRelu(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::relu(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniLrelu(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::lrelu(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPrelu(JNIEnv *env, jclass cls, jlong x, jfloat a) {
  return to_jlong(new Node(functions::prelu(to_object<Node>(x), a)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniElu(JNIEnv *env, jclass cls, jlong x, jfloat a) {
  return to_jlong(new Node(functions::elu(to_object<Node>(x), a)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSum(JNIEnv *env, jclass cls, jlong x, jint dim) {
  return to_jlong(new Node(functions::sum(to_object<Node>(x), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniBroadcast(JNIEnv *env, jclass cls, jlong x, jint dim, jint size) {
  return to_jlong(new Node(functions::broadcast(to_object<Node>(x), dim, size)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniLogsumexp(JNIEnv *env, jclass cls, jlong x, jint dim) {
  return to_jlong(new Node(functions::logsumexp(to_object<Node>(x), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniLogSoftmax(JNIEnv *env, jclass cls, jlong x, jint dim) {
  return to_jlong(new Node(functions::log_softmax(to_object<Node>(x), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSoftmax(JNIEnv *env, jclass cls, jlong x, jint dim) {
  return to_jlong(new Node(functions::softmax(to_object<Node>(x), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSoftmaxCrossEntropy(JNIEnv *env, jclass cls, jlong x, jlong t, jint dim) {
  return to_jlong(new Node(functions::softmax_cross_entropy(to_object<Node>(x), to_object<Node>(t), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSoftmaxCrossEntropyWithArray(JNIEnv *env, jclass cls, jlong x, jintArray ids, jint dim) {
  JNIIntArrayAccess ids_access(env, ids);
  std::vector<uint32_t> ids_vec = ids_access.get_vector_unsigned();
  return to_jlong(new Node(functions::softmax_cross_entropy(to_object<Node>(x), ids_vec, dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniStopGradient(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::stop_gradient(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniBatchSum(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::batch::sum(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniBatchMean(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::batch::mean(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniBatchNormalize(JNIEnv *env, jclass cls, jlong x) {
  return to_jlong(new Node(functions::batch::normalize(to_object<Node>(x))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniConstant(JNIEnv *env, jclass cls, jlong shape, jfloat k, jlong dev, jlong g) {
  return to_jlong(new Node(functions::constant_node(to_object<Shape>(shape), k, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniIdentity(JNIEnv *env, jclass cls, jint size, jlong dev, jlong g) {
  return to_jlong(new Node(functions::identity_node(size, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRandomBernoulli(JNIEnv *env, jclass cls, jlong shape, jfloat p, jlong dev, jlong g) {
  return to_jlong(new Node(functions::random::bernoulli_node(to_object<Shape>(shape), p, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRandomUniform(JNIEnv *env, jclass cls, jlong shape, jfloat lower, jfloat upper, jlong dev, jlong g) {
  return to_jlong(new Node(functions::random::uniform_node(to_object<Shape>(shape), lower, upper, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRandomNormal(JNIEnv *env, jclass cls, jlong shape, jfloat mean, jfloat sd, jlong dev, jlong g) {
  return to_jlong(new Node(functions::random::normal_node(to_object<Shape>(shape), mean, sd, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRandomLogNormal(JNIEnv *env, jclass cls, jlong shape, jfloat mean, jfloat sd, jlong dev, jlong g) {
  return to_jlong(new Node(functions::random::log_normal_node(to_object<Shape>(shape), mean, sd, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniRandomGumbel(JNIEnv *env, jclass cls, jlong shape, jfloat mu, jfloat beta, jlong dev, jlong g) {
  return to_jlong(new Node(functions::random::gumbel_node(to_object<Shape>(shape), mu, beta, to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));

}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniPown(JNIEnv *env, jclass cls, jlong x, jint k) {
  return to_jlong(new Node(functions::pown(to_object<Node>(x), k)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSelu(JNIEnv *env, jclass cls, jlong x, jfloat a, jfloat s) {
  return to_jlong(new Node(functions::selu(to_object<Node>(x), a, s)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniSumNodes(JNIEnv *env, jclass cls, jlongArray x_ptrs) {
  JNILongArrayAccess x_ptrs_access(env, x_ptrs);
  std::vector<jlong> x_ptrs_vec = x_ptrs_access.get_vector();
  std::vector<Node> x_vec(x_ptrs_vec.size());
  for (size_t i = 0; i < x_ptrs_vec.size(); ++i) {
    x_vec[i] = to_object<Node>(x_ptrs_vec[i]);
  }
  return to_jlong(new Node(functions::sum(x_vec)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMean(JNIEnv *env, jclass cls, jlong x, jint dim) {
  return to_jlong(new Node(functions::mean(to_object<Node>(x), dim)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniMeanNodes(JNIEnv *env, jclass cls, jlongArray x_ptrs) {
  JNILongArrayAccess x_ptrs_access(env, x_ptrs);
  std::vector<jlong> x_ptrs_vec = x_ptrs_access.get_vector();
  std::vector<Node> x_vec(x_ptrs_vec.size());
  for (size_t i = 0; i < x_ptrs_vec.size(); ++i) {
    x_vec[i] = to_object<Node>(x_ptrs_vec[i]);
  }
  return to_jlong(new Node(functions::mean(x_vec)));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniZeros(JNIEnv *env, jclass cls, jlong shape, jlong dev, jlong g) {
  return to_jlong(new Node(functions::zeros_node(to_object<Shape>(shape), to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniOnes(JNIEnv *env, jclass cls, jlong shape, jlong dev, jlong g) {
  return to_jlong(new Node(functions::ones_node(to_object<Shape>(shape), to_object_ptr<Device>(dev), to_object_ptr<Graph>(g))));
}

JNIEXPORT jlong JNICALL Java_primitiv_functions_jniDropout(JNIEnv *env, jclass cls, jlong x, jfloat rate, jboolean enabled) {
  return to_jlong(new Node(functions::dropout(to_object<Node>(x), rate, enabled)));
}

}  // end extern "C"

}  // namespace jni

}  // namespace primitiv
