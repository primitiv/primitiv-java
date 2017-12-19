/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

import primitiv.HandleObjectHashMap;
import java.lang.Thread;


public class Shape
{
  protected long handle_ = 0;

  public Shape() {
    handle_ = jniNew();
  }

  public Shape(int[] dims, int batch) {
    handle_ = jniNewWithDims(dims, batch);
  }

  protected Shape(long ptr) {
    handle_ = ptr;
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

  public int getItem(int i) {
    return jniGetitem(handle_, i);
  }

  public int[] dims() {
    return jniDims(handle_);
  }

  public int depth() {
    return jniDepth(handle_);
  }

  public int batch() {
    return jniBatch(handle_);
  }

  public int volume() {
    return jniVolume(handle_);
  }

  public int lower_volume(int dim) {
    return jniLowerVolume(handle_, dim);
  }

  public int size() {
    return jniSize(handle_);
  }

  public String to_string() {
    return jniToString(handle_);
  }

  public boolean equals(Shape rhs) {
    return jniEqual(handle_, rhs.handle_);
  }

  public boolean has_batch() {
    return jniHasBatch(handle_);
  }

  public boolean has_compatible_batch(Shape rhs) {
    return jniHasCompatibleBatch(handle_, rhs.handle_);
  }

  public boolean is_scalar() {
    return jniIsScalar(handle_);
  }

  public boolean is_row_vector() {
    return jniIsRowVector(handle_);
  }

  public boolean is_matrix() {
    return jniIsMatrix(handle_);
  }

  public boolean has_same_dims(Shape rhs) {
    return jniHasSameDims(handle_, rhs.handle_);
  }

  public boolean has_same_loo_dims(Shape rhs, int dim) {
    return jniHasSameLooDims(handle_, rhs.handle_, dim);
  }

  public Shape resize_dim(int dim, int m) {
    return new Shape(jniResizeDim(handle_, dim, m));
  }

  public Shape resize_batch(int batch) {
    return new Shape(jniResizeBatch(handle_, batch));
  }

  public void update_dim(int dim, int m) {
    jniUpdateDim(handle_, dim, m);
  }

  public void update_batch(int batch) {
    jniUpdateBatch(handle_, batch);
  }

  private native long jniNew();
  private native long jniNewWithDims(int[] dims, int batch);
  private native void jniDelete(long shape);
  private native int jniGetitem(long shape, int i);
  private native int[] jniDims(long shape);
  private native int jniDepth(long shape);
  private native int jniBatch(long shape);
  private native int jniVolume(long shape);
  private native int jniLowerVolume(long shape, int dim);
  private native int jniSize(long shape);
  private native String jniToString(long shape);
  private native boolean jniEqual(long shape, long rhs);
  private native boolean jniNotEqual(long shape, long rhs);
  private native boolean jniHasBatch(long shape);
  private native boolean jniHasCompatibleBatch(long shape, long rhs);
  private native boolean jniIsScalar(long shape);
  private native boolean jniIsRowVector(long shape);
  private native boolean jniIsMatrix(long shape);
  private native boolean jniHasSameDims(long shape, long rhs);
  private native boolean jniHasSameLooDims(long shape, long rhs, int dim);
  private native long jniResizeDim(long shape, int dim, int m);
  private native long jniResizeBatch(long shape, int batch);
  private native void jniUpdateDim(long shape, int dim, int m);
  private native void jniUpdateBatch(long shape, int batch);

  static {
    NativeLibrary.load();
  }
}
