#include <iostream>
using namespace std;
//Napisz klasę szablonową Pair, która przechowuje parę wartości dwóch dowolnych typów i umozliwia dostęp do tych wartości

template<typename N, typename M>
class Pair
{
public:
    Pair(N key, M value) : m_Key(key), m_Value(value) {};

    N GetKey()
    {
        return m_Key;
    }

    M GetValue()
    {
        return m_Value;
    }

    void SetKey(N key)
    {
        m_Key = key;
    }
    void SetValue(M value)
    {
        m_Value = value;
    }
private:
    N m_Key;
    M m_Value;
};




int main()
{
    Pair<int, float> para(10, 5.3);
    cout << para.GetKey() << " " << para.GetValue() << endl;
    para.SetKey(210);
    para.SetValue(666);
    cout << para.GetKey() << " " << para.GetValue();
    return 0;
}
