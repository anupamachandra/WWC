struct CStash{
	int size;
	int quantity;
	int next;
	unsigned char* storage;	
}

void initialize(CStash* s, int size);
void cleanup(CStash* s);
void* fetch(CStash* s, int index);
int count(CStash*s);
void inflate(CStash* s, int increase);

