/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class RMSProp extends Optimizer
{
  public RMSProp(float eta, float alpha, float eps) {
    handle_ = jniNew(eta, alpha, eps);
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
