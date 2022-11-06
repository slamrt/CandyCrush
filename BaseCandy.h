#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Win10.h"
class BaseCandy
{
protected:
public:
	BaseCandy() {}
	virtual char getImage() const = 0;
	virtual int getColor() const = 0;
	~BaseCandy() {}
};

class BananaCandy : public virtual BaseCandy {
protected:
	char Image;
	int Color;
public:
	BananaCandy():Image('%'), Color(CREATE_COLOR(COLOR::black, COLOR::yellow)) {}
	~BananaCandy() {}
	virtual char getImage() const { return Image; }
	virtual int getColor() const { return Color; }
};

class AppleCandy : public virtual BaseCandy {
protected:
	char Image;
	int Color;
public:
	AppleCandy() :Image('@'), Color(CREATE_COLOR(COLOR::black, COLOR::red)) {}
	~AppleCandy() {}
	virtual char getImage() const { return Image; }
	virtual int getColor() const { return Color; }
};

class GrapeCandy : public virtual BaseCandy {
protected:
	char Image;
	int Color;
public:
	GrapeCandy() :Image('&'), Color(CREATE_COLOR(COLOR::black, COLOR::purple)) {}
	~GrapeCandy() {}
	virtual char getImage() const { return Image; }
	virtual int getColor() const { return Color; }
};

class PlumCandy : public virtual BaseCandy {
protected:
	char Image;
	int Color;
public:
	PlumCandy() :Image('*'), Color(CREATE_COLOR(COLOR::black, COLOR::blue)) {}
	~PlumCandy() {}
	virtual char getImage() const { return Image; }
	virtual int getColor() const { return Color; }
};

class PearCandy : public virtual BaseCandy {
protected:
	char Image;
	int Color;
public:
	PearCandy() :Image('^'), Color(CREATE_COLOR(COLOR::black, COLOR::green)) {}
	~PearCandy() {}
	virtual char getImage() const { return Image; }
	virtual int getColor() const { return Color; }
};