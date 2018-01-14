/**
 * @brief Ms3d import import module object
 * @copyright Copyright (C) 2017 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2017-10-19
 * @details
 */

#ifndef _O3DS_MS3DI_PLUGIN_H
#define _O3DS_MS3DI_PLUGIN_H

#include <o3d/studio/common/dynamicmodule.h>
#include "importer.h"

namespace o3d {
namespace studio {
namespace ms3di {

class O3S_PLUGIN_API Plugin : public studio::common::DynamicModule
{
public:

    Plugin(const String &name, DynamicLibrary *library);
    virtual ~Plugin();

    virtual Bool start() override;
    virtual Bool stop() override;

    virtual common::Importer* importer() override;

private:

    class Importer *m_importer;
};

} // namespace ms3di
} // namespace studio
} // namespace o3d

#endif // _O3DS_MS3DI_PLUGIN_H
