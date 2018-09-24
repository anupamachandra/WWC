struct B0 {
     void f(int) const;
     virtual void g(double);
};

struct B1 : B0 { /* ... */ };
struct B2 : B1 { /* ... */ };
struct B3 : B2 { /* ... */ };
struct B4 : B3 { /* ... */ };
struct B5 : B4 { /* ... */ };

struct D : B5 {
     void f(int) const;         // override f() in base class
     void g(int);               // override g() in base class
     virtual int h();           // override h() in base class
};