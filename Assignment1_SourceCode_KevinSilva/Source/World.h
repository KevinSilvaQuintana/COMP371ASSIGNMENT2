//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
//
// Copyright (c) 2014 Concordia University. All rights reserved.
//

#pragma once

#include <vector>
#include <glm/glm.hpp>

class Camera;
class Model;

class World
{
public:
	World();
	~World();
	
	void Update(float dt);
	void Draw();

	void LoadScene(const char * scene_path);

private:
	std::vector<Model*> mModel;

	std::vector<Camera*> mCamera;
	unsigned int mCurrentCamera;

	//Adding light properties from assignment 2
	float ka;
	float kd;
	float ks;
	float n;

	float lightKc;
	float lightKl;
	float lightKq;

	glm::vec3 lightColor;
	glm::vec4 lightPosition;
};
