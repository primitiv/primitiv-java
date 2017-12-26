/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class XavierNormal extends Initializer
{
  public XavierNormal(float scale) {
    handle_ = jniNew(scale);
  }

  private native long jniNew(float scale);

}
