/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.devices;

import primitiv.Device;

public class CUDA extends Device
{
  public CUDA(int device_id) {
    handle_ = jniNew(device_id);
    Device.register_wrapper(handle_, this);
  }

  protected CUDA(long handle) {
    handle_ = handle;
  }

  private native long jniNew(int device_id);

}
