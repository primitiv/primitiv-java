/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


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
    return Graph.wrapGraph(jniGraph(handle_));
  }

  public int operatorId() {
    return jniOperatorId(handle_);
  }

  public int valueId() {
    return jniValueId(handle_);
  }

  public Shape shape() {
    return new Shape(jniShape(handle_));
  }

  public Device device() {
    return Device.wrapDevice(jniDevice(handle_));
  }

  public float toFloat() {
    return jniToFloat(handle_);
  }

  public float[] toArray() {
    return jniToArray(handle_);
  }

  public List<Double> toList() {
    float[] val = jniToArray(handle_);
    return IntStream.range(0, val.length).mapToDouble(i -> val[i]).boxed().collect(Collectors.toList());
  }

  public List<Integer> argmax(int dim) {
    return Arrays.stream(jniArgmax(handle_, dim)).boxed().collect(Collectors.toList());
  }

  public List<Integer> argmin(int dim) {
    return Arrays.stream(jniArgmin(handle_, dim)).boxed().collect(Collectors.toList());
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
