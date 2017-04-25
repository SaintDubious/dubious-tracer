#ifndef INCLUDED_DUBIOUS_SPAN_CONTEXT_H
#define INCLUDED_DUBIOUS_SPAN_CONTEXT_H

#include "span_context_serializer.h"

#include <opentracing1/span_context.h>

#include <string>

namespace dubious {

class Span_context : public opentracing1::Span_context {
public:
    Span_context();
    virtual ~Span_context();

private:
    friend class Span_context_serializer;
    friend class Tracer;

    virtual const Span_context_serializer& get_serializer() const;
    virtual Span_context_serializer&       get_serializer();

    Span_context_serializer m_serializer;

    std::string m_trace_id;
    std::string m_span_id;
};
}

#endif
