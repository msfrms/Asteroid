

#pragma once
#include "GameObjectRender.hpp"
#include "IGeometry.hpp"


using namespace Core;
namespace Render {
    class Asteroid;
    typedef  vector<Asteroid*> AsteroidArray;
    class Asteroid :public GameObjectRender
    {
    private:
        AsteroidArray m_FragmentsOfAsteroid;
    public:
        
        
        Asteroid(Program* handle);
        Asteroid(Program* handle,VertexObject* vertex);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Initialized(uint width,uint height);
        virtual void Move(Vector2 pos);
        virtual void AddFragmentToAsteroid(Asteroid* fragment);
        virtual void RemoveFragmentFromAsteroid(Asteroid* fragment);
        virtual void RemoveAllFragmentFromAsteroid();
        virtual void GenerateContact(GameObject* object); 
        virtual TypeGameObject Type()const;
        virtual bool IsCollideObject(GameObject* object);
        AsteroidArray GetFragmentsOfAsteroid()const;
        virtual bool IsDrawable()const;
        virtual void SetTexture(Texture* texture);
        virtual ~Asteroid();
    

    };
    
}
