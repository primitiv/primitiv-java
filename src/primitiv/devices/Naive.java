/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.devices;

import primitiv.Device;

public class Naive extends Device
{
  public Naive() {
    handle_ = jniNew();
    Device.register_wrapper(handle_, this);
  }

  protected Naive(long handle) {
    handle_ = handle;
  }

  private native long jniNew();

}
