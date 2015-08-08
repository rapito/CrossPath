#pragma once
class UpDrawable
{
public:
	//virtual ~UpDrawable(){ }
	// C++ no cuenta con iterfaces pers�, por lo cual
	// se hacen m�todos "Pure virtual" que deben de ser heredados e implementados
	// de est� forma emulamos la interfaz en C++
	virtual void update() = 0;
	virtual void render() = 0;
};

