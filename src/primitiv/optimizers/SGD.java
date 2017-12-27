/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.optimizers;

import primitiv.Optimizer;


public class SGD extends Optimizer
{
  public SGD(float eta) {
    handle_ = jniNew(eta);
  }

  public float eta() {
    return jniEta(handle_);
  }

  private native long jniNew(float eta);
  private native float jniEta(long handle);

}
