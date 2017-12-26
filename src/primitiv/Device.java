/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public class Device
{
  private static HandleObjectHashMap<Device> handle_object_hashmap = new HandleObjectHashMap<Device>();

  protected static Device wrap_device(long handle) {
    if (handle_object_hashmap.containsKey(new Long(handle))) {
      return handle_object_hashmap.get(handle);
    }
    Device result = new Device(handle);
    handle_object_hashmap.put(new Long(handle), result);
    return result;
  }

  protected static void register_wrapper(long handle, Device wrapper) {
    handle_object_hashmap.put(new Long(handle), wrapper);
  }

  public static void set_default(Device device) {
    jniSetDefault(device.handle_);
  }

  protected long handle_;

  protected Device() {}

  private Device(long handle) {
    handle_ = handle;
  }

  public void dispose() {
    jniDelete(handle_);
  }

  @Override
  protected void finalize() throws Throwable {
    try {
      super.finalize();
    } finally {
      dispose();
    }
  }

  private static native void jniSetDefault(long handle);
  private native void jniDelete(long handle);

  static {
    NativeLibrary.load();
  }
}
