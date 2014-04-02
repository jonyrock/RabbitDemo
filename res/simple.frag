#version 130

uniform float ambient;
uniform float diffuse;
uniform float specular;
uniform float specularPower;
uniform vec3  viewerPos;
uniform vec3  lightColor;

uniform float kc;
uniform float kl;
uniform float kq;

uniform int lightType;
uniform int fillType;


// Interpolated values from the vertex shaders
in vec3 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 color;

void main() {
    
    vec3 lightPos = (view * model * vec4(30.0f, 30.0f, 20.0f, 1)).xyz;
    lightPos = (view * vec4(lightPos,1)).xyz;
    
    vec3 N = normalize(vertexNormal);
    vec3 L = normalize(lightPos - vertexPosition);
    
    float idiff = diffuse * max(dot(N, L), 0.0f);
    
    // it is becuse viewer is the camera so it is vec3(0,0,0)
    vec3 V = normalize(-vertexPosition); 
    vec3 R = (2 * dot(N, L) * N - L);
    
    float d = length(lightPos - vertexPosition) * 1000 + 100;
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
    color.r = ires * lightColor.r * vertexColor.r;
    color.g = ires * lightColor.g * vertexColor.g;
    color.b = ires * lightColor.b * vertexColor.b;
    
    // color.r = ires;
    // color.g = ires;
    // color.b = ires;
    
    
    // color = vertexColor;
    
    // color = vertexColor * diffuse;

}