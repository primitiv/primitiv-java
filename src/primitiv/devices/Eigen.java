/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.devices;

import primitiv.Device;

public class Eigen extends Device
{
  public Eigen() {
    handle_ = jniNew();
    Device.registerWrapper(handle_, this);
  }

  protected Eigen(long handle) {
    handle_ = handle;
  }

  private native long jniNew();

}
