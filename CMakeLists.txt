cmake_minimum_required (VERSION 3.5)
project (dubious-tracer)

include_directories( dubious )
include_directories( carrier )
include_directories( /home/ubuntu/opentracing-cpp )

set(DUBIOUS_HEADERS 
    dubious/tracer.h 
    dubious/span.h 
    dubious/span_options.h 
    dubious/span_context.h
    dubious/span_context_serializer.h
)
set(DUBIOUS_SRC
    dubious/tracer.cpp
    dubious/span.cpp
    dubious/span_options.cpp
    dubious/span_context.cpp
    dubious/span_context_serializer.cpp
)

set(CARRIER_HEADERS
    carrier/custom_writer.h
)

set(CARRIER_SRC
    carrier/custom_writer.cpp
)

add_executable(dubious-tracer main.cpp 
               ${DUBIOUS_HEADERS} ${DUBIOUS_SRC} 
               ${CARRIER_HEADERS} ${CARRIER_SRC}
)