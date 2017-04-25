#ifndef INCLUDED_DUBIOS_TRACER_H
#define INCLUDED_DUBIOS_TRACER_H

#include "span.h"

#include <opentracing1/tracer.h>

namespace dubious {

class Tracer : public opentracing1::Tracer {
public:
    Tracer();

    virtual ~Tracer();

    virtual opentracing1::Span* start_span( const opentracing1::Span_options& span_options ) const;

    virtual void cleanup( opentracing1::Span* span );

private:
    int m_id_count;
};
}
#endif
