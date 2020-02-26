#pragma once


#include <SDL.h>
#include <box2d/box2d.h>

#include "Application.h"

#include "../Input/InputCoreTypes.h"
#include "../Input/InputComponent.h"
#include "../../Game/Actors/PlayerController.h"

#include <stdio.h>

int main(int argc, char* args[])
{
	// Initialize main application (window)
	auto* App = new Application();

	if (!App || !App->Initialize())
	{
		printf("Failed to create application!");
		return 0;
	}

	// Initialize general input component
	auto* InputComponent = new CInputComponent();
	if(!InputComponent->Initialize())
	{
		printf("Failed to initialize input component!");
		App->Quit();
	}

	// Initialize key mappings
	EKeys::Initialize();

	// DEBUG: Init player
	auto* PC = new APlayerController();
	if(!PC)
	{
		printf_s("Failed to instance playercontroller!");
	}
	else
	{
		PC->SetupPlayerInputs(InputComponent);
	}
	// END DEBUG

	while (App->IsRunning())
	{
		SDL_Event Event;
		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_QUIT)
			{
				App->Quit();
			}
			
			InputComponent->HandleInputEvents(Event);
		}
	}

	// Close and free internal resources
	App->Close();

	// Free raw resources
	delete PC;
	delete InputComponent;
	delete App;

	return 0;
}

void testPhys()
{
	// Create physics world
	b2Vec2 gravity(0.0f, -10.0f);
	b2World* world = new b2World(gravity);

	// Step 1
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.f);

	// Step 2 Create the body
	b2Body* groundBody = world->CreateBody(&groundBodyDef);

	// Step 3 Shape definition
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.f, 10.f);

	// Step 4 Create the fixture on the body
	groundBody->CreateFixture(&groundBox, 0.0f);


	// Create dynamic body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

	float physicsTimestep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	double runTime = 10;

	while (runTime > 0)
	{
		world->Step(physicsTimestep, velocityIterations, positionIterations);

		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();

		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
		runTime -= 0.01;
	}

	delete world;
}