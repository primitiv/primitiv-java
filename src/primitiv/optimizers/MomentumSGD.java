/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class MomentumSGD extends Optimizer
{
  public MomentumSGD(float eta, float momentum) {
    handle_ = jniNew(eta, momentum);
  }

  public float eta() {
    return jniEta(handle_);
  }

  public float momentum() {
    return jniMomentum(handle_);
  }

  private native long jniNew(float eta, float momentum);
  private native float jniEta(long handle);
  private native float jniMomentum(long handle);

}
