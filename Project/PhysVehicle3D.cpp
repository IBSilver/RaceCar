#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Grey; //Color de ruedas

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	//Cubo central
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	chassis.color = Orangedark;

	chassis.Render();

	//Upperchassis
	Cube upperchassis(info.upperchassis_size.x, info.upperchassis_size.y, info.upperchassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&upperchassis.transform);
	btQuaternion q0 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset0(info.upperchassis_offset.x, info.upperchassis_offset.y, info.upperchassis_offset.z);
	offset0 = offset0.rotate(q0.getAxis(), q0.getAngle());

	upperchassis.transform.M[12] += offset0.getX();
	upperchassis.transform.M[13] += offset0.getY();
	upperchassis.transform.M[14] += offset0.getZ();

	upperchassis.color = Orange;

	upperchassis.Render();

	//Grua 1
	Cube grua1(info.grua1_size.x, info.grua1_size.y, info.grua1_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&grua1.transform);
	btQuaternion q1 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset1(info.grua1_offset.x, info.grua1_offset.y, info.grua1_offset.z);
	offset1 = offset1.rotate(q1.getAxis(), q1.getAngle());

	grua1.transform.M[12] += offset1.getX();
	grua1.transform.M[13] += offset1.getY();
	grua1.transform.M[14] += offset1.getZ();

	grua1.color = Yellow;

	grua1.Render();

	//Grua 2
	Cube grua2(info.grua2_size.x, info.grua2_size.y, info.grua2_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&grua2.transform);
	btQuaternion q2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset2(info.grua2_offset.x, info.grua2_offset.y, info.grua2_offset.z);
	offset2 = offset2.rotate(q2.getAxis(), q2.getAngle());

	grua2.transform.M[12] += offset2.getX();
	grua2.transform.M[13] += offset2.getY();
	grua2.transform.M[14] += offset2.getZ();

	grua2.color = Yellow;

	grua2.Render();

	//Grua 3
	Cube grua3(info.grua3_size.x, info.grua3_size.y, info.grua3_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&grua3.transform);
	btQuaternion q3 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset3(info.grua3_offset.x, info.grua3_offset.y, info.grua3_offset.z);
	offset3 = offset3.rotate(q3.getAxis(), q3.getAngle());

	grua3.transform.M[12] += offset3.getX();
	grua3.transform.M[13] += offset3.getY();
	grua3.transform.M[14] += offset3.getZ();

	grua3.color = Yellow;

	grua3.Render();

	//Grua 4
	Cube grua4(info.grua4_size.x, info.grua4_size.y, info.grua4_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&grua4.transform);
	btQuaternion q4 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset4(info.grua4_offset.x, info.grua4_offset.y, info.grua4_offset.z);
	offset4 = offset4.rotate(q4.getAxis(), q4.getAngle());

	grua4.transform.M[12] += offset4.getX();
	grua4.transform.M[13] += offset4.getY();
	grua4.transform.M[14] += offset4.getZ();

	grua4.color = Grey;

	grua4.Render();
}

vec3 PhysVehicle3D::GetForwardVector() const {
	btVector3 veh = vehicle->getForwardVector();
	vec3 vehaux;
	vehaux.Set(veh.getX(), veh.getY(), veh.getZ());
	return vehaux;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}