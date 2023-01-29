#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;


	p2List<PhysBody3D*> bodiesmapa;
	p2List<Cube*> mapa;

	//Suelos
	Cube* suelo1;
	Cube* suelo2;
	Cube* suelo3;
	Cube* suelo4;
	Cube* suelo5;
	Cube* suelo6;
	Cube* suelo7;
	Cube* suelo8;
	Cube* suelo9;
	Cube* suelo10;
	Cube* suelo11;
	Cube* suelo12;
	Cube* suelo13;
	Cube* suelo14;
	Cube* suelo15;
	Cube* suelo16;
	Cube* suelo17;
	Cube* suelo18;
	Cube* suelo19;
	Cube* suelofinal;

	//Obstaculos
	Cube* pilar1;
	Cube* pilar2;
	Cube* pilar3;
	Cube* pilar4;
	Cube* pilar5;
	Cube* pilar6;
	Cube* pilar7;
	Cube* pilar8;
	Cube* pilar9;
	Cube* pilar10;
	Cube* pilar11;
	Cube* pilar12;
	Cube* pilar13;
	Cube* pilar14;
	Cube* pilar15;


	//Rampas
	Cube* rampa1;
	Cube* rampa2;
	Cube* rampa3;
	Cube* rampa4;

};
