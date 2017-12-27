/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

package primitiv;

public final class functions {

  private functions() {}

  public static Node positive(Node x) {
    return new Node(jniPositive(x.handle_));
  }

  public static Node negative(Node x) {
    return new Node(jniNegative(x.handle_));
  }

  public static Node add(Node x, float k) {
    return new Node(jniAddNodeConst(x.handle_, k));
  }

  public static Node add(float k, Node x) {
    return new Node(jniAddConstNode(k, x.handle_));
  }

  public static Node add(Node a, Node b) {
    return new Node(jniAddNodeNode(a.handle_, b.handle_));
  }

  public static Node subtract(Node x, float k) {
    return new Node(jniSubtractNodeConst(x.handle_, k));
  }

  public static Node subtract(float k, Node x) {
    return new Node(jniSubtractConstNode(k, x.handle_));
  }

  public static Node subtract(Node a, Node b) {
    return new Node(jniSubtractNodeNode(a.handle_, b.handle_));
  }

  public static Node multiply(Node x, float k) {
    return new Node(jniMultiplyNodeConst(x.handle_, k));
  }

  public static Node multiply(float k, Node x) {
    return new Node(jniMultiplyConstNode(k, x.handle_));
  }

  public static Node multiply(Node a, Node b) {
    return new Node(jniMultiplyNodeNode(a.handle_, b.handle_));
  }

  public static Node divide(Node x, float k) {
    return new Node(jniDivideNodeConst(x.handle_, k));
  }

  public static Node divide(float k, Node x) {
    return new Node(jniDivideConstNode(k, x.handle_));
  }

  public static Node divide(Node a, Node b) {
    return new Node(jniDivideNodeNode(a.handle_, b.handle_));
  }

  public static Node pow(Node x, float k) {
    return new Node(jniPowNodeConst(x.handle_, k));
  }

  public static Node pow(float k, Node x) {
    return new Node(jniPowConstNode(k, x.handle_));
  }

  public static Node pow(Node a, Node b) {
    return new Node(jniPowNodeNode(a.handle_, b.handle_));
  }

  public static Node input(Shape shape, float[] data, Device dev, Graph g) {
    return new Node(jniInput(shape.handle_, data, dev.handle_, g.handle_));
  }

  public static Node input(Shape shape, float[] data, Device dev) {
    return new Node(jniInput(shape.handle_, data, dev.handle_, 0));
  }

  public static Node input(Shape shape, float[] data) {
    return new Node(jniInput(shape.handle_, data, 0, 0));
  }

  public static Node parameter(Parameter param, Graph g) {
    return new Node(jniParameter(param.handle_, g.handle_));
  }

  public static Node parameter(Parameter param) {
    return new Node(jniParameter(param.handle_, 0));
  }

  public static Node copy(Node x, Device dev) {
    return new Node(jniCopy(x.handle_, dev.handle_));
  }

  public static Node copy(Node x) {
    return new Node(jniCopy(x.handle_, 0));
  }

  public static Node pick(Node x, int[] ids, int dim) {
    return new Node(jniPick(x.handle_, ids, dim));
  }

  public static Node slice(Node x, int dim, int lower, int upper) {
    return new Node(jniSlice(x.handle_, dim, lower, upper));
  }

  public static Node concat(Node[] xs, int dim) {
    long[] x_ptrs = new long[xs.length];
    for (int i = 0; i < xs.length; ++i) {
      x_ptrs[i] = xs[i].handle_;
    }
    return new Node(jniConcat(x_ptrs, dim));
  }

  public static Node reshape(Node x, Shape new_shape) {
    return new Node(jniReshape(x.handle_, new_shape.handle_));
  }

  public static Node flatten(Node x) {
    return new Node(jniFlatten(x.handle_));
  }

  public static Node transpose(Node x) {
    return new Node(jniTranspose(x.handle_));
  }

