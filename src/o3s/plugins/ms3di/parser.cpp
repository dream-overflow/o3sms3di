/**
 * @brief Ms3d import parser object
 * @copyright Copyright (C) 2017 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2017-12-30
 * @details
 */

#include "parser.h"

using namespace o3d::studio::ms3di;

Parser::Parser(o3d::InStream *stream) :
    m_stream(*stream)
{
    O3D_ASSERT(stream != nullptr);
}

Parser::~Parser()
{

}

o3d::Bool Parser::parse()
{
    // @todo
    return True;
}
