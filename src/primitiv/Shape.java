package primitiv;

public class Shape
{
  private long ptr_ = 0;

  public Shape() {
    ptr_ = jniNew();
  }

  public Shape(int[] dims, int batch) {
    ptr_ = jniNewWithDims(dims, dims.length, batch);
  }

  private Shape(long ptr) {
    ptr_ = ptr;
  }

  public void dispose() {
    jniDelete(ptr_);
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
    return jniGetitem(ptr_, i);
  }

  public int[] dims() {
    return jniDims(ptr_);
  }

  public int depth() {
    return jniDepth(ptr_);
  }

  public int batch() {
    return jniBatch(ptr_);
  }

  public int volume() {
    return jniVolume(ptr_);
  }

  public int lower_volume(int dim) {
    return jniLowerVolume(ptr_, dim);
  }

  public int size() {
    return jniSize(ptr_);
  }

  public String to_string() {
    return jniToString(ptr_);
  }

  public boolean equals(Shape rhs) {
    return jniEqual(ptr_, rhs.ptr_);
  }

  public boolean has_batch() {
    return jniHasBatch(ptr_);
  }

  public boolean has_compatible_batch(Shape rhs) {
    return jniHasCompatibleBatch(ptr_, rhs.ptr_);
  }

  public boolean is_scalar() {
    return jniIsScalar(ptr_);
  }

  public boolean is_row_vector() {
    return jniIsRowVector(ptr_);
  }

  public boolean is_matrix() {
    return jniIsMatrix(ptr_);
  }

  public boolean has_same_dims(Shape rhs) {
    return jniHasSameDims(ptr_, rhs.ptr_);
  }

  public boolean has_same_loo_dims(Shape rhs, int dim) {
    return jniHasSameLooDims(ptr_, rhs.ptr_, dim);
  }

  public Shape resize_dim(int dim, int m) {
    return new Shape(jniResizeDim(ptr_, dim, m));
  }

  public Shape resize_batch(int batch) {
    return new Shape(jniResizeBatch(ptr_, batch));
  }

  public void update_dim(int dim, int m) {
    jniUpdateDim(ptr_, dim, m);
  }

  public void update_batch(int batch) {
    jniUpdateBatch(ptr_, batch);
  }

  private native long jniNew();
  private native long jniNewWithDims(int[] dims, int n, int batch);

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
