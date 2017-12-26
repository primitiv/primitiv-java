set(primitiv_java_SRCS
  primitiv_Device.cc
  primitiv_devices_Naive.cc
  primitiv_Initializer.cc
  primitiv_initializers_Constant.cc
  primitiv_initializers_Identity.cc
  primitiv_initializers_Normal.cc
  primitiv_initializers_Uniform.cc
  primitiv_initializers_XavierNormal.cc
  primitiv_initializers_XavierUniform.cc
  primitiv_Graph.cc
  primitiv_Node.cc
  primitiv_Parameter.cc
  primitiv_Shape.cc
  primitiv_Tensor.cc
)

set(primitiv_java_JAVA_SRCS
  primitiv/Device.java
  primitiv/devices/Naive.java
  primitiv/Graph.java
  primitiv/Initializer.java
  primitiv/initializers/Constant.java
  primitiv/initializers/Identity.java
  primitiv/initializers/Normal.java
  primitiv/initializers/Uniform.java
  primitiv/initializers/XavierNormal.java
  primitiv/initializers/XavierUniform.java
  primitiv/Node.java
  primitiv/Parameter.java
  primitiv/Shape.java
  primitiv/Tensor.java
  primitiv/HandleObjectHashMap.java
)

set(primitiv_java_javah_CLASSLIST
  primitiv.Device
  primitiv.devices.Naive
  primitiv.Initializer
  primitiv.initializers.Constant
  primitiv.initializers.Identity
  primitiv.initializers.Normal
  primitiv.initializers.Uniform
  primitiv.initializers.XavierNormal
  primitiv.initializers.XavierUniform
  primitiv.Graph
  primitiv.Node
  primitiv.Parameter
  primitiv.Shape
  primitiv.Tensor
)

add_jar(primitiv_java_JAR
  ${primitiv_java_JAVA_SRCS}
  OUTPUT_NAME primitiv
)

create_javah(TARGET primitiv_java_javah
  GENERATED_FILES primitiv_java_HDRS
  CLASSES ${primitiv_java_javah_CLASSLIST}
  CLASSPATH primitiv_java_JAR
  DEPENDS ${primitiv_java_JAVA_SRCS}
)

add_library(primitiv_jni_all_OBJS OBJECT
  ${primitiv_java_HDRS}
  ${primitiv_java_SRCS})
add_dependencies(primitiv_jni_all_OBJS primitiv_java_javah)
set(primitiv_jni_all_OBJS $<TARGET_OBJECTS:primitiv_jni_all_OBJS>)
set(primitiv_jni_all_DEPS)

list(APPEND primitiv_jni_all_DEPS
    ${PRIMITIV_LIBRARIES})

add_library(primitiv_jni SHARED ${primitiv_jni_all_OBJS})
target_link_libraries(primitiv_jni ${primitiv_jni_all_DEPS})
