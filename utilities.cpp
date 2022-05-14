namespace utils {
	void vtr::print (int tabs) {
		for (int i = 0; i < tabs; i++) printf("\t");
		printf("X : %g\n", x);
		for (int i = 0; i < tabs; i++) printf("\t");
		printf("Y : %g\n", y);
	}

	void vtr::zero () {
		x, y = 0.0;
	}

	void planet::print () {
		printf("Position:\n");
		position.print(1);
		printf("Velocity:\n");
		velocity.print(1);
		printf("Recent Acceleration:\n");
		acclrton.print(1);
	}
}
