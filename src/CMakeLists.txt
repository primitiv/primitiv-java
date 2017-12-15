set(primitiv_java_SRCS
  primitiv_Parameter.cc
  primitiv_Shape.cc
)

set(primitiv_java_CLASSLIST
  primitiv.Parameter
  primitiv.Shape
)

add_jar(primitiv_java_JAR
  primitiv/Parameter.java
  primitiv/Shape.java
  OUTPUT_NAME primitiv
)

create_javah(TARGET primitiv_java_javah
  GENERATED_FILES primitiv_java_HDRS
  CLASSES ${primitiv_java_CLASSLIST}
  CLASSPATH primitiv_java_JAR
)

add_library(primitiv_java_all_OBJS OBJECT
  ${primitiv_java_HDRS}
  ${primitiv_java_SRCS})
add_dependencies(primitiv_java_all_OBJS primitiv_java_javah)
set(primitiv_java_all_OBJS $<TARGET_OBJECTS:primitiv_java_all_OBJS>)
set(primitiv_java_all_DEPS)

list(APPEND primitiv_java_all_DEPS
    ${PRIMITIV_LIBRARIES})

add_library(primitiv_java SHARED ${primitiv_java_all_OBJS})
target_link_libraries(primitiv_java ${primitiv_java_all_DEPS})
