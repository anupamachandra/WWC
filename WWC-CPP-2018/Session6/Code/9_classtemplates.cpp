template <typename T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};

mypair<int> myobject{115, 36};
mypair<double> myfloats{3.0, 2.18}; 