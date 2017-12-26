/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public abstract class Initializer {
  protected long handle_;

//   public Initializer() {}

  public void dispose() {
    if (handle_ != 0) {
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

  public void apply(Tensor tensor) {
    jniApply(handle_, tensor.handle_);
  }

  private native void jniDelete(long handle);
  private native void jniApply(long handle, long tensor);

  static {
    NativeLibrary.load();
  }
}
