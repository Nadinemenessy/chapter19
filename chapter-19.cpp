#include <std_lib_facilities.h>

template<typename T> //template passes data type as a parameter so that we don’t need to write the same code for different data type
struct S  //we use struct to group the following 1 place
{
public:

    S& operator=(const T&);

    S(T NewValue) //constructor to assign a value to S(struct)
    {
        val = NewValue;
    }

    void set(T NewValue) //set function to change the val
    {
        val = NewValue;
    }

    S<T> &operator=(S<T> &value);

    T& get();
    const T& get() const;

private:
    T val;
};

template<typename T> //a function template that returns a reference to va
T& S<T>::get()
{
    return val;
}

template<typename T> //const version of get()
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this; // return self-reference
}

template<typename T> //layout for line 99
ostream& operator<<(ostream& os, vector<T>& v) //ostream is used for output
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T> //layout for the input of vector + error messaged
istream& operator>>(istream& is, vector<T>& v) //istream is used for input
{
    char ch = 0;
    is >> ch;
    if (ch != '{')
    {
        cout << "error please use '{}'" << endl;
        is.unget();
        return is;
    }

    for (T val; is >> val; )
    {
        v.push_back(val);
        is >> ch;
        if (ch != ',')
        {
            cout << "error please use ','" << endl;
            break;
        }

    }

    return is;
}

template<typename T> void read_val(T& v) //stores the value inputed in v
{
    cin >> v;
}

int main()
{
    S<int> si {5};
    S<char> sc {'A'};
    S<double> sd {3.1};
    S<string> s {"testing"};
    S<vector<int>> svi { vector<int>{1, 2, 3, 4, 5, 6}};

    cout << "S<int> : " << si.get() << '\n'
         << "S<char> : " << sc.get() << '\n'
         << "S<double> : " << sd.get() << '\n'
         << "S<string> : " << s.get() << '\n'
         << "S<vector<int>> : " << svi.get() << '\n';

    sc.set('s');
    cout << "S<char> : " << sc.get() << '\n';

    cout << "Integer: ";
    int ii;
    read_val(ii); //calls the read_val function and stores the value in ii
    S<int> si2 {ii}; //stores the value of ii in si2
    cout << "S<int> read: " << si2.get() << '\n' << '\n'; // prints the value inputed

    cout << "Char: ";
    char cc;
    read_val(cc); //calls the read_val function and stores the value in cc
    S<char> sc2 {cc}; //stores the value of cc in sc2
    cout << "S<char> read: " << sc2.get() << '\n' << '\n'; // prints the value inputed

    cout << "Double: ";
    double dd;
    read_val(dd); //calls the read_val function and stores the value in dd
    S<double> sd2 {dd}; //stores the value of dd in sd2
    cout << "S<double> read: " << sd2.get() << '\n' << '\n'; // prints the value inputed

    cout << "String: ";
    string ss;
    read_val(ss); //calls the read_val function and stores the value in ss
    S<string> s2 {ss}; //stores the value of ss in s2
    cout << "S<string> read: " << s2.get() << '\n' << '\n'; // prints the value inputed

    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> vi2;
    read_val(vi2); //calls the read_val function and stores the value in vi2
    S<vector<int>> svi2 {vi2}; //stores the value of vi2 in vi2
    cout << "S<vector<int>> read: " << svi2.get() << '\n' << '\n'; // prints the value inputed
}
