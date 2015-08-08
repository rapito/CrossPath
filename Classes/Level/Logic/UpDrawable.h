#pragma once
class UpDrawable
{
public:
	//virtual ~UpDrawable(){ }
	// C++ no cuenta con iterfaces persé, por lo cual
	// se hacen métodos "Pure virtual" que deben de ser heredados e implementados
	// de está forma emulamos la interfaz en C++
	virtual void update() = 0;
	virtual void render() = 0;
};

