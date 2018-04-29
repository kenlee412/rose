#include <string>
#include "CastTransformer.h"

class TypeTransformer {
 public:
  typedef std::tuple<SgType*,SgFunctionDefinition*,std::string> VarTypeVarNameTuple;
  typedef std::list<VarTypeVarNameTuple> VarTypeVarNameTupleList;
  void addToTransformationList(VarTypeVarNameTupleList& list,SgType* type, SgFunctionDefinition* funDef, std::string varNames);
  // searches for variable in the given subtree 'root'
  int changeVariableType(SgNode* root, std::string varNameToFind, SgType* type);
  int changeTypeIfInitNameMatches(SgInitializedName* varInitName, SgNode* root, std::string varNameToFind, SgType* type);
  void transformCommandLineFiles(SgProject* project);
  void transformCommandLineFiles(SgProject* project, VarTypeVarNameTupleList& list);
  void makeAllCastsExplicit(SgProject* root);
  void annotateImplicitCastsAsComments(SgProject* root);
  void transformCastsInCommandLineFiles(SgProject* project);
  void setTraceFlag(bool);
  bool getTraceFlag();
  static void trace(std::string s);
  int getTotalNumChanges();
 private:
  CastTransformer _castTransformer;
  static bool _traceFlag;
  int _totalNumChanges=0;
};