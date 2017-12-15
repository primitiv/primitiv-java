package primitiv;

final class NativeLibrary {
  private static final boolean DEBUG =
      System.getProperty("primitiv.NativeLibrary.DEBUG") != null;
  private static final String JNI_LIBNAME = "primitiv_jni";

  public static void load() {
      tryLoadLibrary();
  }

  private static boolean tryLoadLibrary() {
    try {
      System.loadLibrary(JNI_LIBNAME);
      return true;
    } catch (UnsatisfiedLinkError e) {
      log("tryLoadLibraryFailed: " + e.getMessage());
      return false;
    }
  }

  private static void log(String message) {
    if (DEBUG) {
      System.err.println("org.tensorflow.NativeLibrary: " + message);
    }
  }

  private NativeLibrary() {}
}
