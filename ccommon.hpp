
#include "avector3d.hpp"
#define C_SMALL 1e-6
using cMatrix3d = Eigen::Matrix3d;
// TODO: cCollisionEvent,cCollisionSettings,cCollisionRecorder,cGenericObject,cWorld
struct cHapticTexture
{

};

// cNormalMapPtr
// m_normalMap
// m_texture
// cTexture1dPtr
// cColorb

struct cVertices
{
    cVector3d getLocalPos(int i ) { return cVector3d(); }
    cVector3d getTexCoord(int i ) { return cVector3d(); }
    cVector3d getNormal(int i) {return cVector3d(); }
};

struct cColorb
{
    int getR() const;
    int getB() const;
    int getG() const;
};

struct cImage
{
    int getWidth() {return 0;}
    int getHeight() {return 0;}

    void getPixelColor(int x, int y, cColorb &);
};

struct cTriangles
{
    int getVertexIndex0(int i) { return 0; }
    int getVertexIndex1(int i) {return 0; }
    int getVertexIndex2(int i) {return 0; }

    cVertices * m_vertices;
};
struct cTexture1d
{

};
using cTexture1dPtr = cTexture1d*;

struct cNormalMap
{
    cImage * m_image;
};

using cNormalMapPtr = cNormalMap*;

struct cHapticMaterial
{
    bool getUseHapticShading() {return false;}
    bool getUseHapticFriction() {return false;}
    bool getUseDynamicFriction() {return false; }
    double getDynamicFriction() {return 0;}
    double getStaticFriction() {return 0;}
    double getStiffness() {return 0; }
    cHapticTexture * getUseHapticTexture() { return 0; }
    double getTextureLevel();
};

class cGenericObject
{
public:
// m_material->getUseHapticShading()
// m_material->getUseHapticTexture()
    cVector3d getGlobalPos() const;
    cMatrix3d getGlobalRot() const;

    cHapticMaterial * m_material;
    cNormalMapPtr m_normalMap;
    cTexture1dPtr  m_texture;
};

#if 0
enum CollisionType {C_COL_TRIANGLE};
class cCollisionEvent
{
public:
    void clear()
    {}

    CollisionType m_type;

    int m_index;
    cGenericObject * m_object;
    cVector3d m_adjustedSegmentAPoint;
    double m_squareDistance;
    cVector3d m_globalNormal;
    cVector3d m_globalPos;
    double m_posV01,m_posV02;
    cTriangles *m_triangles;

    // m_triangles
};

struct cCollisionSettings
{
    double m_collisionRadius = 1.0;
    bool m_returnMinimalCollisionData = false;
    bool m_checkForNearestCollisionOnly = true;
    bool m_ignoreShapes = false;
    bool m_checkHapticObjects = false;
    bool m_adjustObjectMotion = false;
    bool m_checkVisibleObjects = false;
};

class cCollisionRecorder
{
public:
    cCollisionSettings m_settings;
	// m_nearestCollision.clear();
	// m_nearestCollision.m_object .getGlobalRot .getGlobalPos .m_adjustedSegmentAPoint
	// m_collisions.size()
    cCollisionEvent m_nearestCollision;

    void clear();

    std::vector<cCollisionEvent> m_collisions;
};
#endif

class cWorld
{
public:
	virtual bool computeCollisionDetection(const cVector3d & p, const cVector3d & e, cCollisionRecorder &, const cCollisionSettings & ) = 0;
};

//cMatrix3d -> Eigen3x3
//cTranspose(m)
//cVector3d -> Eigen
// .zero() .setZero()
//cProject(v,v) cNormalize(v)
//cDistance
//cProjectPointOnPlane
//normalizer
//crossr
