

bool dins(Cercle c, Punt p) {
	
	float distancia_al_cercle = sqr(p.x - c.c.x) + sqr(p.y - c.c.y)
	return distancia_al_cercle <= sqr(c.r);
}


Rectangle bounding_box(Cercle c) {

	Punt sd = {c.c.x + c.r, c.c.y + c.r};
	Punt ie = {c.c.x - c.r, c.c.y - c.r};

	Rectangle r = {sd, ie};

	return r;
}


void traslacio(Rectangle& r, double dx, double dy) {

	r.sd.x += dx;
	r.ie.x += dx;

	r.sd.y += dy;
	r.ie.y += dy;
}


// Retorna un numero real aleatori entre a y b
double random_double(double a, double b) {
	return a + rand() / double(RAND_MAX) * (b-a);
}


Punt aleatori(Rectangle r) {

	double x = random_double(r.ie.x, r.sd.x);
	double y = random_double(r.ie.y, r.sd.y);

	Punt p = {x, y};

	return p;
}


Punt dins(Cercle c) {

	Rectangle r = bounding_box(c);
	Punt p = aletori(r);

	if (dins(c, p)) {
		return p;
	}
	else {
		return dins(c);
	}
}


Rectangle rectangle_contenidor(const Cercles& v_cercles) {

	Rectangle r = bounding_box(v_cercles[0]);

	for (int i = 1; i < v_cercles.size(); i++) {

		if (v_cercles[i].c.x + v_cercles[i].r > r.sd.x)
			r.sd.x = v_cercles[i].c.x + v_cercles[i].r;

		if(...) {

		}

		...

	}

}