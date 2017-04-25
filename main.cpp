#include "span.h"
#include "span_options.h"
#include "span_context.h"
#include "tracer.h"

#include "custom_writer.h"

#include <iostream>

int main( int argc, char** argv )
{
    try {
        std::cout << "Start\n";
        opentracing1::init_global_tracer( new dubious::Tracer() );

        dubious::Span_options  options( "main" );
        opentracing1::Span*    span = opentracing1::global_tracer()->start_span( options );
        char                   write_buffer[1000];
        carrier::Custom_writer writer( write_buffer, 1000 );

        opentracing1::global_tracer()->inject(
            *span, *static_cast<opentracing1::Text_map_writer*>( &writer ) );
        opentracing1::global_tracer()->cleanup( span );

        /////////////////////////////

        std::cout << "End\n";
        return 0;
    }
    catch ( const std::exception& e ) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    catch ( ... ) {
        std::cout << "Exception\n";
    }
    return 1;
}