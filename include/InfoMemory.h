#pragma once

#include "Info.h"
#include <set>
#include <memory>
#include <ostream>


namespace person {

class InfoMemory;
typedef std::shared_ptr< InfoMemory >  InfoMemoryPtr;
typedef std::unique_ptr< InfoMemory >  InfoMemoryUPtr;

}



namespace person {


/**
* Память, хранящая информацию о степени привязанности к понятиям.
*/
class InfoMemory {
public:
    /**
    * Топология памяти InfoMemory.
    */
    typedef std::set< Info >  topology_t;



public:
    inline InfoMemory() {
    }


    virtual inline ~InfoMemory() {
    }




    inline InfoMemory& operator<<( const Info& info ) {
        ( *this ) = info;
        return *this;
    }



    inline InfoMemory& operator=( const Info& info ) {
        mTopology.insert( info );
        return *this;
    }



    /**
    * @return Количество элементов в этой памяти.
    */
    inline size_t count() const {
        return mTopology.size();
    }



    inline topology_t const& topology() const {
        return mTopology;
    }





private:
    topology_t mTopology;
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::InfoMemory& im ) {
    out << "{ \"count\": " << im.count() << ", \"topology\": ";
    typelib::print( out, im.topology() );
    out << " }";
    return out;
}


} // std
