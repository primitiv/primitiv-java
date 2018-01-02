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

  public static int numPlatforms() {
    return jniNumPlatforms();
  }

  public static int numDevices(int platform_id) {
    return jniNumDevices(platform_id);
  }

  public static boolean checkSupport(int platform_id, int device_id) {
    return jniCheckSupport(platform_id, device_id);
  }

  private native long jniNew(int platform_id, int device_id);
  private static native int jniNumPlatforms();
  private static native int jniNumDevices(int platform_id);
  private static native boolean jniCheckSupport(int platform_id, int device_id);

}