  public static Node matmul(Node a, Node b) {
    return new Node(jniMatmul(a.handle_, b.handle_));
  }

  public static Node sqrt(Node x) {
    return new Node(jniSqrt(x.handle_));
  }

  public static Node exp(Node x) {
    return new Node(jniExp(x.handle_));
  }

  public static Node log(Node x) {
    return new Node(jniLog(x.handle_));
  }

  public static Node tanh(Node x) {
    return new Node(jniTanh(x.handle_));
  }

  public static Node sigmoid(Node x) {
    return new Node(jniSigmoid(x.handle_));
  }

  public static Node softplus(Node x) {
    return new Node(jniSoftplus(x.handle_));
  }

  public static Node sin(Node x) {
    return new Node(jniSin(x.handle_));
  }

  public static Node cos(Node x) {
    return new Node(jniCos(x.handle_));
  }

  public static Node tan(Node x) {
    return new Node(jniTan(x.handle_));
  }

  public static Node relu(Node x) {
    return new Node(jniRelu(x.handle_));
  }

  public static Node lrelu(Node x) {
    return new Node(jniLrelu(x.handle_));
  }

  public static Node prelu(Node x, float a) {
    return new Node(jniPrelu(x.handle_, a));
  }

  public static Node elu(Node x, float a) {
    return new Node(jniElu(x.handle_, a));
  }

  public static Node sum(Node x, int dim) {
    return new Node(jniSum(x.handle_, dim));
  }

  public static Node broadcast(Node x, int dim, int size) {
    return new Node(jniBroadcast(x.handle_, dim, size));
  }

  public static Node logsumexp(Node x, int dim) {
    return new Node(jniLogsumexp(x.handle_, dim));
  }

  public static Node log_softmax(Node x, int dim) {
    return new Node(jniLogSoftmax(x.handle_, dim));
  }

  public static Node softmax(Node x, int dim) {
    return new Node(jniSoftmax(x.handle_, dim));
  }

  public static Node softmax_cross_entropy(Node x, Node t, int dim) {
    return new Node(jniSoftmaxCrossEntropy(x.handle_, t.handle_, dim));
  }

  public static Node softmax_cross_entropy(Node x, int[] ids, int dim) {
    return new Node(jniSoftmaxCrossEntropyWithArray(x.handle_, ids, dim));
  }

  public static Node stop_gradient(Node x) {
    return new Node(jniStopGradient(x.handle_));
  }


  public static class batch {
    public static Node sum(Node x) {
      return new Node(jniBatchSum(x.handle_));
    }

    public static Node mean(Node x) {
      return new Node(jniBatchMean(x.handle_));
    }

    public static Node normalize(Node x) {
      return new Node(jniBatchNormalize(x.handle_));
    }
  }

  public static Node constant(Shape shape, float k, Device dev, Graph g) {
    return new Node(jniConstant(shape.handle_, k, dev.handle_, g.handle_));
  }

  public static Node constant(Shape shape, float k, Device dev) {
    return new Node(jniConstant(shape.handle_, k, dev.handle_, 0));
  }

  public static Node constant(Shape shape, float k) {
    return new Node(jniConstant(shape.handle_, k, 0, 0));
  }

  public static Node identity(int size, Device dev, Graph g) {
    return new Node(jniIdentity(size, dev.handle_, g.handle_));
  }

  public static Node identity(int size, Device dev) {
    return new Node(jniIdentity(size, dev.handle_, 0));
  }

  public static Node identity(int size) {
    return new Node(jniIdentity(size, 0, 0));
  }

  public static class random {
    public static Node bernoulli(Shape shape, float p, Device dev, Graph g) {
      return new Node(jniRandomBernoulli(shape.handle_, p, dev.handle_, g.handle_));
    }

    public static Node bernoulli(Shape shape, float p, Device dev) {
      return new Node(jniRandomBernoulli(shape.handle_, p, dev.handle_, 0));
    }

