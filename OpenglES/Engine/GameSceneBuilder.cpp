//
//  GameSceneBuilder.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 19.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "GameSceneBuilder.hpp"
#include "ShipRender.hpp"
#include "Asteroid.hpp"
#include "VertexFactory.hpp"
#include "Exception.hpp"
#include "ProgramFactory.hpp"


using namespace Render;

GameSceneBuilder::GameSceneBuilder(Options options):m_Options(options)
{
}

void GameSceneBuilder::MakeProgramHandle()
{
    ApplicationProgram* appProgram = ApplicationProgram::ProgramContainer();
    Program* defaultProgram = ProgramFactory::CreateProgram(TypeShaderBlock::Textured);
    appProgram->AddProgram(defaultProgram);
    appProgram->Attach(TypeShaderBlock::Textured);
    appProgram->Update();
    m_ProgramHandle = appProgram->GetActiveProgram();
    m_GameObjectFactory = new GameObjectFactory(m_ProgramHandle,m_Options);
}

void GameSceneBuilder::MakeSpaceShip()
{
    m_Ship = m_GameObjectFactory->CreateShip();
}
void GameSceneBuilder::MakeAsteroids()
{
    m_Asteroids = m_GameObjectFactory->CreateAsteroids();
}

void GameSceneBuilder::MakeGameScene()
{
    m_GameScene = new SceneRender(m_Ship,m_Asteroids,m_ProgramHandle,m_Options);
}

SceneRender* GameSceneBuilder::GetGameScene()const
{
    return m_GameScene;
}

GameSceneBuilder::~GameSceneBuilder()
{
    delete m_GameObjectFactory;
}

