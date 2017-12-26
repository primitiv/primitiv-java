/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public class Tensor
{
  private static HandleObjectHashMap<Tensor> handle_object_hashmap = new HandleObjectHashMap<Tensor>();

  protected static Tensor wrap_tensor(long handle) {
    if (handle_object_hashmap.containsKey(new Long(handle))) {
      return handle_object_hashmap.get(handle);
    }
    Tensor result = new Tensor(handle);
    handle_object_hashmap.put(new Long(handle), result);
    return result;
  }

  protected static void register_wrapper(long handle, Tensor wrapper) {
    handle_object_hashmap.put(new Long(handle), wrapper);
  }

  protected long handle_;
  protected boolean del_required_;

  protected Tensor(long handle) {
    handle_ = handle;
  }

  protected Tensor(long handle, boolean del_required) {
    handle_ = handle;
    del_required_ = del_required;
  }

  public Tensor() {
    handle_ = jniNew();
    del_required_ = true;
  }

  public Tensor(Tensor tensor) {
    handle_ = jniNewFromTensor(tensor.handle_);
    del_required_ = true;
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

  public boolean valid() {
    return jniValid(handle_);
  }

  public Shape shape() {
    return new Shape(jniShape(handle_));
  }

  public Device device() {
    return Device.wrap_device(jniDevice(handle_));
  }

  public float to_float() {
    return jniToFloat(handle_);
  }

  public float[] to_array() {
    return jniToArray(handle_);
  }

  public int[] argmax(int dim) {
    return jniArgmax(handle_, dim);
  }

  public int[] argmin(int dim) {
    return jniArgmin(handle_, dim);
  }

  public void reset(float k) {
    jniReset(handle_, k);
  }

  public void reset_by_array(float[] values) {
    jniResetByArray(handle_, values);
  }

  public Tensor reshape(Shape new_shape) {
    return new Tensor(jniReshape(handle_, new_shape.handle_), true);
  }

  public Tensor flatten() {
    return new Tensor(jniFlatten(handle_), true);
  }

  public void inplace_multiply_const(float k) {
    jniInplaceMultiplyConst(handle_, k);
  }

  public void inplace_add(Tensor x) {
    jniInplaceAdd(handle_, x.handle_);
  }

  public void inplace_subtract(Tensor x) {
    jniInplaceSubtract(handle_, x.handle_);
  }

  private native long jniNew();
  private native long jniNewFromTensor(long handle);
  private native void jniDelete(long handle);
  private native boolean jniValid(long handle);
  private native long jniShape(long handle);
  private native long jniDevice(long handle);
  private native float jniToFloat(long handle);
  private native float[] jniToArray(long handle);
  private native int[] jniArgmax(long handle, int dim);
  private native int[] jniArgmin(long handle, int dim);
  private native void jniReset(long handle, float k);
  private native void jniResetByArray(long handle, float[] values);
  private native long jniReshape(long handle, long new_shape);
  private native long jniFlatten(long handle);
  private native void jniInplaceMultiplyConst(long handle, float k);
  private native void jniInplaceAdd(long handle, long x);
  private native void jniInplaceSubtract(long handle, long x);

  static {
    NativeLibrary.load();
  }
}
