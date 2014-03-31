#pragma once

#include <memory>
#include <ostream>


namespace person {

class Affection;
typedef std::shared_ptr< Affection >  AffectionPtr;
typedef std::unique_ptr< Affection >  AffectionUPtr;

}




namespace person {


/**
* ������� ������������� � ����-���� (� ������-���� �������).
* ������ ������������� ��������.
* ������������� ����������, ��������� ������ �������� ������ (��������) ������
* ����������� �������, ����� "������" ��� ��������. ������� �������: "��� ���",
* "��� ������", "� ��������", "� ������ ������", "��� ��� - �����" � �.�..
*/
class Affection {
public:
    explicit inline Affection( float value = 0.0f ) : mAffection( value ) {
    }


    inline float operator()() const {
        return mAffection;
    }


    inline float& operator()() {
        return mAffection;
    }

    
    inline operator float& () {
        return mAffection;
    }



    inline Affection& operator<<( float value ) {
        ( *this ) = value;
        return *this;
    }



    /*
    template< typename T >
    inline void operator=( T value ) {
        t = static_cast< float >( value );
    }
    */


    inline Affection& operator=( float value ) {
        mAffection = value;
        return *this;
    }




private:
    /**
    * �������������� ���-�� ����� ��������� �������� � ��������� [0; +...].
    */
    float mAffection;
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::Affection& a ) {
    out << "{ \"affection\": " << a() << " }";
    return out;
}


} // std
