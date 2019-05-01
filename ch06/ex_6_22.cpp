void swap(int *(&p1), int *(&p2)) {
	int *tmp = p2;
	p2 = p1;
	p1 = tmp; 
}