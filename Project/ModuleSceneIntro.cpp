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

	rampa3 = new Cube(20, 1, 20);
	rampa3->SetPos(5, 12.5, 500);
	rampa3->SetRotation(-7.5f, { 0.5, 0, 0 });
	rampa3->color = White;
	mapa.add(rampa3);
	bodiesmapa.add(App->physics->AddBody(*rampa3, 0));

	suelo14 = new Cube(20, 1, 70);
	suelo14->SetPos(5, 10, 570);
	suelo14->color = White;
	mapa.add(suelo14);
	bodiesmapa.add(App->physics->AddBody(*suelo14, 0));

	suelo15 = new Cube(180, 1, 20);
	suelo15->SetPos(-95, 10, 595);
	suelo15->color = White;
	mapa.add(suelo15);
	bodiesmapa.add(App->physics->AddBody(*suelo15, 0));

	suelo16 = new Cube(20, 1, 60);
	suelo16->SetPos(-195, 10, 575);
	suelo16->color = White;
	mapa.add(suelo16);
	bodiesmapa.add(App->physics->AddBody(*suelo16, 0));

	suelo17 = new Cube(80, 1, 20);
	suelo17->SetPos(-245, 10, 555);
	suelo17->color = White;
	mapa.add(suelo17);
	bodiesmapa.add(App->physics->AddBody(*suelo17, 0));

	suelo18 = new Cube(80, 1, 20);
	suelo18->SetPos(-305, 10, 575);
	suelo18->color = White;
	mapa.add(suelo18);
	bodiesmapa.add(App->physics->AddBody(*suelo18, 0));

	suelo19 = new Cube(80, 1, 40);
	suelo19->SetPos(-385, 10, 575);
	suelo19->color = White;
	mapa.add(suelo19);
	bodiesmapa.add(App->physics->AddBody(*suelo19, 0));

	rampa4 = new Cube(20, 1, 200);
	rampa4->SetPos(-385, 29, 470);
	rampa4->SetRotation(11.0f, { 0.5, 0, 0 });
	rampa4->color = White;
	mapa.add(rampa4);
	bodiesmapa.add(App->physics->AddBody(*rampa4, 0));

	suelofinal = new Cube(100, 1, 100);
	suelofinal->SetPos(-385, 48, 322);
	suelofinal->color = White;
	mapa.add(suelofinal);
	bodiesmapa.add(App->physics->AddBody(*suelofinal, 0));



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
	rampa3->Render();
	rampa4->Render();

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
	suelo14->Render();
	suelo14->Render();
	suelo15->Render();
	suelo16->Render();
	suelo17->Render();
	suelo18->Render();
	suelo19->Render();
	suelofinal->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

