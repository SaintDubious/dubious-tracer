#include "span.h"

namespace dubious {

Span::Span( const std::string& operation_name )
    : m_operation_name( operation_name )
{
}

Span::~Span()
{
}

const opentracing1::Span_context& Span::get_context() const
{
    return m_context;
}

opentracing1::Span_context& Span::get_context()
{
    return m_context;
}
}
