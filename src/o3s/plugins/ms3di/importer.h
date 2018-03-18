/**
 * @brief MS3D importer controller
 * @copyright Copyright (C) 2018 Dream Overflow. All rights reserved.
 * @author Frederic SCHERMA (frederic.scherma@dreamoverflow.org)
 * @date 2018-01-14
 * @details
 */

#ifndef _O3DS_MS3DI_IMPORTER_H
#define _O3DS_MS3DI_IMPORTER_H

#include <o3d/core/instream.h>
#include <o3d/studio/common/global.h>
#include <o3d/studio/common/importer/importer.h>
#include <o3d/studio/common/importer/importdefinition.h>

namespace o3d {
namespace studio {
namespace ms3di {

/**
 * @brief The Ms3dImportDefinition class
 * @todo more detailed objects list (name, info per type...)
 */
class O3S_PLUGIN_API Ms3dImportDefinition : public common::ImportDefinition
{
public:

    Ms3dImportDefinition(const String &basePath);

    virtual ~Ms3dImportDefinition();

    virtual String basePath() const override;

    virtual String creator() const override;
    virtual DateTime creationDateTime() const override;
    virtual Float unit() const override;
    virtual Color ambientColor() const override;

    virtual UInt32 numModel() const override;
    virtual UInt32 numGeometry() const override;
    virtual UInt32 numMaterial() const override;
    virtual UInt32 numCamera() const override;
    virtual UInt32 numLight() const override;

private:

    String m_basePath;

    String m_creator;
    DateTime m_ceationTimestamp;
    Float m_unit;

    Color m_ambient;

    UInt32 m_numModel;
    UInt32 m_numGeometry;
    UInt32 m_numMaterial;
    UInt32 m_numCamera;
    UInt32 m_numLight;
};

class Importer : public common::Importer
{
public:

    Importer();
    virtual ~Importer();

    virtual common::ImporterOption* buildOptions() const override;
    virtual common::ImportDefinition* introspect(const String &filename) const override;
    virtual common::ImportDefinition* import(
            const String &filename,
            common::ImporterOption *options,
            common::Hub *parent) const override;
};

} // namespace fbxi
} // namespace studio
} // namespace o3d

#endif // _O3DS_MS3DI_IMPORTER_H
