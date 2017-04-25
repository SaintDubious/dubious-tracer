#ifndef INCLUDED_CARRIER_CUSTOM_WRITER_H
#define INCLUDED_CARRIER_CUSTOM_WRITER_H

#include <opentracing1/carrier.h>

namespace carrier {

class Custom_writer : public opentracing1::Text_map_writer {
public:
    Custom_writer( char* buffer, int length );
    virtual ~Custom_writer();

    virtual void write( const std::string& key, const std::string& value );

private:
    char* m_buffer;
    int   m_length;
    int   m_index;
};
}
#endif
