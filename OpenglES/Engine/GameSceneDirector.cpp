//
//  GameSceneDirector.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 20.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "GameSceneDirector.hpp"

using namespace Factory;

GameSceneDirector::GameSceneDirector(GameSceneBuilder* builder):m_SceneBuilder(builder)
{
    
}

void GameSceneDirector::BuildScene()
{
    m_SceneBuilder->MakeProgramHandle();
    m_SceneBuilder->MakeSpaceShip();
    m_SceneBuilder->MakeAsteroids();
    m_SceneBuilder->MakeGameScene();
}

SceneRender* GameSceneDirector::GetGameScene()const
{
    return m_SceneBuilder->GetGameScene();
}