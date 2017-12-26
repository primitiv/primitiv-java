/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public class Node
{
  protected long handle_;

  protected Node(long handle) {
    handle_ = handle;
  }

  public Node() {
    handle_ = jniNew();
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

  public boolean valid() {
    return jniValid(handle_);
  }

  public Graph graph() {
    return Graph.wrap_graph(jniGraph(handle_));
  }

  public int operator_id() {
    return jniOperatorId(handle_);
  }

  public int value_id() {
    return jniValueId(handle_);
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

  public void backward() {
    jniBackward(handle_);
  }

  private native long jniNew();
  private native void jniDelete(long handle);
  private native boolean jniValid(long handle);
  private native long jniGraph(long handle);
  private native int jniOperatorId(long handle);
  private native int jniValueId(long handle);
  private native long jniShape(long handle);
  private native long jniDevice(long handle);
  private native float jniToFloat(long handle);
  private native float[] jniToArray(long handle);
  private native int[] jniArgmax(long handle, int dim);
  private native int[] jniArgmin(long handle, int dim);
  private native void jniBackward(long handle);

  static {
    NativeLibrary.load();
  }
}
