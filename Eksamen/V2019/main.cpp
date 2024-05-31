#include "std_lib_facilities.h"
#include "Vector.h"


int main() {
    
    cout << "Hello world!" << endl;

    Vector2d vec1{1,2};
    Vector2d vec2{2,3};
    Vector2d vec3{4,5};

    std::vector<Vector2d> vectors = {vec1, vec2, vec3};
    Vector2d sum = vectorSum(vectors);

    cout << sum << '\n';
    cout << vec1;
    
    return 0;
}