#include "span_context.h"

namespace dubious {

Span_context::Span_context()
    : m_serializer( *this )
{
}

Span_context::~Span_context()
{
}

const Span_context_serializer& Span_context::get_serializer() const
{
    return m_serializer;
}

Span_context_serializer& Span_context::get_serializer()
{
    return m_serializer;
}
}
