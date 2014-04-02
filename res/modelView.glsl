vec3 mv(vec3 v) {
	return (view * model * vec4(v, 1)).xyz;
}