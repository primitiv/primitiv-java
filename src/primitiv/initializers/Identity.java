/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class Identity extends Initializer
{
  public Identity() {
    handle_ = jniNew();
  }

  private native long jniNew();

}