    public static Node bernoulli(Shape shape, float p) {
      return new Node(jniRandomBernoulli(shape.handle_, p, 0, 0));
    }

    public static Node uniform(Shape shape, float lower, float upper, Device dev, Graph g) {
      return new Node(jniRandomUniform(shape.handle_, lower, upper, dev.handle_, g.handle_));
    }

    public static Node uniform(Shape shape, float lower, float upper, Device dev) {
      return new Node(jniRandomUniform(shape.handle_, lower, upper, dev.handle_, 0));
    }

    public static Node uniform(Shape shape, float lower, float upper) {
      return new Node(jniRandomUniform(shape.handle_, lower, upper, 0, 0));
    }

    public static Node normal(Shape shape, float mean, float sd, Device dev, Graph g) {
      return new Node(jniRandomNormal(shape.handle_, mean, sd, dev.handle_, g.handle_));
    }

    public static Node normal(Shape shape, float mean, float sd, Device dev) {
      return new Node(jniRandomNormal(shape.handle_, mean, sd, dev.handle_, 0));
    }

    public static Node normal(Shape shape, float mean, float sd) {
      return new Node(jniRandomNormal(shape.handle_, mean, sd, 0, 0));
    }

    public static Node log_normal(Shape shape, float mean, float sd, Device dev, Graph g) {
      return new Node(jniRandomLogNormal(shape.handle_, mean, sd, dev.handle_, g.handle_));
    }

    public static Node log_normal(Shape shape, float mean, float sd, Device dev) {
      return new Node(jniRandomLogNormal(shape.handle_, mean, sd, dev.handle_, 0));
    }

    public static Node log_normal(Shape shape, float mean, float sd) {
      return new Node(jniRandomLogNormal(shape.handle_, mean, sd, 0, 0));
    }

    public static Node gumbel(Shape shape, float mu, float beta, Device dev, Graph g) {
      return new Node(jniRandomGumbel(shape.handle_, mu, beta, dev.handle_, g.handle_));
    }

    public static Node gumbel(Shape shape, float mu, float beta, Device dev) {
      return new Node(jniRandomGumbel(shape.handle_, mu, beta, dev.handle_, 0));
    }

    public static Node gumbel(Shape shape, float mu, float beta) {
      return new Node(jniRandomGumbel(shape.handle_, mu, beta, 0, 0));
    }
  }

  public static Node pown(Node x, int k) {
    return new Node(jniPown(x.handle_, k));
  }

  public static Node selu(Node x, float a, float s) {
    return new Node(jniSelu(x.handle_, a, s));
  }

  public static Node sum(Node[] xs) {
    long[] x_ptrs = new long[xs.length];
    for (int i = 0; i < xs.length; ++i) {
      x_ptrs[i] = xs[i].handle_;
    }
    return new Node(jniSumNodes(x_ptrs));
  }

  public static Node mean(Node x, int dim) {
    return new Node(jniMean(x.handle_, dim));
  }

  public static Node mean(Node[] xs) {
    long[] x_ptrs = new long[xs.length];
    for (int i = 0; i < xs.length; ++i) {
      x_ptrs[i] = xs[i].handle_;
    }
    return new Node(jniMeanNodes(x_ptrs));
  }

  public static Node zeros(Shape shape, Device dev, Graph g) {
    return new Node(jniZeros(shape.handle_, dev.handle_, g.handle_));
  }

  public static Node zeros(Shape shape, Device dev) {
    return new Node(jniZeros(shape.handle_, dev.handle_, 0));
  }

  public static Node zeros(Shape shape) {
    return new Node(jniZeros(shape.handle_, 0, 0));
  }

  public static Node ones(Shape shape, Device dev, Graph g) {
    return new Node(jniOnes(shape.handle_, dev.handle_, g.handle_));
  }

  public static Node ones(Shape shape, Device dev) {
    return new Node(jniOnes(shape.handle_, dev.handle_, 0));
  }

