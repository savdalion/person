#pragma once

#include "TraitCharacter.h"
#include <other-type.h>
#include <memory>
#include <tuple>


namespace person {

class Character;
typedef std::shared_ptr< Character >  CharacterPtr;
typedef std::unique_ptr< Character >  CharacterUPtr;

}




namespace person {


/**
* �������� ���������.
*
* �� ������ ����� ������ �. �. ��������� "�������������� �������������� ���� ���������"
* @source http://ria-stk.ru/mi/adetail.php?ID=8859
*
* �������� �������� �� 10-�� ������� ����:
     0	�������������	    ���	    hypering	    hyp
     1	�����������	        ���	    seizing	        sei
     2	�����������	        ���	    emoting	        emo
     3	�������������	    ���	    pedantic	    ped
     4	�����������	        ���	    anxiety	        anx
     5	�������������	    ���	    cycloiding	    cyc
     6	�����������������	���	    demonstrativing	dem
     7	������������	    ���	    excitability	exc
     8	�����������	        ���	    dysthyming	    dys
     9	������������������	���	    ecstatic	    ecs
*
* ��� ������ ����� ��������� �������� ������������ �� ������� ����.
*/
class Character {
public:
    /**
    * ��������� ���������, ������� �����.
    * (!) ������� ��������� ������ ��������� � �������� � ������� ���������� 'MC'.
    */
    typedef std::tuple<
        hyp, sei, emo, ped, anx, cyc, dem, exc, dys, ecs
    >  topology_t;



public:

    inline Character() {
        hyp h;
        h = 0.0f;
        std::get< 0 >( mTopology ) = 0.0f;
        std::get< 1 >( mTopology ) = 0.0f;
        std::get< 2 >( mTopology ) = 0.0f;
        std::get< 3 >( mTopology ) = 0.0f;
        std::get< 4 >( mTopology ) = 0.0f;
        std::get< 5 >( mTopology ) = 0.0f;
        std::get< 6 >( mTopology ) = 0.0f;
        std::get< 7 >( mTopology ) = 0.0f;
        std::get< 8 >( mTopology ) = 0.0f;
        std::get< 9 >( mTopology ) = 0.0f;
    }




    inline virtual ~Character() {
    }




    inline topology_t const& topology() const {
        return mTopology;
    }




    /**
    * ������������� �������� ��� ����� ��������� 'T'.
    * ��������� ����� ������������� ������������� � "����������",
    * ������������ ��������� �������� ������� ���������� 'MC'.
    * (!) �������� ��� �������� �� ����������� ����� 'T'.
    */
    template< typename T, typename V >
    inline void set( V value ) {
        assert( typelib::between( static_cast< float >( value ), 0.0f, 100.0f )
            && "�������� ����� ��������� ������ ������ � ��������� [0; 100]." );
        // ������� ������ � ������� 'MC' �� ����� 'T'
        const size_t k = it< T >();
        std::get< k >( mTopology ) = static_cast< float >( value );
        recount< k >();
    }






protected:
    /**
    * ������������� �������� ������ ���� ��������� �������� �������
    * ���������� 'MC'.
    * (!) �������� ��� �������� �� ����������� ����� 'k'.
    *
    * @template k ������ �����, ������������ ������� ���� �����������
    *           ������ �����.
    *
    * @see set()
    */
    template< size_t k >
    inline void recount() {
        const float value = std::get< k >( topology );
        // � ������������� �������� ������ ����
        for (size_t i = 0; i < 10; ++i) {
            if (i != k) {
                const float t = value * (MC[i] + 1.0f);
                std::get< i >( mTopology ) = t;
                assert( typelib::between( t, 0.0f, 100.0f )
                    && "�������� ���� ��������� ������ ������ � ��������� [0; 100]." );
            }
        }        
    }





protected:
    /**
    * @return ������ � ������� �� ����� 'T'.
    */
    template< typename T >
    static inline size_t indexMC() {
        if (typeid( T ) == typeid( hyp )) {
            return 0;
        } else if (typeid( T ) == typeid( sei )) {
            return 1;
        } else if (typeid( T ) == typeid( emo )) {
            return 2;
        } else if (typeid( T ) == typeid( ped )) {
            return 3;
        } else if (typeid( T ) == typeid( anx )) {
            return 4;
        } else if (typeid( T ) == typeid( cyc )) {
            return 5;
        } else if (typeid( T ) == typeid( dem )) {
            return 6;
        } else if (typeid( T ) == typeid( exc )) {
            return 7;
        } else if (typeid( T ) == typeid( dys )) {
            return 8;
        } else if (typeid( T ) == typeid( ecs )) {
            return 9;
        } else {
            const std::string& typeName = typeid( T ).name();
            std::cerr <<
                "����� ��������� ������ ���� �� ����. ������: hyp, sei, emo, ped, anx, cyc, dem, exc, dys, ecs" <<
                "\n��������: " << typeName <<
            std::endl;
            throw "@todo fine";
        }
        return 0;
    }





protected:
    /**
    * ������� ����� ��������� (���������).
    */
    topology_t mTopology;





private:
    /**
    * ������� ���������� ����� �������� ������� ���������.
    * (!) ������� ������������� ������ ��������� � �������� �
    * ��������� 'topology'.
    */
    static const float MC[10][10];

};






// @source http://ria-stk.ru/mi/adetail.php?ID=8859
const float Character::MC[10][10] = {
    { 1.00f, 0.04f, 0.11f, 0.00f, -0.03f, -0.11f, 0.51f, 0.03f, -0.62f, 0.05f },
    { 0.04f, 1.00f, 0.06f, 0.39f, 0.22f, 0.28f, 0.16f, 0.23f, 0.00f, 0.18f },
    { 0.11f, 0.06f, 1.00f, 0.26f, 0.48f, 0.20f, 0.03f, 0.26f, -0.06f, 0.30f },
    { 0.00f, 0.39f, 0.26f, 1.00f, 0.23f, 0.22f, 0.12f, 0.06f, 0.16f, 0.13f },
    { -0.03f, 0.22f, 0.48f, 0.23f, 1.00f, 0.33f, 0.01f, 0.02f, 0.18f, 0.26f },
    { -0.11f, 0.28f, 0.20f, 0.22f, 0.33f, 1.00f, -0.11f, 0.42f, 0.27f, 0.70f },
    { 0.51f, 0.16f, 0.03f, 0.12f, 0.01f, -0.11f, 1.00f, 0.27f, -0.30f, 0.22f },
    { 0.03f, 0.23f, 0.26f, 0.06f, 0.02f, 0.42f, 0.27f, 1.00f, 0.10f, 0.29f },
    { -0.62f, 0.00f, -0.06f, 0.16f, 0.18f, 0.27f, -0.30f, 0.10f, 1.00f, 0.16f },
    { 0.05f, 0.30f, 0.30f, 0.13f, 0.26f, 0.70f, 0.22f, 0.29f, 0.16f, 1.00f }
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::Character& c ) {
    out << "[ " <<
        std::get< 0 >( c.topology() ) << ", " <<
        std::get< 1 >( c.topology() ) << ", " <<
        std::get< 2 >( c.topology() ) << ", " <<
        std::get< 3 >( c.topology() ) << ", " <<
        std::get< 4 >( c.topology() ) << ", " <<
        std::get< 5 >( c.topology() ) << ", " <<
        std::get< 6 >( c.topology() ) << ", " <<
        std::get< 7 >( c.topology() ) << ", " <<
        std::get< 8 >( c.topology() ) << ", " <<
        std::get< 9 >( c.topology() ) <<
    " ]";
    return out;
}


} // std
