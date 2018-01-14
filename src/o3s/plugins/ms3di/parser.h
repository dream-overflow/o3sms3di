/**
 * @brief dummy module object
 * @copyright Copyright (C) 2017 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2017-10-19
 * @details
 */

#ifndef _O3DS_MS3DI_PARSER_H
#define _O3DS_MS3DI_PARSER_H

#include <o3d/core/instream.h>

namespace o3d {
namespace studio {
namespace ms3di {

class Parser
{
public:

    Parser(InStream *stream);
    virtual ~Parser();

    o3d::Bool parse();

private:

    InStream &m_stream;
};

} // namespace ms3di
} // namespace studio
} // namespace o3d

#endif // _O3DS_MS3DI_PARSER_H
