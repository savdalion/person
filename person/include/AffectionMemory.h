#pragma once

#include "Concept.h"
#include "Affection.h"
#include <map>
#include <memory>
#include <ostream>


namespace person {

class AffectionMemory;
typedef std::shared_ptr< AffectionMemory >  AffectionMemoryPtr;
typedef std::unique_ptr< AffectionMemory >  AffectionMemoryUPtr;

}



namespace person {


/**
* Память, хранящая информацию о *степени привязанности* к понятиям.
*/
class AffectionMemory {
public:
    /**
    * Понятие и степень привязанности к этому понятию.
    */
    typedef std::pair< Concept, Affection >  conceptAffection_t;

    /**
    * Топология памяти AffectionMemory.
    */
    typedef std::map< conceptAffection_t::first_type, conceptAffection_t::second_type >  topology_t;



public:
    inline AffectionMemory() {
    }


    virtual inline ~AffectionMemory() {
    }




    inline AffectionMemory& operator<<( const conceptAffection_t& ca ) {
        ( *this ) = ca;
        return *this;
    }



    inline AffectionMemory& operator=( const conceptAffection_t& ca ) {
        mTopology[ ca.first ] = ca.second;
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


inline std::ostream& operator<<( std::ostream& out, const person::AffectionMemory& am ) {
    out << "{ \"count\": " << am.count() << ", \"topology\": ";
    typelib::printPair( out, am.topology() );
    out << " }";
    return out;
}


} // std
