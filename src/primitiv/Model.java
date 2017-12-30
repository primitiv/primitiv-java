/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Model {
  private static HandleObjectHashMap<Model> handle_object_hashmap = new HandleObjectHashMap<Model>();

  protected static Model wrapModel(long handle) {
    if (handle_object_hashmap.containsKey(new Long(handle))) {
      return handle_object_hashmap.get(handle);
    }
    Model result = new Model(handle);
    handle_object_hashmap.put(new Long(handle), result);
    return result;
  }

  protected static void registerWrapper(long handle, Model wrapper) {
    handle_object_hashmap.put(new Long(handle), wrapper);
  }

  protected long handle_;

  public Model() {
    handle_ = jniNew();
    registerWrapper(handle_, this);
  }

  protected Model(long handle) {
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

  public void load(String path, boolean with_stats, Device device) {
    jniLoad(handle_, path, with_stats, device.handle_);
  }

  public void save(String path, boolean with_stats) {
    jniSave(handle_, path, with_stats);
  }

  public void add(String name, Parameter param) {
    jniAddParameter(handle_, name, param.handle_);
  }

  public void add(String name, Model model) {
    jniAddModel(handle_, name, model.handle_);
  }

  public Parameter getParameter(String name) {
    return Parameter.wrapParameter(jniGetParameter(handle_, new String[] {name}));
  }

  public Parameter getParameter(String[] names) {
    return Parameter.wrapParameter(jniGetParameter(handle_, names));
  }

  public Parameter getParameter(List<String> names) {
    return Parameter.wrapParameter(jniGetParameter(handle_, (String[]) names.toArray(new String[0])));
  }

  public Model getSubmodel(String name) {
    return wrapModel(jniGetSubmodel(handle_, new String[] {name}));
  }

  public Model getSubmodel(String[] names) {
    return wrapModel(jniGetSubmodel(handle_, names));
  }

  public Model getSubmodel(List<String> names) {
    return wrapModel(jniGetSubmodel(handle_, (String[]) names.toArray(new String[0])));
  }

  public Map<List<String>, Parameter> getAllParameters() {
    Map<String[], Long> params = jniGetAllParameters(handle_);
    Map<List<String>, Parameter> result = new HashMap<List<String>, Parameter>();
    for (Map.Entry<String[], Long> entry : params.entrySet()) {
      result.put(Arrays.asList(entry.getKey()), Parameter.wrapParameter(entry.getValue().longValue()));
    }
    return result;
  }

  public Map<List<String>, Parameter> getTrainableParameters() {
    Map<String[], Long> params = jniGetTrainableParameters(handle_);
    Map<List<String>, Parameter> result = new HashMap<List<String>, Parameter>();
    for (Map.Entry<String[], Long> entry : params.entrySet()) {
      result.put(Arrays.asList(entry.getKey()), Parameter.wrapParameter(entry.getValue().longValue()));
    }
    return result;
  }

  private native long jniNew();
  private native void jniDelete(long handle);
  private native void jniLoad(long handle, String path, boolean with_stats, long device);
  private native void jniSave(long handle, String path, boolean with_stats);
  private native void jniAddParameter(long handle, String name, long param);
  private native void jniAddModel(long handle, String name, long model);
  private native long jniGetParameter(long handle, String[] names);
  private native long jniGetSubmodel(long handle, String[] names);
  private native Map<String[], Long> jniGetAllParameters(long handle);
  private native Map<String[], Long> jniGetTrainableParameters(long handle);

  static {
    NativeLibrary.load();
  }
}
