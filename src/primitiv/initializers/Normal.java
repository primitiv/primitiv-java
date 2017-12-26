/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class Normal extends Initializer
{
  public Normal(float mean, float sd) {
    handle_ = jniNew(mean, sd);
  }

  private native long jniNew(float mean, float sd);

}
