///Вычисление параллельного сопротивления для 3х сопротивлений
float parallelR(float r1, float r2, float r3)
{
	float R;
	R = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
	return R;
}
