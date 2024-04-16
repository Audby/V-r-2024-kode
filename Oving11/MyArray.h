#include <stdexcept>

//Oppgave 5)
template<typename Type, int Size>
class MyArray
{
private:
    Type elements[Size];

public:
    int getSize() const {
        return Size;
    }

    Type& at(int index) {
        if (index < 0 || index >= Size) {
            throw std::out_of_range("Index utenfor rekkevidde");
        }
        return elements[index];
    }

    void fill(const Type& value) {
        for (int i = 0; i < Size; ++i) {
            elements[i] = value;
        }
    }
};
