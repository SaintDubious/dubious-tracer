#include "custom_writer.h"

#include <iostream>
#include <cstring>

namespace carrier {

Custom_writer::Custom_writer( char* buffer, int length )
    : m_buffer( buffer )
    , m_length( length )
    , m_index( 0 )
{
    std::memset( m_buffer, length, 0 );
}

Custom_writer::~Custom_writer()
{
}

void Custom_writer::write( const std::string& key, const std::string& value )
{
    std::cout << "Writing (" << key << ", " << value << ")\n";
    memcpy( &m_buffer[( m_index++ ) * 50], key.c_str(), key.length() );
    memcpy( &m_buffer[( m_index++ ) * 50], value.c_str(), value.length() );
}
}
