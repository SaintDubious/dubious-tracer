#include "span_options.h"

namespace dubious {

Span_options::Span_options( const std::string& operation_name )
    : opentracing1::Span_options( operation_name )
{
}

Span_options::~Span_options()
{
}
}
