/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class XavierUniform extends Initializer
{
  public XavierUniform(float scale) {
    handle_ = jniNew(scale);
  }

  public XavierUniform() {
    handle_ = jniNew(1.0f);
  }

  private native long jniNew(float scale);

}
