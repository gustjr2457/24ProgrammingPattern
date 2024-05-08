#pragma once

class MObject
{
public:
	MObject();
	~MObject();

	virtual void update();
	virtual void render();
	virtual void render(double rad);

};