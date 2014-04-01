

#pragma once
#include "SceneRender.hpp"
#include "Program.hpp"
#include "GameObjectFactory.hpp"
#include "Options.hpp"
using namespace GameOptions;
using namespace Render;
using namespace Factory;
namespace Factory {
    class GameSceneBuilder
    {
    private:
        SceneRender* m_GameScene;
        Program* m_ProgramHandle;
        AsteroidArray m_Asteroids;
        Ship* m_Ship;
        GameObjectFactory* m_GameObjectFactory;
        Options m_Options;
    public:
       GameSceneBuilder(Options options);
       virtual void MakeProgramHandle();
       virtual void MakeSpaceShip();
       virtual void MakeAsteroids();
       virtual void MakeGameScene();
       virtual SceneRender* GetGameScene()const;
       virtual ~GameSceneBuilder();
    };
}