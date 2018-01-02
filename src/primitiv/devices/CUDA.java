/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv.devices;

import primitiv.Device;

public class CUDA extends Device
{
  public CUDA(int device_id) {
    handle_ = jniNew(device_id);
    Device.registerWrapper(handle_, this);
  }

  protected CUDA(long handle) {
    handle_ = handle;
  }

  public static int numDevices() {
    return jniNumDevices();
  }

  public static boolean checkSupport(int device_id) {
    return jniCheckSupport(device_id);
  }

  private native long jniNew(int device_id);
  private static native int jniNumDevices();
  private static native boolean jniCheckSupport(int device_id);

}
