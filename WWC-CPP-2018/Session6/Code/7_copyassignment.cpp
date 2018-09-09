//Copy assignment

MyVector& operator=(const MyVector& v)
{
	if(v.size ! = size)
	 throw runtime_error("bad size in Matrix =");

	for (i = 0; i < size; i++)
		elems[i] = v.elems[i];

	return *this;
}