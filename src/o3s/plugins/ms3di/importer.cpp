/**
 * @brief MS3D importer controller object
 * @copyright Copyright (C) 2018 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2018-01-14
 * @details
 */

#include "importer.h"
#include "parser.h"

#include <o3d/core/filemanager.h>

using namespace o3d::studio::ms3di;

Importer::Importer() :
    common::Importer()
{
    m_name = "o3s::plugin::importer::ms3di";
    m_exts = "MilkShape3D (*.ms3d)";
}

Importer::~Importer()
{

}

o3d::studio::common::ImporterOption *Importer::buildOptions() const
{
    return nullptr;
}

o3d::studio::common::ImportDefinition *Importer::introspect(const o3d::String &filename) const
{
    InStream *inStream = o3d::FileManager::instance()->openInStream(filename);
    Ms3dImportDefinition *def = new Ms3dImportDefinition(File(filename).getFilePath());

    Parser *parser = new Parser(inStream);
    Bool result = parser->parse();

    // keep global structure except data
    // @todo

    delete parser;
    delete inStream;

    if (result) {
        return def;
    } else {
        delete def;
        return nullptr;
    }
}

o3d::studio::common::ImportDefinition *Importer::import(const o3d::String &filename,
        o3d::studio::common::ImporterOption *options,
        common::Hub *parent) const
{
    InStream *inStream = o3d::FileManager::instance()->openInStream(filename);
    Ms3dImportDefinition *def = new Ms3dImportDefinition(File(filename).getFilePath());

    Parser *parser = new Parser(inStream);
    Bool result = parser->parse();

    // instanciate into parent entity
    // @todo

    delete parser;
    delete inStream;

    if (result) {
        return def;
    } else {
        delete def;
        return nullptr;
    }
}

Ms3dImportDefinition::Ms3dImportDefinition(const o3d::String &basePath) :
    m_basePath(basePath)
{

}

Ms3dImportDefinition::~Ms3dImportDefinition()
{

}

o3d::String Ms3dImportDefinition::basePath() const
{
    return m_basePath;
}

o3d::String Ms3dImportDefinition::creator() const
{
    return m_creator;
}

o3d::DateTime Ms3dImportDefinition::creationDateTime() const
{
    return m_ceationTimestamp;
}

o3d::Float Ms3dImportDefinition::unit() const
{
    return m_unit;
}

o3d::Color Ms3dImportDefinition::ambientColor() const
{
    return m_ambient;
}

o3d::UInt32 Ms3dImportDefinition::numModel() const
{
    return m_numModel;
}

o3d::UInt32 Ms3dImportDefinition::numGeometry() const
{
    return m_numGeometry;
}

o3d::UInt32 Ms3dImportDefinition::numMaterial() const
{
    return m_numMaterial;
}

o3d::UInt32 Ms3dImportDefinition::numCamera() const
{
    return m_numCamera;
}

o3d::UInt32 Ms3dImportDefinition::numLight() const
{
    return m_numLight;
}
