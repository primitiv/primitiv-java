/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class AdaDelta extends Optimizer
{
  public AdaDelta(float rho, float eps) {
    handle_ = jniNew(rho, eps);
  }

  public AdaDelta(float rho) {
    handle_ = jniNew(rho, 1e-6f);
  }

  public AdaDelta() {
    handle_ = jniNew(0.95f, 1e-6f);
  }

  public float rho() {
    return jniRho(handle_);
  }

  public float eps() {
    return jniEps(handle_);
  }

  private native long jniNew(float rho, float eps);
  private native float jniRho(long handle);
  private native float jniEps(long handle);

}
