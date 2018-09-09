MyVector(const MyVector& other) :size(other.size)
{
	elems = new int[size];
	for (int i = 0; i < size; i++)
		elems[i] = other.elems[i];
}

void swap(MyVector& other)
{
	std::swap(elems, other.elems);
	std::swap(size, others,size);
	//MyVector temp(other);
	//other = *this;
	//*this = temp;
}

MyVector(MyVector&& other) : size(0), elems(nullptr)
{
	swap(other);
}

~MyVector
{
	delete[] elems;
}