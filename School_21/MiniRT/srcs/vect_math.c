#include "../includes/MiniRT.h"

t_vector	*sum_vect(t_vector *a, t_vector *b)
{
	return (new_vector(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vector	*sub_vect(t_vector *a, t_vector *b)
{
	return (new_vector(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vector	*mult_vect(t_vector *a, float b)
{
	return (new_vector(a->x * b, a->y * b, a->z * b));
}

float		dot_vect(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float		length_vect(t_vector *a)
{
	return (sqrt(dot_vect(a, a)));
}

t_vector	*normalize_vect(t_vector *vect)
{
	float len;

	len = length_vect(vect);
	return (new_vector(vect->x / len, vect->y / len, vect->z / len));
}
