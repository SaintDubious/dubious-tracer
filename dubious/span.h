#ifndef INCLUDED_DUBIOUS_SPAN_H
#define INCLUDED_DUBIOUS_SPAN_H

#include "span_context.h"

#include <opentracing1/span.h>

namespace dubious {

class Span : public opentracing1::Span {
public:
    virtual ~Span();

private:
    friend class Tracer;

    Span( const std::string& operation_name );

    virtual const opentracing1::Span_context& get_context() const;
    virtual opentracing1::Span_context&       get_context();

    Span_context m_context;
    std::string  m_operation_name;
};
}

#endif
