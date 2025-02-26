
#ifndef THREEPP_INTERFACES_HPP
#define THREEPP_INTERFACES_HPP

#include "threepp/materials/Material.hpp"

#include "threepp/textures/Texture.hpp"

namespace threepp {

    struct MaterialWithColor: virtual Material {

        Color color;

        explicit MaterialWithColor(Color color): color(color) {}
    };

    struct MaterialWithRotation: virtual Material {

        float rotation{};
    };

    struct MaterialWithClipping: virtual Material {

        bool clipping;

        explicit MaterialWithClipping(bool clipping): clipping(clipping) {}
    };

    struct MaterialWithLights: virtual Material {

        bool lights;

        explicit MaterialWithLights(bool lights): lights(lights) {}
    };

    struct MaterialWithSize: virtual Material {

        float size;
        bool sizeAttenuation;

        MaterialWithSize(float size, bool sizeAttenuation): size(size), sizeAttenuation(sizeAttenuation) {}
    };

    struct MaterialWithLineWidth: virtual Material {

        float linewidth;

        explicit MaterialWithLineWidth(float linewidth): linewidth(linewidth) {}
    };

    struct MaterialWithEmissive: virtual Material {

        Color emissive;
        float emissiveIntensity;
        std::shared_ptr<Texture> emissiveMap;

        MaterialWithEmissive(Color emissive, float emissiveIntensity): emissive(emissive), emissiveIntensity(emissiveIntensity) {}
    };

    struct MaterialWithSpecular: virtual Material {

        Color specular;
        float shininess;

        MaterialWithSpecular(Color specular, float shininess): specular(specular), shininess(shininess) {}
    };

    struct MaterialWithReflectivityRatio: virtual Material {

        float refractionRatio;

        explicit MaterialWithReflectivityRatio(float refractionRatio): refractionRatio(refractionRatio) {}
    };

    struct MaterialWithReflectivity: virtual Material, public MaterialWithReflectivityRatio {

        float reflectivity;

        MaterialWithReflectivity(float reflectivity, float refractionRatio): MaterialWithReflectivityRatio(refractionRatio), reflectivity(reflectivity) {}
    };

    struct MaterialWithWireframe: virtual Material {

        bool wireframe;
        float wireframeLinewidth;

        MaterialWithWireframe(bool wireframe, float wireframeLinewidth): wireframe(wireframe), wireframeLinewidth(wireframeLinewidth) {}
    };

    struct MaterialWithMap: virtual Material {

        std::shared_ptr<Texture> map;
    };

    struct MaterialWithAlphaMap: virtual Material {

        std::shared_ptr<Texture> alphaMap;
    };

    struct MaterialWithSpecularMap: virtual Material {

        std::shared_ptr<Texture> specularMap;
    };

    struct MaterialWithEnvMap: virtual Material {

        float envMapIntensity;// Only used by MeshStandardMaterial
        std::shared_ptr<Texture> envMap;

        explicit MaterialWithEnvMap(std::optional<float> envMapIntensity = std::nullopt): envMapIntensity(envMapIntensity.value_or(1)) {}
    };

    struct MaterialWithGradientMap: virtual Material {

        std::shared_ptr<Texture> gradientMap;
    };

    struct MaterialWithAoMap: virtual Material {

        std::shared_ptr<Texture> aoMap;
        float aoMapIntensity;

        explicit MaterialWithAoMap(float aoMapIntensity): aoMapIntensity(aoMapIntensity) {}
    };

    struct MaterialWithBumpMap: virtual Material {

        std::shared_ptr<Texture> bumpMap;
        float bumpScale;

        explicit MaterialWithBumpMap(float bumpScale): bumpScale(bumpScale) {}
    };

    struct MaterialWithLightMap: virtual Material {

        std::shared_ptr<Texture> lightMap;
        float lightMapIntensity;

        explicit MaterialWithLightMap(float lightMapIntensity): lightMapIntensity(lightMapIntensity) {}
    };

    struct MaterialWithDisplacementMap: virtual Material {

        std::shared_ptr<Texture> displacementMap;
        float displacementScale;
        float displacementBias;

        MaterialWithDisplacementMap(float displacementScale, float displacementBias): displacementScale(displacementScale), displacementBias(displacementBias) {}
    };

    struct MaterialWithNormalMap: virtual Material {

        std::shared_ptr<Texture> normalMap;
        NormalMapType normalMapType;
        Vector2 normalScale;

        MaterialWithNormalMap(NormalMapType normalMapType, Vector2 normalScale): normalMapType(normalMapType), normalScale(normalScale) {}
    };

    struct MaterialWithMatCap: virtual Material {

        std::shared_ptr<Texture> matcap;
    };

    struct MaterialWithRoughness: virtual Material {

        float roughness;
        std::shared_ptr<Texture> roughnessMap;

        explicit MaterialWithRoughness(float roughness): roughness(roughness) {}
    };

    struct MaterialWithMetalness: virtual Material {

        float metalness;
        std::shared_ptr<Texture> metalnessMap;

        explicit MaterialWithMetalness(float metalness): metalness(metalness) {}
    };

    struct MaterialWithThickness: virtual Material {

        std::shared_ptr<Texture> thicknessMap;
    };

    struct MaterialWithSheen: virtual Material {

        std::optional<Color> sheen;
    };

    struct MaterialWithCombine: virtual Material {

        CombineOperation combine;

        explicit MaterialWithCombine(CombineOperation combine): combine(combine) {}
    };

    struct MaterialWithDepthPacking: virtual Material {

        DepthPacking depthPacking;

        explicit MaterialWithDepthPacking(DepthPacking depthPacking): depthPacking(depthPacking) {}
    };

    struct MaterialWithFlatShading: virtual Material {

        bool flatShading;

        explicit MaterialWithFlatShading(bool flatShading): flatShading(flatShading) {}
    };

    struct MaterialWithVertexTangents: virtual Material {

        bool vertexTangents;

        explicit MaterialWithVertexTangents(bool vertexTangents): vertexTangents(vertexTangents) {}
    };

    struct MaterialWithDefines: virtual Material {

        std::unordered_map<std::string, std::string> defines;
    };

    struct MaterialWithMorphTargets: virtual Material {

        bool morphTargets = false;
        bool morphNormals = false;
    };

}// namespace threepp


#endif//THREEPP_INTERFACES_HPP
