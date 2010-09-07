#ifndef REVERSE_COMPUTATION_EXP_PROCESSOR_H
#define REVERSE_COMPUTATION_EXP_PROCESSOR_H

#include <rose.h>
#include "eventProcessor.h"


/*
 * If a variable is modified using destruction operation, it can be 
 * recovered by restoring or retrieving its value from others. That is 
 * store and restore and akgul style expression processor in our current
 * implementation. I think those two functions should be reused by all 
 * destructive operations: assignment, function call, a local variable 
 * leaving its scope, etc.
 */

//! This handler generates a NULL reverse expression.
class NullExpressionProcessor : public ExpressionReversalHandler
{
public:
    NullExpressionProcessor() { name_ = "Null Expression Processor"; }
    virtual ExpressionReversal generateReverseAST(SgExpression* exp, const EvaluationResult& evaluationResult);
    virtual std::vector<EvaluationResult> evaluate(SgExpression* exp, const VariableVersionTable& var_table, bool is_value_used);
};

//! This handler generates a reverse expression which is the same as the original expression.
class IdentityExpressionProcessor : public ExpressionReversalHandler
{
public:
    IdentityExpressionProcessor() { name_ = "Identity Expression Processor"; }
    virtual ExpressionReversal generateReverseAST(SgExpression* exp, const EvaluationResult& evaluationResult);
    virtual std::vector<EvaluationResult> evaluate(SgExpression* exp, const VariableVersionTable& var_table, bool is_value_used);
};

//! This handler just store and restore a value, once the value is modified (state saving style).
class StoreAndRestoreExpressionProcessor : public ExpressionReversalHandler
{
public:
    StoreAndRestoreExpressionProcessor() { name_ = "Store And Restore Expression Processor"; }
    virtual ExpressionReversal generateReverseAST(SgExpression* exp, const EvaluationResult& evaluationResult);
    virtual std::vector<EvaluationResult> evaluate(SgExpression* exp, const VariableVersionTable& var_table, bool is_value_used);
};

//! This handler handles constructive assignment, like ++, +=, -=, etc.
class ConstructiveExpressionProcessor : public ExpressionReversalHandler
{
public:
    ConstructiveExpressionProcessor() { name_ = "Constructive Expression Processor"; }
    virtual ExpressionReversal generateReverseAST(SgExpression* exp, const EvaluationResult& evaluationResult);
    virtual std::vector<EvaluationResult> evaluate(SgExpression* exp, const VariableVersionTable& var_table, bool is_value_used);
};

//! This handler handles more constructive assignment (for example, a = b - a).
/*class ConstructiveAssignmentProcessor : public ExpressionProcessor
{
public:
    ConstructiveAssignmentProcessor() { name_ = "Constructive Assignment Processor"; }
    virtual ExpressionReversal process(SgExpression* exp, const EvaluationResult& evaluationResult);
    virtual std::vector<EvaluationResult> evaluate(SgExpression* exp, const VariableVersionTable& var_table, bool is_value_used);
};*/

#endif    
