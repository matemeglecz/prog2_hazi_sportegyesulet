#include "datum.h"

std::ostream& operator<<(std::ostream& os, const Datum& d){
    return os << d.getEv() << "." << d.getHonap() << "." << d.getNap() << ". " << d.getOra() << ":" << d.getPerc();

}

bool Datum::operator==(Datum& rhs) const{
    return rhs.getEv()==ev && rhs.getHonap()==honap && rhs.getNap()==nap && rhs.getOra()==ora && rhs.getPerc()==perc;
}
