//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
//
// Copyright (c) 2014 Concordia University. All rights reserved.
//

#include "VehicleModel.h"
#include "CubeModel.h"


using namespace std;
using namespace glm;

VehicleModel::VehicleModel()
{
	// @TODO 5 - Layout your vehicle in a hierarchy
	CubeModel * mChassis = new CubeModel(this);

	CubeModel * mCarRoof = new CubeModel(mChassis);
	CubeModel * mTire1 = new CubeModel(mChassis, false);
	CubeModel * mTire2 = new CubeModel(mChassis, false);
	CubeModel * mTire3 = new CubeModel(mChassis, false);
	CubeModel * mTire4 = new CubeModel(mChassis, false);
	CubeModel * mPoliceLights = new CubeModel(mCarRoof);
	CubeModel * mPillar1 = new CubeModel(mCarRoof);
	CubeModel * mPillar2 = new CubeModel(mCarRoof);
	CubeModel * mPillar3 = new CubeModel(mCarRoof);
	CubeModel * mPillar4 = new CubeModel(mCarRoof);

	mVehicleParts.push_back(mChassis);
	mVehicleParts.push_back(mCarRoof);
	mVehicleParts.push_back(mTire1);
	mVehicleParts.push_back(mTire2);
	mVehicleParts.push_back(mTire3);
	mVehicleParts.push_back(mTire4);
	mVehicleParts.push_back(mPoliceLights);
	mVehicleParts.push_back(mPillar1);
	mVehicleParts.push_back(mPillar2);
	mVehicleParts.push_back(mPillar3);
	mVehicleParts.push_back(mPillar4);

	mRotatingTires.push_back(mTire1);
	mRotatingTires.push_back(mTire2);
	mRotatingTires.push_back(mTire3);
	mRotatingTires.push_back(mTire4);

	//Scaling and Positioning
	mChassis->SetPosition(glm::vec3(0.0f, 1.0f, 0.75f));
	mChassis->SetScaling(glm::vec3(2.0f, 0.5f, 1.0f));

	mCarRoof->SetPosition(glm::vec3(0.0f, 1.25f, 0.0f));
	mCarRoof->SetScaling(glm::vec3(0.5f, 0.10f, 1.0f));

	mTire1->SetPosition(glm::vec3(-0.5f, -0.25f, 0.6f));
	mTire1->SetScaling(glm::vec3(0.4f, 0.4f, 0.15f));

	mTire2->SetPosition(glm::vec3(-0.5f, -0.25f, -0.6f));
	mTire2->SetScaling(glm::vec3(0.4f, 0.4f, 0.15f));

	mTire3->SetPosition(glm::vec3(0.5f, -0.25f, 0.6f));
	mTire3->SetScaling(glm::vec3(0.4f, 0.4f, 0.15f));
	
	mTire4->SetPosition(glm::vec3(0.5f, -0.25f, -0.6f));
	mTire4->SetScaling(glm::vec3(0.4f, 0.4f, 0.15f));

	mPoliceLights->SetPosition(glm::vec3(-0.2f, 1.0f, 0.0f));
	mPoliceLights->SetScaling(glm::vec3(0.2f, 3.0f, 0.75f));

	mPillar1->SetPosition(glm::vec3(-0.45f, -5.0f, 0.4f));
	mPillar1->SetScaling(glm::vec3(0.1f, 10.0f, 0.1f));

	mPillar2->SetPosition(glm::vec3(-0.45f, -5.0f, -0.4f));
	mPillar2->SetScaling(glm::vec3(0.1f, 10.0f, 0.1f));

	mPillar3->SetPosition(glm::vec3(0.45f, -5.0f, 0.4f));
	mPillar3->SetScaling(glm::vec3(0.1f, 10.0f, 0.1f));

	mPillar4->SetPosition(glm::vec3(0.45f, -5.0f, -0.4f));
	mPillar4->SetScaling(glm::vec3(0.1f, 10.0f, 0.1f));
}

VehicleModel::~VehicleModel()
{
	for each (CubeModel * part in mVehicleParts)
	{
		delete part;
	}
}

void VehicleModel::Update(float dt)
{	
	// @TODO 6 (Optional) - Here is where you can add some code if you want your vehicle to animate

	glm::vec3 xAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 yAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 zAxis = glm::vec3(0.0f, 0.0f, 1.0f);

	for each (CubeModel * tire in mRotatingTires)
	{
		tire->SetRotation(zAxis, tire->GetRotationAngle() + 540 * dt);
	}

}

void VehicleModel::Draw()
{
	// @TODO 5 - Draw Each part of your vehicle here
	for each (CubeModel* part in mVehicleParts)
	{
		part -> Draw();
	}
}

bool VehicleModel::ParseLine(const std::vector<ci_string> &token)
{
	if (token.empty())
	{
		return true;
	}
	else
	{
		return Model::ParseLine(token);
	}
}
