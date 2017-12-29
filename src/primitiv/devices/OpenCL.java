/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.devices;

import primitiv.Device;

public class OpenCL extends Device
{
  public OpenCL(int platform_id, int device_id) {
    handle_ = jniNew(platform_id, device_id);
    Device.registerWrapper(handle_, this);
  }

  protected OpenCL(long handle) {
    handle_ = handle;
  }

  private native long jniNew(int platform_id, int device_id);

}
