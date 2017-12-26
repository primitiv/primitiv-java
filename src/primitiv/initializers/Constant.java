/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class Constant extends Initializer
{
  public Constant(float k) {
    handle_ = jniNew(k);
  }

  private native long jniNew(float k);

}
