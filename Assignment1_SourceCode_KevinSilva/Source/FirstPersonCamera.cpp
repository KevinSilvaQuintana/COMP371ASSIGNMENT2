//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
//
// Copyright (c) 2014 Concordia University. All rights reserved.
//

#include "FirstPersonCamera.h"
#include "EventManager.h"
#include <GLM/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>
#include <algorithm>



using namespace glm;

//Setting initial position for camera
FirstPersonCamera::FirstPersonCamera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 upDown) : Camera()
{

	mHorizontalAngle = glm::radians(180.0f);
	mVerticalAngle = glm::radians(0.0f);

	mPosition = position;
	mLookAt = lookAt;
	mUpDown = upDown;

	mRightLeft = glm::cross(mRightLeft, mLookAt);
}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::Update(float dt)
{
	// Prevent from having the camera move only when the cursor is within the windows
	EventManager::DisableMouseCursor();


	// @TODO 3 : You need to move the Camera based on the User inputs
	// - You can access the mouse motion with EventManager::GetMouseMotionXY()
	// - For mapping A S D W, you can look in World.cpp for an example of accessing key states
	// - Don't forget to use dt to control the speed of the camera motion

	//Calculating angles
	mHorizontalAngle -= MOVE_SPEED * dt * EventManager::GetMouseMotionX();
	mVerticalAngle -= AIM_SPEED * dt * EventManager::GetMouseMotionY();

	//Update direction vectors
	mLookAt = glm::vec3(
		cos(mVerticalAngle) * sin(mHorizontalAngle),
		sin(mVerticalAngle),
		cos(mVerticalAngle) * cos(mHorizontalAngle)
		);

	mRightLeft = glm::vec3(
		sin(mHorizontalAngle - 3.14f / 2.0f),
		0,
		cos(mHorizontalAngle - 3.14f / 2.0f)
		);

	mUpDown = glm::cross(mRightLeft, mLookAt);

	// Move forward
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_W) == GLFW_PRESS){
		mPosition += mLookAt * dt * MOVE_SPEED;
	}
	// Move backward
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_S) == GLFW_PRESS){
		mPosition -= mLookAt * dt * MOVE_SPEED;
	}
	// Strafe right
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_D) == GLFW_PRESS){
		mPosition += mRightLeft * dt * MOVE_SPEED;
	}
	// Strafe left
	if (glfwGetKey(EventManager::GetWindow(), GLFW_KEY_A) == GLFW_PRESS){
		mPosition -= mRightLeft * dt * MOVE_SPEED;
	}


}

glm::mat4 FirstPersonCamera::GetViewMatrix() const
{
	// @TODO 3 : Calculate the View Matrix
	//glm::mat4 viewMatrix(1.0f);

	glm::mat4 viewMatrix = glm::lookAt(mPosition, mPosition + mLookAt, mUpDown);
	
	return viewMatrix;
}
