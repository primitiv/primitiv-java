/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public class Graph
{
  private static HandleObjectHashMap<Graph> handle_object_hashmap = new HandleObjectHashMap<Graph>();

  protected static Graph wrapGraph(long handle) {
    if (handle_object_hashmap.containsKey(new Long(handle))) {
      return handle_object_hashmap.get(handle);
    }
    Graph result = new Graph(handle);
    handle_object_hashmap.put(new Long(handle), result);
    return result;
  }

  protected static void registerWrapper(long handle, Graph wrapper) {
    handle_object_hashmap.put(new Long(handle), wrapper);
  }

  public static void setDefault(Graph graph) {
    jniSetDefault(graph.handle_);
  }

  protected long handle_;

  public Graph() {
    handle_ = jniNew();
  }

  protected Graph(long handle) {
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

  public void clear() {
    jniClear(handle_);
  }

  public Tensor forward(Node node) {
    return new Tensor(jniForward(handle_, node.handle_));
  }

  public void backward(Node node) {
    jniBackward(handle_, node.handle_);
  }

  public Shape getShape(Node node) {
    return new Shape(jniGetShape(handle_, node.handle_));
  }

  public Device getDevice(Node node) {
    return Device.wrap_device(jniGetDevice(handle_, node.handle_));
  }

  public String dump(String format) {
    return jniDump(handle_, format);
  }

  public int numOperators() {
    return jniNumOperators(handle_);
  }

  private static native void jniSetDefault(long handle);
  private native long jniNew();
  private native void jniDelete(long handle);
  private native void jniClear(long handle);
  private native long jniForward(long handle, long node);
  private native void jniBackward(long handle, long node);
  private native long jniGetShape(long handle, long node);
  private native long jniGetDevice(long handle, long node);
  private native String jniDump(long handle, String format);
  private native int jniNumOperators(long handle);

  static {
    NativeLibrary.load();
  }
}
