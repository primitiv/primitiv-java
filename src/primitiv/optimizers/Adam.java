/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class Adam extends Optimizer
{
  public Adam(float alpha, float beta1, float beta2, float eps) {
    handle_ = jniNew(alpha, beta1, beta2, eps);
  }

  public Adam(float alpha, float beta1, float beta2) {
    handle_ = jniNew(alpha, beta1, beta2, 1e-8f);
  }

  public Adam(float alpha, float beta1) {
    handle_ = jniNew(alpha, beta1, 0.999f, 1e-8f);
  }

  public Adam(float alpha) {
    handle_ = jniNew(alpha, 0.9f, 0.999f, 1e-8f);
  }

  public Adam() {
    handle_ = jniNew(0.001f, 0.9f, 0.999f, 1e-8f);
  }

  public float alpha() {
    return jniAlpha(handle_);
  }

  public float beta1() {
    return jniBeta1(handle_);
  }

  public float beta2() {
    return jniBeta2(handle_);
  }

  public float eps() {
    return jniEps(handle_);
  }

  private native long jniNew(float alpha, float beta1, float beta2, float eps);
  private native float jniAlpha(long handle);
  private native float jniBeta1(long handle);
  private native float jniBeta2(long handle);
  private native float jniEps(long handle);

}
