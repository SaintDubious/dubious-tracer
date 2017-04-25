#include "span_context_serializer.h"
#include "span_context.h"

#include <opentracing1/carrier.h>

namespace dubious {

Span_context_serializer::Span_context_serializer( Span_context& context )
    : m_context( context )
{
}

Span_context_serializer::~Span_context_serializer()
{
}

opentracing1::Result Span_context_serializer::inject( opentracing1::Text_map_writer& carrier ) const
{
    carrier.write( "traceId", m_context.m_trace_id );
    carrier.write( "spanId", m_context.m_span_id );

    return opentracing1::Success;
}

opentracing1::Result Span_context_serializer::extract( opentracing1::Text_map_reader& carrier )
{
    return opentracing1::Success;
}
}
