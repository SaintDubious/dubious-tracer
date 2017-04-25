#include "tracer.h"

namespace dubious {

Tracer::Tracer()
{
}

Tracer::~Tracer()
{
}

opentracing1::Span* Tracer::start_span( const opentracing1::Span_options& span_options ) const
{
    Span* result = new Span( span_options.m_operation_name );
    /*
    if ( !span_options.m_references.empty() ) {
        result->m_context.m_trace_id = span_options.m_references[0].second->m_trace_id;
    }
    else {
        result->m_context.m_trace_id = "";
    }
    result->m_context.m_span_id = "";
    */

    return result;
}

void Tracer::cleanup( opentracing1::Span* span )
{
    delete span;
}
}

namespace opentracing1 {

Tracer* g_tracer;

Tracer* init_global_tracer( Tracer* tracer )
{
    Tracer* hold = g_tracer;
    g_tracer     = tracer;
    return hold;
}

Tracer* global_tracer()
{
    return g_tracer;
}
}
