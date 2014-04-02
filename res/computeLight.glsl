#include "res/modelView.glsl"

uniform float ambient;
uniform float diffuse;
uniform float specular;
uniform float specularPower;
uniform vec3  viewerPosition;
uniform vec3  lightColor;
uniform vec3  lightPosition;

uniform float kc;
uniform float kl;
uniform float kq;

uniform int lightType;

vec3 computeLight(vec3 color, vec3 position, vec3 normal) {	
	vec3 res;
	vec3 N = normalize(vertexNormal);
    vec3 L = normalize(lightPosition - position);
    float idiff = diffuse * max(dot(N, L), 0.0f);
    vec3 V = normalize(viewerPosition - position); 
    vec3 R = (2 * dot(N, L) * N - L);
    float d = length(lightPosition - position) * 1000 + 100;
    float intensity = 1.0f / (kc + kl * d + kq * d * d);
    // float intensity = 1.0f;
    float ispec = 0;
    // if blinn
    if(lightType == 1) {
	    ispec = specular * pow(
	    			dot(normalize(R), normalize(V)), 
	    			specularPower
	    		);
    } else {
    	vec3 H = normalize(L + V);
        ispec = max(specular * pow(dot(H, N), specularPower), 0);
    }
    if(dot(L, N) < 0) {
		ispec = 0;
	}
    float ires = ambient + idiff + ispec;
    res.r = ires * lightColor.r * color.r;
    res.g = ires * lightColor.g * color.g;
    res.b = ires * lightColor.b * color.b;
    return res;
}