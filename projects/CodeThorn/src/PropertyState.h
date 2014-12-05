
#ifndef PROPERTY_STATE_H
#define PROPERTY_STATE_H

#include "sage3basic.h"
#include "Lattice.h"
#include "VariableIdMapping.h"

class PropertyState : public Lattice {
 public:
  PropertyState();
  virtual void toStream(ostream& os, VariableIdMapping* vim=0);
  virtual bool approximatedBy(PropertyState& other);
  virtual void combine(PropertyState& other);
};

#endif
