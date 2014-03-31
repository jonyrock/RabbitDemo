#pragma once

enum LightType {
	LT_PHONG,
	LT_BLINN_PHONG
};

enum FillType {
	FT_FLAT,
	FT_PER_VERTEX,
	FT_PER_FRAGMENT
};

struct Settings {
	float ambient;
	float diffuse;
	float specular;
	float specularPower;
	LightType lightType;
	FillType fillType;
	
	float bgColor[3];
	
	Settings() {
		ambient = 0.5;
		diffuse = 0.5;
		specular = 1.0;
		specularPower = 1.5;
		lightType = LT_PHONG;
		fillType = FT_FLAT;
		
		bgColor[0] = 0.1f; 
		bgColor[1] = 0.2f;
		bgColor[2] = 0.4f;
	}
};

