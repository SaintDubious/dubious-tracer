#ifndef INCLUDED_DUBIOUS_SPAN_OPTIONS_H
#define INCLUDED_DUBIOUS_SPAN_OPTIONS_H

#include <opentracing1/span_options.h>

namespace dubious {

class Span_options : public opentracing1::Span_options {
public:
    Span_options( const std::string& operation_name );

    virtual ~Span_options();
};
}

#endif
