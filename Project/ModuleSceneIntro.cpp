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

	//Aquí creamos el mapa
	//Suelo del recorrido
	suelo1 = new Cube(50, 1, 100);
	suelo1->SetPos(0, 13, 30);
	suelo1->color = White;
	mapa.add(suelo1);
	bodiesmapa.add(App->physics->AddBody(*suelo1, 0));

	suelo2 = new Cube(30, 1, 100);
	suelo2->SetPos(0, 13, 130);
	suelo2->color = White;
	mapa.add(suelo2);
	bodiesmapa.add(App->physics->AddBody(*suelo2, 0));

	suelo3 = new Cube(120, 1, 20);
	suelo3->SetPos(-45, 13, 190);
	suelo3->color = White;
	mapa.add(suelo3);
	bodiesmapa.add(App->physics->AddBody(*suelo3, 0));

	suelo4 = new Cube(20, 1, 50);
	suelo4->SetPos(-95, 13, 155);
	suelo4->color = White;
	mapa.add(suelo4);
	bodiesmapa.add(App->physics->AddBody(*suelo4, 0));

	rampa1 = new Cube(80, 1, 20);
	rampa1->SetPos(-145, 16.5, 140);
	rampa1->SetRotation(-5.0f, { 0, 0, 0.5 });
	rampa1->color = White;
	mapa.add(rampa1);
	bodiesmapa.add(App->physics->AddBody(*rampa1, 0));

	suelo5 = new Cube(20, 1, 80);
	suelo5->SetPos(-195, 20, 170);
	suelo5->color = White;
	mapa.add(suelo5);
	bodiesmapa.add(App->physics->AddBody(*suelo5, 0));

	suelo6 = new Cube(80, 1, 20);
	suelo6->SetPos(-245, 20, 190);
	suelo6->color = White;
	mapa.add(suelo6);
	bodiesmapa.add(App->physics->AddBody(*suelo6, 0));

	suelo7 = new Cube(20, 1, 180);
	suelo7->SetPos(-275, 20, 290);
	suelo7->color = White;
	mapa.add(suelo7);
	bodiesmapa.add(App->physics->AddBody(*suelo7, 0));

	suelo8 = new Cube(180, 1, 40);
	suelo8->SetPos(-195, 20, 400);
	suelo8->color = White;
	mapa.add(suelo8);
	bodiesmapa.add(App->physics->AddBody(*suelo8, 0));

	suelo9 = new Cube(5, 1, 120);
	suelo9->SetPos(-190, 20, 270);
	suelo9->color = White;
	mapa.add(suelo9);
	bodiesmapa.add(App->physics->AddBody(*suelo9, 0));

	suelo10 = new Cube(15, 1, 5);
	suelo10->SetPos(-195, 20, 332.5);
	suelo10->color = White;
	mapa.add(suelo10);
	bodiesmapa.add(App->physics->AddBody(*suelo10, 0));

	suelo11 = new Cube(5, 1, 45);
	suelo11->SetPos(-200, 20, 357.5);
	suelo11->color = White;
	mapa.add(suelo11);
	bodiesmapa.add(App->physics->AddBody(*suelo11, 0));

	suelo12 = new Cube(120, 1, 20);
	suelo12->SetPos(-45, 20, 400);
	suelo12->color = White;
	mapa.add(suelo12);
	bodiesmapa.add(App->physics->AddBody(*suelo12, 0));

	suelo13 = new Cube(20, 1, 70);
	suelo13->SetPos(5, 20, 445);
	suelo13->color = White;
	mapa.add(suelo13);
	bodiesmapa.add(App->physics->AddBody(*suelo13, 0));

	rampa2 = new Cube(20, 1, 20);
	rampa2->SetPos(5, 20.8, 485);
	rampa2->SetRotation(-4.5f, { 0.5, 0, 0 });
	rampa2->color = White;
	mapa.add(rampa2);
	bodiesmapa.add(App->physics->AddBody(*rampa2, 0));

	rampa3 = new Cube(20, 1, 20);
	rampa3->SetPos(5, 22.5, 500);
	rampa3->SetRotation(-7.5f, { 0.5, 0, 0 });
	rampa3->color = White;
	mapa.add(rampa3);
	bodiesmapa.add(App->physics->AddBody(*rampa3, 0));

	suelo14 = new Cube(20, 1, 70);
	suelo14->SetPos(5, 20, 570);
	suelo14->color = White;
	mapa.add(suelo14);
	bodiesmapa.add(App->physics->AddBody(*suelo14, 0));

	suelo15 = new Cube(180, 1, 20);
	suelo15->SetPos(-95, 20, 595);
	suelo15->color = White;
	mapa.add(suelo15);
	bodiesmapa.add(App->physics->AddBody(*suelo15, 0));

	suelo16 = new Cube(20, 1, 60);
	suelo16->SetPos(-195, 20, 575);
	suelo16->color = White;
	mapa.add(suelo16);
	bodiesmapa.add(App->physics->AddBody(*suelo16, 0));

	suelo17 = new Cube(80, 1, 20);
	suelo17->SetPos(-245, 20, 555);
	suelo17->color = White;
	mapa.add(suelo17);
	bodiesmapa.add(App->physics->AddBody(*suelo17, 0));

	suelo18 = new Cube(80, 1, 20);
	suelo18->SetPos(-305, 20, 575);
	suelo18->color = White;
	mapa.add(suelo18);
	bodiesmapa.add(App->physics->AddBody(*suelo18, 0));

	suelo19 = new Cube(80, 1, 40);
	suelo19->SetPos(-385, 20, 575);
	suelo19->color = White;
	mapa.add(suelo19);
	bodiesmapa.add(App->physics->AddBody(*suelo19, 0));

	rampa4 = new Cube(20, 1, 200);
	rampa4->SetPos(-385, 39, 470);
	rampa4->SetRotation(11.0f, { 0.5, 0, 0 });
	rampa4->color = White;
	mapa.add(rampa4);
	bodiesmapa.add(App->physics->AddBody(*rampa4, 0));

	suelofinal = new Cube(100, 1, 100);
	suelofinal->SetPos(-385, 58, 322);
	suelofinal->color = White;
	mapa.add(suelofinal);
	bodiesmapa.add(App->physics->AddBody(*suelofinal, 0));

	pilar1 = new Cube(10, 10, 2);
	pilar1->SetPos(-270, 25.5, 240);
	pilar1->color = Red;
	mapa.add(pilar1);
	bodiesmapa.add(App->physics->AddBody(*pilar1, 0));

	pilar2 = new Cube(10, 10, 2);
	pilar2->SetPos(-280, 25.5, 260);
	pilar2->color = Red;
	mapa.add(pilar2);
	bodiesmapa.add(App->physics->AddBody(*pilar2, 0));

	pilar3 = new Cube(10, 10, 2);
	pilar3->SetPos(-270, 25.5, 300);
	pilar3->color = Red;
	mapa.add(pilar3);
	bodiesmapa.add(App->physics->AddBody(*pilar3, 0));

	pilar4 = new Cube(10, 10, 2);
	pilar4->SetPos(-280, 25.5, 320);
	pilar4->color = Red;
	mapa.add(pilar4);
	bodiesmapa.add(App->physics->AddBody(*pilar4, 0));

	pilar5 = new Cube(3, 10, 3);
	pilar5->SetPos(-240, 25.5, 390);
	pilar5->color = Red;
	mapa.add(pilar5);
	bodiesmapa.add(App->physics->AddBody(*pilar5, 0));

	pilar6 = new Cube(3, 10, 3);
	pilar6->SetPos(-238, 25.5, 410);
	pilar6->color = Red;
	mapa.add(pilar6);
	bodiesmapa.add(App->physics->AddBody(*pilar6, 0));

	pilar7 = new Cube(3, 10, 3);
	pilar7->SetPos(-234, 25.5, 401);
	pilar7->color = Red;
	mapa.add(pilar7);
	bodiesmapa.add(App->physics->AddBody(*pilar7, 0));

	pilar8 = new Cube(3, 10, 3);
	pilar8->SetPos(-230, 25.5, 393);
	pilar8->color = Red;
	mapa.add(pilar8);
	bodiesmapa.add(App->physics->AddBody(*pilar8, 0));

	pilar9 = new Cube(3, 10, 3);
	pilar9->SetPos(-220, 25.5, 399);
	pilar9->color = Red;
	mapa.add(pilar9);
	bodiesmapa.add(App->physics->AddBody(*pilar9, 0));

	pilar10 = new Cube(3, 10, 3);
	pilar10->SetPos(-210, 25.5, 415);
	pilar10->color = Red;
	mapa.add(pilar10);
	bodiesmapa.add(App->physics->AddBody(*pilar10, 0));

	pilar11 = new Cube(3, 10, 3);
	pilar11->SetPos(-208, 25.5, 385);
	pilar11->color = Red;
	mapa.add(pilar11);
	bodiesmapa.add(App->physics->AddBody(*pilar11, 0));

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

	pilar1->Render();
	pilar2->Render();
	pilar3->Render();
	pilar4->Render();
	pilar5->Render();
	pilar6->Render();
	pilar7->Render();
	pilar8->Render();
	pilar9->Render();
	pilar10->Render();
	pilar11->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

