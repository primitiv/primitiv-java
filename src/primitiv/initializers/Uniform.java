/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.initializers;

import primitiv.Initializer;


public class Uniform extends Initializer
{
  public Uniform(float lower, float upper) {
    handle_ = jniNew(lower, upper);
  }

  private native long jniNew(float lower, float upper);

}