  public static Node ones(Shape shape) {
    return new Node(jniOnes(shape.handle_, 0, 0));
  }

  public static Node dropout(Node x, float rate, boolean enabled) {
    return new Node(jniDropout(x.handle_, rate, enabled));
  }

  private static native long jniPositive(long x);
  private static native long jniNegative(long x);
  private static native long jniAddNodeConst(long x, float k);
  private static native long jniAddConstNode(float k, long x);
  private static native long jniAddNodeNode(long a, long b);
  private static native long jniSubtractNodeConst(long x, float k);
  private static native long jniSubtractConstNode(float k, long x);
  private static native long jniSubtractNodeNode(long a, long b);
  private static native long jniMultiplyNodeConst(long x, float k);
  private static native long jniMultiplyConstNode(float k, long x);
  private static native long jniMultiplyNodeNode(long a, long b);
  private static native long jniDivideNodeConst(long x, float k);
  private static native long jniDivideConstNode(float k, long x);
  private static native long jniDivideNodeNode(long a, long b);
  private static native long jniPowNodeConst(long x, float k);
  private static native long jniPowConstNode(float k, long x);
  private static native long jniPowNodeNode(long a, long b);
  private static native long jniInput(long shape, float[] data, long dev, long g);
  private static native long jniParameter(long param, long g);
  private static native long jniCopy(long x, long dev);
  private static native long jniPick(long x, int[] ids, int dim);
  private static native long jniSlice(long x, int dim, int lower, int upper);
  private static native long jniConcat(long[] x_ptrs, int dim);
  private static native long jniReshape(long x, long new_shape);
  private static native long jniFlatten(long x);
  private static native long jniTranspose(long x);
  private static native long jniMatmul(long a, long b);
  private static native long jniSqrt(long x);
  private static native long jniExp(long x);
  private static native long jniLog(long x);
  private static native long jniTanh(long x);
  private static native long jniSigmoid(long x);
  private static native long jniSoftplus(long x);
  private static native long jniSin(long x);
  private static native long jniCos(long x);
  private static native long jniTan(long x);
  private static native long jniRelu(long x);
  private static native long jniLrelu(long x);
  private static native long jniPrelu(long x, float a);
  private static native long jniElu(long x, float a);
  private static native long jniSum(long x, int dim);
  private static native long jniBroadcast(long x, int dim, int size);
  private static native long jniLogsumexp(long x, int dim);
  private static native long jniLogSoftmax(long x, int dim);
  private static native long jniSoftmax(long x, int dim);
  private static native long jniSoftmaxCrossEntropy(long x, long t, int dim);
  private static native long jniSoftmaxCrossEntropyWithArray(long x, int[] ids, int dim);
  private static native long jniStopGradient(long x);
  private static native long jniBatchSum(long x);
  private static native long jniBatchMean(long x);
  private static native long jniBatchNormalize(long x);
  private static native long jniConstant(long shape, float k, long dev, long g);
  private static native long jniIdentity(int size, long dev, long g);
  private static native long jniRandomBernoulli(long shape, float p, long dev, long g);
  private static native long jniRandomUniform(long shape, float lower, float upper, long dev, long g);
  private static native long jniRandomNormal(long shape, float mean, float sd, long dev, long g);
  private static native long jniRandomLogNormal(long shape, float mean, float sd, long dev, long g);
  private static native long jniRandomGumbel(long shape, float mu, float beta, long dev, long g);
  private static native long jniPown(long x, int k);
  private static native long jniSelu(long x, float a, float s);
  private static native long jniSumNodes(long[] x_ptrs);
  private static native long jniMean(long x, int dim);
  private static native long jniMeanNodes(long[] x_ptrs);
  private static native long jniZeros(long shape, long dev, long g);
  private static native long jniOnes(long shape, long dev, long g);
  private static native long jniDropout(long x, float rate, boolean enabled);

  static {
    NativeLibrary.load();
  }
}
