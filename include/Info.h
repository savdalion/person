#pragma once

#include <string>
#include <memory>
#include <ostream>


namespace person {

class Info;
typedef std::shared_ptr< Info >  InfoPtr;
typedef std::unique_ptr< Info >  InfoUPtr;

}



namespace boost {

// ��� ������ ��������� boost::unordered_set � ��.
size_t hash_value( const person::Info& );

} // boost




namespace person {


/**
* ���������� � ���-����.
* ������������ � ���� ������ ��������, �� ������� ������������ ����� ����
* ������� ����� ������.
* ������ �������� ����� ���� *�����*, ��� �� ��������� �� �����, �.�. Info - ���
* ������ �����. �� �� �������� ����� ���� ����� "�������", ����� �����������:
* ����� �������� ��, ��� ����� ���� ���������� ����������.
*/
class Info {
public:
    explicit inline Info( const std::string& data ) : mData( data ) {
    }



    inline std::string const& operator()() const {
        return mData;
    }


    inline std::string& operator()() {
        return mData;
    }



    inline bool operator==( const Info& b ) const {
        return (mData == b());
    }





private:
    /**
    * ���������� � ���� ������ ��������.
    */
    std::string mData;
};




} // person








namespace boost {

inline size_t hash_value( const person::Info& a ) {
    return boost::hash_value( a() );
}

} // boost






namespace std {


inline bool operator<( const person::Info& a, const person::Info& b ) {
    return (a() < b());
}



inline std::ostream& operator<<( std::ostream& out, const person::Info& info ) {
    out << "\"" << info() << "\"";
    return out;
}


} // std
