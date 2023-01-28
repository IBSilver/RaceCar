#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//aqui cramos el mapa
	
	//suelo del recorrido
	suelo1 = new Cube(50, 1, 100);
	suelo1->SetPos(0, 3, 30);
	suelo1->color = White;
	mapa.add(suelo1);
	bodiesmapa.add(App->physics->AddBody(*suelo1, 0));

	suelo2 = new Cube(30, 1, 100);
	suelo2->SetPos(0, 3, 130);
	suelo2->color = White;
	mapa.add(suelo2);
	bodiesmapa.add(App->physics->AddBody(*suelo2, 0));

	suelo3 = new Cube(120, 1, 20);
	suelo3->SetPos(-45, 3, 190);
	suelo3->color = White;
	mapa.add(suelo3);
	bodiesmapa.add(App->physics->AddBody(*suelo3, 0));

	suelo4 = new Cube(20, 1, 50);
	suelo4->SetPos(-95, 3, 155);
	suelo4->color = White;
	mapa.add(suelo4);
	bodiesmapa.add(App->physics->AddBody(*suelo4, 0));

	rampa1 = new Cube(80, 1, 20);
	rampa1->SetPos(-145, 6.5, 140);
	rampa1->SetRotation(-5.0f, { 0, 0, 0.5 });
	rampa1->color = White;
	mapa.add(rampa1);
	bodiesmapa.add(App->physics->AddBody(*rampa1, 0));

	suelo5 = new Cube(20, 1, 80);
	suelo5->SetPos(-195, 10, 170);
	suelo5->color = White;
	mapa.add(suelo5);
	bodiesmapa.add(App->physics->AddBody(*suelo5, 0));

	suelo6 = new Cube(80, 1, 20);
	suelo6->SetPos(-245, 10, 190);
	suelo6->color = White;
	mapa.add(suelo6);
	bodiesmapa.add(App->physics->AddBody(*suelo6, 0));

	suelo7 = new Cube(20, 1, 180);
	suelo7->SetPos(-275, 10, 290);
	suelo7->color = White;
	mapa.add(suelo7);
	bodiesmapa.add(App->physics->AddBody(*suelo7, 0));

	suelo8 = new Cube(180, 1, 40);
	suelo8->SetPos(-195, 10, 400);
	suelo8->color = White;
	mapa.add(suelo8);
	bodiesmapa.add(App->physics->AddBody(*suelo8, 0));

	suelo9 = new Cube(5, 1, 120);
	suelo9->SetPos(-190, 10, 270);
	suelo9->color = White;
	mapa.add(suelo9);
	bodiesmapa.add(App->physics->AddBody(*suelo9, 0));

	suelo10 = new Cube(15, 1, 5);
	suelo10->SetPos(-195, 10, 332.5);
	suelo10->color = White;
	mapa.add(suelo10);
	bodiesmapa.add(App->physics->AddBody(*suelo10, 0));

	suelo11 = new Cube(5, 1, 45);
	suelo11->SetPos(-200, 10, 357.5);
	suelo11->color = White;
	mapa.add(suelo11);
	bodiesmapa.add(App->physics->AddBody(*suelo11, 0));

	suelo12 = new Cube(120, 1, 20);
	suelo12->SetPos(-45, 10, 400);
	suelo12->color = White;
	mapa.add(suelo12);
	bodiesmapa.add(App->physics->AddBody(*suelo12, 0));

	suelo13 = new Cube(20, 1, 70);
	suelo13->SetPos(5, 10, 445);
	suelo13->color = White;
	mapa.add(suelo13);
	bodiesmapa.add(App->physics->AddBody(*suelo13, 0));

	rampa2 = new Cube(20, 1, 20);
	rampa2->SetPos(5, 10.8, 485);
	rampa2->SetRotation(-4.5f, { 0.5, 0, 0 });
	rampa2->color = White;
	mapa.add(rampa2);
	bodiesmapa.add(App->physics->AddBody(*rampa2, 0));



	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/

	rampa1->Render();
	rampa2->Render();

	suelo1->Render();
	suelo2->Render();
	suelo3->Render();
	suelo4->Render();
	suelo5->Render();
	suelo6->Render();
	suelo7->Render();
	suelo8->Render();
	suelo9->Render();
	suelo10->Render();
	suelo11->Render();
	suelo12->Render();
	suelo13->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

