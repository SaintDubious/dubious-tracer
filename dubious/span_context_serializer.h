#ifndef INCLUDED_DUBIOUS_SPAN_CONTEXT_SERIALIZER_H
#define INCLUDED_DUBIOUS_SPAN_CONTEXT_SERIALIZER_H

#include <opentracing1/span_context_serializer.h>

namespace dubious {

class Span_context;

class Span_context_serializer : public opentracing1::Span_context_serializer {
public:
    Span_context_serializer( Span_context& context );
    virtual ~Span_context_serializer();

    virtual opentracing1::Result inject( opentracing1::Text_map_writer& carrier ) const;

    virtual opentracing1::Result extract( opentracing1::Text_map_reader& carrier );

private:
    Span_context& m_context;
};
}

#endif
