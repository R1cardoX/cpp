#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <list>
#include <vector>

using namespace std;
class Number
{
private:
    shared_ptr<string> pNum; 
    static string Init_Zero(int n,int length)
    {
        string t = "0000000000000000000000000000000000000000";
        t.resize(length);
        string s = "";
        for(int i=0;i<n;i++)
            s += t;
        return s;
    }
    static long long To_Integer(string s)
    {
        long long l;
        stringstream stream(s);  
        stream>>l;  
        return l;
    }
    static vector<string> To_Array(string a,int length)
    {
        vector<string> vec_a((a.size()-1)/length+1);
        vec_a.back() = a.substr(0,a.size()%length);
        for(size_t i=0;i<vec_a.size()-1;i++)
        {
            int begin = (i*length)+(a.size()%length);
            vec_a[vec_a.size()-i-2] = a.substr(begin,length);    
        }
        return vec_a;
    }
    static string To_String(vector<int> lst)
    {
        string a = "";
        for(auto var:lst)
            a = a + char(var+'0'); 
        return a;
    }
    static string To_String(list<int> lst)
    {
        string a = "";
        for(auto var:lst)
            a = a + char(var+'0'); 
        return a;
    }
    static string To_String(string num)
    {
        return num;
    }
    static string To_String(long long num)
    {
        return to_string(num);
    }
public:
    Number()
    {
        shared_ptr<string> s(new string("0"));
        pNum = move(s);
    }
    template <typename T>
    Number(T str)
    {
        shared_ptr<string> s(new string(To_String(str)));
        pNum = move(s);
    }

    Number& operator=(const Number& t)
    {
        if(&t == this)
            return *this;
        pNum = t.pNum;
        return *this;
    }
    friend std::ostream & operator<<(std::ostream &out, Number &obj);
    friend std::istream & operator >> (std::istream &in, Number &obj);
    template <typename T>
    Number& operator=(T t)
    {
        shared_ptr<string> s(new string(To_String(t)));
        pNum = move(s);
        return *this;
    }
    bool operator==(Number& num) const
    {
        if(*(this->pNum) == *(num.pNum))
            return true;
        return false;
    }
    bool operator>(Number num)
    {
        if(this->pNum->size() > num.pNum->size())
            return true;
        else if(this->pNum->size() < num.pNum->size())
            return false;
        else
        {
            for(size_t i=0;i<this->pNum->size();i++)
            {
                if((*this->pNum)[i] > (*num.pNum)[i])
                    return true;
                else if((*this->pNum)[i] > (*num.pNum)[i])
                    return false;
            }
            return false;
        }
    }
    bool operator>=(Number num)
    {
        if(*this>num)
            return true;
        else if(*this==num)
            return true;
        else
            return false;
    }
    bool operator<(Number num)
    {
        if(num>(*this))
            return true;
        return false;
    }
    bool operator<=(Number num)
    {
        if(*this<num)
            return true;
        else if(*this==num)
            return true;
        else
            return false;
    }
    Number& operator+=(const Number &res)
    {
        *this = *this + res;
        return *this;
    }
    Number& operator*=(const Number &res)
    {
        *this = (*this)*(res);
        return *this;
    }
    Number operator*(const Number &a)
    {
        Number temp;
        *(temp.pNum) = Mul(*(this->pNum),*(a.pNum));
        return temp;
    }
    Number operator+(const Number &a)
    {
        Number temp;
        *(temp.pNum) = Sum(*(this->pNum),*(a.pNum));
        return temp;
    }
    static string Sum(string a,string b)
    {
        string s = "";
        if(a.size()<b.size())
            swap(a,b);
        int i,flag=0;
        for(i=0;i<(int)b.size();i++)
        {
            int num = (a[a.size()-i-1]-'0')+ (b[b.size()-i-1]-'0') + flag;
            flag = num/10;
            s = char(num%10+'0') + s;
        }
        for(;i<(int)a.size();i++)
        {
            int num = (a[a.size()-i-1]-'0') + flag;
            flag = num/10;
            s = char(num%10+'0') + s;
        }
        if(flag > 0)
            s = char(flag+'0')+s; 
        return s;
    } 
    static string Mul(string a,string b)
    {
        string s = "0";
        int length = 9;
        vector<string> vec_a =  To_Array(a,length);            
        vector<string> vec_b =  To_Array(b,length);            
        vector<string> vec(vec_a.size()*vec_b.size(),"0");
        auto ite = vec.begin();
        for(size_t i=0;i<vec_a.size();i++)
        {
            for(size_t j=0;j<vec_b.size();j++)
            {
                string base = Init_Zero(i+j,length);
                *ite = To_String((To_Integer(vec_a[i])*To_Integer(vec_b[j]))) + base;
                ite++;
            }
        }
        for(auto var:vec)
        {
            s = Sum(s,var);
        }
        return s;
    }
};

std::ostream & operator<<(std::ostream &out, Number &obj)
{
    out << *obj.pNum;
    return out;
}
std::istream & operator>>(std::istream &in, Number &obj)
{
    in >> *obj.pNum;
    return in;
}
