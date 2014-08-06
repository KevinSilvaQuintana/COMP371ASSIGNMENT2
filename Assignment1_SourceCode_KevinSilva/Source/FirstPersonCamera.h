//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
//
// Copyright (c) 2014 Concordia University. All rights reserved.
//

#pragma once

#include "Camera.h"

class FirstPersonCamera : public Camera
{
public:
	FirstPersonCamera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 upDown);
	virtual ~FirstPersonCamera();

	virtual void Update(float dt);

	virtual glm::mat4 GetViewMatrix() const;

private:
	// @TODO 3 - Add every parameter you need for a first person camera
	//           including the speed of the camera

	glm::vec3 mPosition;
	glm::vec3 mLookAt;
	glm::vec3 mRightLeft;
	glm::vec3 mUpDown;


	float const MOVE_SPEED = 2.0f;
	float const AIM_SPEED = 2.0f;

	double mVerticalAngle;
	double mHorizontalAngle;

};
