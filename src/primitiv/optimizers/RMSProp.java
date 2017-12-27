/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class RMSProp extends Optimizer
{
  public RMSProp(float eta, float alpha, float eps) {
    handle_ = jniNew(eta, alpha, eps);
  }

  public RMSProp(float eta, float alpha) {
    handle_ = jniNew(eta, alpha, 1e-8f);
  }

  public RMSProp(float eta) {
    handle_ = jniNew(eta, 0.9f, 1e-8f);
  }

  public RMSProp() {
    handle_ = jniNew(0.01f, 0.9f, 1e-8f);
  }

  public float eta() {
    return jniEta(handle_);
  }

  public float alpha() {
    return jniAlpha(handle_);
  }

  public float eps() {
    return jniEps(handle_);
  }

  private native long jniNew(float eta, float alpha, float eps);
  private native float jniEta(long handle);
  private native float jniAlpha(long handle);
  private native float jniEps(long handle);

}
