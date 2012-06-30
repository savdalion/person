#pragma once

#include "Character.h"
#include "LikeMemory.h"
#include "AffectionMemory.h"
#include "InfoMemory.h"
#include <string>


namespace person {

class Person;
typedef std::shared_ptr< Person >  PersonPtr;
typedef std::unique_ptr< Person >  PersonUPtr;

}




namespace std {

inline std::ostream& operator<<( std::ostream&, const person::Person& );

}




namespace person {


/**
* ��������.
* ���������� ����� �������� ����� ����� ��������.
*/
class Person {
public:

    inline Person() {
    }



    inline virtual ~Person() {
    }



    /**
    * @return ������ � ���� ������ ��������.
    */
    inline std::string operator()() const {
        std::ostringstream ss;
        ss << *this;
        return ss.str();
    }




    inline Character const& character() const {
        return mCharacter;
    }


    inline Character& character() {
        return mCharacter;
    }




    inline InfoMemory const& infoMemory() const {
        return mInfoMemory;
    }


    inline InfoMemory& infoMemory() {
        return mInfoMemory;
    }




    inline LikeMemory const& likeMemory() const {
        return mLikeMemory;
    }


    inline LikeMemory& likeMemory() {
        return mLikeMemory;
    }




    inline AffectionMemory const& affectionMemory() const {
        return mAffectionMemory;
    }


    inline AffectionMemory& affectionMemory() {
        return mAffectionMemory;
    }




    inline Person& operator<<( const Character& ch ) {
        mCharacter = ch;
        return *this;
    }




    inline Person& operator<<( const Info& info ) {
        mInfoMemory << info;
        return *this;
    }







private:
    /**
    * ��������.
    */
    Character mCharacter;

    
    /**
    * ������ � ���-����.
    * �������� �������� ���������� ����������.
    */
    InfoMemory mInfoMemory;


    /**
    * ������ "������� -> �������� / ���".
    * �������� ��� ���� ������ �� ����� ���� ���������, �.�. �� ��������
    * �������� - ������������ ��� ������������� - � ��������.
    */
    LikeMemory mLikeMemory;


    /**
    * ������ "������� -> �������������".
    * �������� ��� ���� ������ �� ����� ���� ���������, �.�. �� ��������
    * �������� - ������������ ��� ������������� - � ��������.
    */
    AffectionMemory mAffectionMemory;



    /**
    * @todo ������������.
    */


    /**
    * @todo ������������.
    */

};



} // person







namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::Person& p ) {
    out << "{ " <<
        "\"character\": " << p.character() << ", " <<
        "\"info-memory\": " << p.infoMemory() << ", " <<
        "\"like-memory\": " << p.likeMemory() << ", " <<
        "\"affection-memory\": " << p.affectionMemory() <<
    " }";
    return out;
}


} // std
