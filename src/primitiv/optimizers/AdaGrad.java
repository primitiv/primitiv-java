/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class AdaGrad extends Optimizer
{
  public AdaGrad(float eta, float eps) {
    handle_ = jniNew(eta, eps);
  }

  public AdaGrad(float eta) {
    handle_ = jniNew(eta, 1e-8f);
  }

  public AdaGrad() {
    handle_ = jniNew(0.001f, 1e-8f);
  }

  public float eta() {
    return jniEta(handle_);
  }

  public float eps() {
    return jniEps(handle_);
  }

  private native long jniNew(float eta, float eps);
  private native float jniEta(long handle);
  private native float jniEps(long handle);

}
