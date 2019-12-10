
#include<algorithm>
namespace N {

struct A {};
/*void swap(A a, A b)
{

}*/

}  // namespace N

int main()
{
    using namespace std;
    using N::A;
    A a;
    A b;
    swap(a, b);
}