/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

import java.util.List;


public abstract class Optimizer {
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

  public void load(String path) {
    jniLoad(handle_, path);
  }

  public void save(String path) {
    jniSave(handle_, path);
  }

  public int getEpoch() {
    return jniGetEpoch(handle_);
  }

  public void setEpoch(int epoch) {
    jniSetEpoch(handle_, epoch);
  }

  public float getLearningRateScaling() {
    return jniGetLearningRateScaling(handle_);
  }

  public void setLearningRateScaling(float scale) {
    jniSetLearningRateScaling(handle_, scale);
  }

  public float getWeightDecay() {
    return jniGetWeightDecay(handle_);
  }

  public void setWeightDecay(float strength) {
    jniSetWeightDecay(handle_, strength);
  }

  public float getGradientClipping() {
    return jniGetGradientClipping(handle_);
  }

  public void setGradientClipping(float threshold) {
    jniSetGradientClipping(handle_, threshold);
  }

  public void add() {}

  public void add(Parameter... params) {
    for (Parameter param : params) {
      jniAdd(handle_, param.handle_);
    }
  }

  public void add(List<Parameter> params) {
    for (Parameter param : params) {
      jniAdd(handle_, param.handle_);
    }
  }

  public void resetGradients() {
    jniResetGradients(handle_);
  }

  public void update() {
    jniUpdate(handle_);
  }

  private native void jniDelete(long handle);
  private native void jniLoad(long handle, String path);
  private native void jniSave(long handle, String path);
  private native int jniGetEpoch(long handle);
  private native void jniSetEpoch(long handle, int epoch);
  private native float jniGetLearningRateScaling(long handle);
  private native void jniSetLearningRateScaling(long handle, float scale);
  private native float jniGetWeightDecay(long handle);
  private native void jniSetWeightDecay(long handle, float strength);
  private native float jniGetGradientClipping(long handle);
  private native void jniSetGradientClipping(long handle, float threshold);
  private native void jniAdd(long handle, long param);
  private native void jniResetGradients(long handle);
  private native void jniUpdate(long handle);

  static {
    NativeLibrary.load();
  }
}
