//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
//
// Copyright (c) 2014 Concordia University. All rights reserved.
//

#pragma once

#include "Model.h"

class SphereModel : public Model
{
public:
	SphereModel(glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f));
	// @TODO 4 - It could be a good idea to allow passing a parent model in the constructor
	SphereModel(Model * parent, bool scaleParent = true, glm::vec3 size = glm::vec3(1.0f, 1.0f, 1.0f));
	virtual ~SphereModel();

	virtual void generateBuffer(glm::vec3 size);
	virtual void Update(float dt);
	virtual void Draw();

protected:
	virtual bool ParseLine(const std::vector<ci_string> &token);

private:
	// The vertex format could be different for different types of models
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 color;
	};

	unsigned int mVertexArrayID;
	unsigned int mVertexBufferID;

	//Adding num vertices for sphere
	unsigned int numVertices;
};
