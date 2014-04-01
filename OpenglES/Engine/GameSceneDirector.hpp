
#pragma once
#include "GameSceneBuilder.hpp"
namespace Factory {
    class GameSceneDirector
    {
        GameSceneBuilder* m_SceneBuilder;
    public:
        GameSceneDirector(GameSceneBuilder* builder);
        void BuildScene();
        SceneRender* GetGameScene()const;
        virtual ~GameSceneDirector(){};
    };
}