constexpr const int* addr(const int& r) { return &r; }    // OK

static const int x = 5;

constexpr const int* p1 = addr(x);       // OK

constexpr int xx = *p1;                  // OK

static int y;

constexpr const int* p2 = addr(y);       // OK

constexpr int yy = *p2;                   // error: attempt to read a variable



constexpr const int* tp = addr(5);       // error: address of temporary