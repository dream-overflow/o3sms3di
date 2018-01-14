/**
 * @brief Ms3d import module object
 * @copyright Copyright (C) 2017 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2017-12-30
 * @details
 */

#include "plugin.h"
#include "importer.h"
#include <o3d/core/base.h>

using namespace o3d::studio::ms3di;

extern "C"
{

O3S_PLUGIN_API o3d::studio::common::Module* o3dstudioPlugin(const o3d::String &name, o3d::DynamicLibrary *library)
{
    Plugin *module = new Plugin(name, library);
    return module;
}

} // extern "C"

Plugin::Plugin(const String &name, DynamicLibrary *library) :
    DynamicModule(name, library),
    m_importer(nullptr)
{
    m_properties["section"] = "o3s::plugin::importer";
    m_properties["verbose"] = "Milkshape3D Importer";

    m_properties["vendor"] = "Dream Overflow";
    m_properties["group"] = "Official extensions";
    m_properties["url"] = "http://o3dstudio.dreamoverflow.org/ms3di";
    m_properties["plateforms"] = "all";

    m_properties["version"] = "1.0.0";
    m_properties["description"] = "A Milkshape 3D models importer";
    m_properties["copyright"] = "(C) 2017 Dream Overflow";
    m_properties["license"] = "Proprietary";

    m_properties["dependencies"] = "";

    m_capacities.setBit(common::CAPACITY_IMPORTER, True);
}

Plugin::~Plugin()
{

}

o3d::Bool Plugin::start()
{
    m_started = True;
    return True;
}

o3d::Bool Plugin::stop()
{
    m_started = False;
    return False;
}

o3d::studio::common::Importer* Plugin::importer()
{
    if (!m_importer) {
        m_importer = new Importer();
    }

    return m_importer;
}
