#include "datum.h"

std::ostream& operator<<(std::ostream& os, const Datum& d){
    return os << d.getEv() << "." << d.getHonap() << "." << d.getNap() << ". " << d.getOra() << ":" << d.getPerc();

}
