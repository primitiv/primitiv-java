/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public class Parameter {
  private static HandleObjectHashMap<Parameter> handle_object_hashmap = new HandleObjectHashMap<Parameter>();

  protected static Parameter wrap_parameter(long handle) {
    if (handle_object_hashmap.containsKey(new Long(handle))) {
      return handle_object_hashmap.get(handle);
    }
    Parameter result = new Parameter(handle);
    handle_object_hashmap.put(new Long(handle), result);
    return result;
  }

  protected long handle_;
  private boolean del_required_;

  public Parameter() {
    handle_ = jniNew();
    del_required_ = true;
  }

  public Parameter(Shape shape, float[] value, Device device) {
    handle_ = jniNewWithValues(shape.handle_, value, device.handle_);
    del_required_ = true;
  }

  public Parameter(Shape shape, Initializer initializer, Device device) {
    handle_ = jniNewWithInitializer(shape.handle_, initializer.handle_, device.handle_);
    del_required_ = true;
  }

  protected Parameter(long handle) {
    handle_ = handle;
  }

  public void dispose() {
    if (del_required_) {
      jniDelete(handle_);
    }
  }

  @Override
  protected void finalize() throws Throwable {
    try {
      super.finalize();
    } finally {
      dispose();
    }
  }

  public void init(Shape shape, float[] value, Device device) {
    jniInitWithValues(handle_, shape.handle_, value, device.handle_);
  }

  public void init(Shape shape, Initializer initializer, Device device) {
    jniInitWithInitializer(handle_, shape.handle_, initializer.handle_, device.handle_);
  }

  public void load(String path, boolean with_stats, Device device) {
    jniLoad(handle_, path, with_stats, device.handle_);
  }

  public void save(String path, boolean with_stats) {
    jniSave(handle_, path, with_stats);
  }

  public boolean valid() {
    return jniValid(handle_);
  }

  public void reset_gradients() {
    jniResetGradients(handle_);
  }

  public void add_stats(String name, Shape shape) {
    jniAddStats(handle_, name, shape.handle_);
  }

  public boolean has_stats(String name) {
    return jniHasStats(handle_, name);
  }

  public Shape shape() {
    return new Shape(jniShape(handle_));
  }

  public Device device() {
    return Device.wrap_device(jniDevice(handle_));
  }

  public Tensor value() {
    return Tensor.wrap_tensor(jniValue(handle_));
  }

  public Tensor gradient() {
    return Tensor.wrap_tensor(jniGradient(handle_));
  }

  public Tensor stats(String name) {
    return Tensor.wrap_tensor(jniStats(handle_, name));
  }

  private native long jniNew();
  private native long jniNewWithValues(long shape, float[] value, long device);
  private native long jniNewWithInitializer(long shape, long initializer, long device);
  private native void jniDelete(long handle);
  private native void jniInitWithValues(long handle, long shape, float[] value, long device);
  private native void jniInitWithInitializer(long handle, long shape, long initializer, long device);
  private native void jniLoad(long handle, String path, boolean with_stats, long device);
  private native void jniSave(long handle, String path, boolean with_stats);
  private native boolean jniValid(long handle);
  private native void jniResetGradients(long handle);
  private native void jniAddStats(long handle, String name, long shape);
  private native boolean jniHasStats(long handle, String name);
  private native long jniShape(long handle);
  private native long jniDevice(long handle);
  private native long jniValue(long handle);
  private native long jniGradient(long handle);
  private native long jniStats(long handle, String name);

  static {
    NativeLibrary.load();
  }
}
