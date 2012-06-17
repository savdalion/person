#pragma once

#include <memory>
#include <ostream>


namespace person {

class Like;
typedef std::shared_ptr< Like >  LikePtr;
typedef std::unique_ptr< Like >  LikeUPtr;

}




namespace person {


/**
* ������� ��������� � ����-���� � ���� �����. ��� �����. ��������.
*/
class Like {
public:
    explicit inline Like( float value = 0.0f ) : mLike( value ) {
    }


    inline float operator()() const {
        return mLike;
    }


    inline float& operator()() {
        return mLike;
    }



    inline Like& operator<<( float value ) {
        ( *this ) = value;
        return *this;
    }



    /* - @todo ������ operator=( float ). ��� ���� �������� �������.
    template< typename T >
    inline void operator=( T value ) {
        t = static_cast< float >( value );
    }
    */


    inline Like& operator=( float value ) {
        mLike = value;
        return *this;
    }




private:
    /**
    * �������������� ���-�� ����� ��������� �������� � ��������� [-...; +...].
    */
    float mLike;
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::Like& lu ) {
    out << "{ \"like\": " << lu() << " }";
    return out;
}


} // std
