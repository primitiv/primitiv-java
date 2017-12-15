package primitiv;

public class Parameter {
  private long nativeHandle;

  public Parameter() {
    nativeHandle = allocate();
  }

  Parameter(long nativeHandle) {
    this.nativeHandle = nativeHandle;
  }

  public void save(String path, boolean with_stats) {
  }

  private native long allocate();

  private native void delete(long handle);

  private native void save(long handle, String path, boolean with_stats);

  static {
    NativeLibrary.load();
  }
}