#pragma once

typedef struct vec3_t {
	float x, y, z;
} vec3_t;

vec3_t vec3_new(float x, float y, float z) {
	vec3_t v = { x, y, z };
	return v;
}

vec3_t vec3_plus(vec3_t a, vec3_t b) {
	vec3_t v = { a.x + b.x, a.y + b.y, a.z + b.z };
	return v;
}

float vec3_scal(vec3_t a, vec3_t b) {
	float f = { a.x * b.x + a.y * b.y + a.z * b.z };
	return f;
}
