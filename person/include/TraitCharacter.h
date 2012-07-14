#pragma once

#include <memory>
#include <string>
#include <ostream>


namespace person {

class TraitCharacter;
typedef std::shared_ptr< TraitCharacter >  TraitCharacterPtr;
typedef std::unique_ptr< TraitCharacter >  TraitCharacterUPtr;

}




namespace person {


/**
* „ерта характера.
*
* @see Character
*/
class TraitCharacter {
public:
    explicit inline TraitCharacter( float value = 0.0f ) : t( value ) {
    }

    inline float operator()() const {
        return t;
    }

    inline float& operator()() {
        return t;
    }

    inline operator float& () {
        return t;
    }

    /*
    template< typename T >
    inline void operator=( T value ) {
        t = static_cast< float >( value );
    }
    */

    inline TraitCharacter& operator=( float value ) {
        t = value;
        return *this;
    }


private:
    /**
    *  оличественна€ хар-ка может принимать значение в диапазоне [0.0; 100.0].
    */
    float t;
};







struct hyp : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct sei : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct emo : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct ped : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct anx : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct cyc : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct dem : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct exc : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct dys : public TraitCharacter {
    using TraitCharacter::operator=;
};




struct ecs : public TraitCharacter {
    using TraitCharacter::operator=;
};





} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::hyp& trait ) {
    out << "{ \"hyp\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::sei& trait ) {
    out << "{ \"sei\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::emo& trait ) {
    out << "{ \"emo\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::ped& trait ) {
    out << "{ \"ped\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::anx& trait ) {
    out << "{ \"anx\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::cyc& trait ) {
    out << "{ \"cyc\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::dem& trait ) {
    out << "{ \"dem\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::exc& trait ) {
    out << "{ \"exc\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::dys& trait ) {
    out << "{ \"dys\": " << trait() << " }";
    return out;
}


inline std::ostream& operator<<( std::ostream& out, const person::ecs& trait ) {
    out << "{ \"ecs\": " << trait() << " }";
    return out;
}


} // std
