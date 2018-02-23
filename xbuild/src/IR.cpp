//
// Created by Jarlene on 2018/2/7.
//
#include "xbuild/include/IRVisitor.h"
#include "xbuild/include/IRMutator.h"
#include "xbuild/include/IR.h"


namespace xbuild {
    Expr Cast::make(Type t, Expr v) {
        assert(v.defined());
        assert(t.lanes() == v.type().lanes());
        Cast * node = new Cast;
        node->type = t;
        node->value = std::move(v);
        return node;
    }

    Expr Add::make(Expr a, Expr b) {

        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Add * node = new Add;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Sub::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Sub * node = new Sub;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Mul::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Mul * node = new Mul;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Div::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Div * node = new Div;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Mod::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Mod * node = new Mod;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Min::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Min * node = new Min;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Max::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Max * node = new Max;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr EQ::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        EQ * node = new EQ;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr NE::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        NE * node = new NE;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr LT::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        LT * node = new LT;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr LE::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        LE * node = new LE;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr GT::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        GT * node = new GT;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr GE::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        GE * node = new GE;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr And::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        And * node = new And;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Or::make(Expr a, Expr b) {
        assert(a.defined());
        assert(b.defined());
        assert(a.type() == b.type());
        Or * node = new Or;
        node->type = a.type();
        node->a = std::move(a);
        node->b = std::move(b);
        return node;
    }

    Expr Not::make(Expr a) {
        assert(a.defined());
        Not * node = new Not;
        node->type = a.type();
        node->a = std::move(a);
        return node;
    }

    Expr Select::make(Expr condition, Expr true_value, Expr false_value) {
        assert(condition.defined());
        assert(true_value.defined());
        assert(false_value.defined());
        assert(condition.type().is_bool());
        assert(false_value.type() == true_value.type());
        assert(condition.type().is_scalar() ||
               condition.type().lanes() == true_value.type().lanes());

        Select * node = new Select;
        node->type = true_value.type();
        node->condition = std::move(condition);
        node->true_value = std::move(true_value);
        node->false_value = std::move(false_value);
        return node;
    }

    template <class T>
    Expr Load::make(Type type, const std::string &name,
                    Expr index, Buffer<T> image,
                    Parameter param, Expr predicate) {
        assert(predicate.defined());
        assert(index.defined());
        assert(type.lanes() == index.type().lanes());
        assert(type.lanes() == predicate.type().lanes());
    }

    Expr Ramp::make(Expr base, Expr stride, int lanes) {
        assert(base.defined());
        assert(stride.defined());
        assert(base.type().is_scalar());
        assert(stride.type().is_scalar());
        assert(lanes > 1);
        assert(stride.type() == base.type());

        Ramp * node = new Ramp;
        node->type = base.type().with_lanes(lanes);
        node->base = std::move(base);
        node->stride = std::move(stride);
        node->lanes = std::move(lanes);
        return node;
    }

    Expr Broadcast::make(Expr value, int lanes) {
        assert(value.defined());
        assert(value.type().is_scalar());
        assert(lanes != 1);

        Broadcast * node = new Broadcast;
        node->type = value.type().with_lanes(lanes);
        node->value = std::move(value);
        node->lanes = lanes;
        return node;
    }

    Expr Let::make(const std::string &name, Expr value, Expr body) {
        assert(value.defined());
        assert(body.defined());
        Let * node = new Let;
        node->type = body.type();
        node->name = name;
        node->value = std::move(value);
        node->body = std::move(body);
        return node;
    }

    Stmt LetStmt::make(const std::string &name, Expr value, Stmt body) {
        assert(value.defined());
        assert(body.defined());

        LetStmt * node = new LetStmt;
        node->name = name;
        node->value = std::move(value);
        node->body = std::move(body);
        return node;
    }

    Stmt AssertStmt::make(Expr condition, Expr message) {
        assert(condition.defined());
        assert(message.type() == Int(32));
        AssertStmt * node = new AssertStmt;
        node->condition = std::move(condition);
        node->message = std::move(message);
        return node;

    }

    Stmt ProducerConsumer::make(const std::string &name, bool is_producer, Stmt body) {
        assert(body.defined());
        ProducerConsumer * node = new ProducerConsumer;
        node->name = name;
        node->is_producer = is_producer;
        node->body = std::move(body);
        return node;
    }

    Stmt ProducerConsumer::make_produce(const std::string &name, Stmt body) {
        return ProducerConsumer::make(name, true, std::move(body));
    }

    Stmt ProducerConsumer::make_consume(const std::string &name, Stmt body) {
        return ProducerConsumer::make(name, false, std::move(body));
    }

    Stmt Store::make(const std::string &name, Expr value, Expr index, Parameter param, Expr predicate) {
        assert(predicate.defined());
        assert(value.defined());
        assert(index.defined());
        assert(value.type().lanes() == index.type().lanes());
        assert(value.type().lanes() == predicate.type().lanes());
        Store * node = new Store;
        node->name = name;
        node->predicate = std::move(predicate);
        node->value = std::move(value);
        node->index = std::move(index);
        node->param = std::move(param);
        return node;
    }

    Stmt Provide::make(const std::string &name, const std::vector<Expr> &values, const std::vector<Expr> &args) {

        assert(!values.empty());
        for (size_t i = 0; i < values.size(); i++) {
            assert(values[i].defined());
        }
        for (size_t i = 0; i < args.size(); i++) {
            assert(args[i].defined());
        }

        Provide * node = new Provide;
        node->name = name;
        node->values = values;
        node->args = args;
        return node;
    }

    Stmt Allocate::make(const std::string &name, Type type, const std::vector<Expr> &extents, Expr condition, Stmt body,
                        Expr new_expr, const std::string &free_function) {
        return Stmt();
    }

    int32_t Allocate::constant_allocation_size(const std::vector<Expr> &extents, const std::string &name) {
        return 0;
    }

    int32_t Allocate::constant_allocation_size() const {
        return 0;
    }

    Stmt Free::make(const std::string &name) {
        return Stmt();
    }

    Stmt Realize::make(const std::string &name, const std::vector<Type> &types, const Region &bounds, Expr condition,
                       Stmt body) {
        return Stmt();
    }

    Stmt Block::make(Stmt first, Stmt rest) {
        return Stmt();
    }

    Stmt Block::make(const std::vector<Stmt> &stmts) {
        return Stmt();
    }

    Stmt IfThenElse::make(Expr condition, Stmt then_case, Stmt else_case) {
        return Stmt();
    }

    Stmt Evaluate::make(Expr v) {
        return Stmt();
    }

    Expr Variable::make(Type type, const std::string &name) {
        return Expr();
    }

    Stmt For::make(const std::string &name, Expr min, Expr extent, Stmt body) {
        return Stmt();
    }

    Expr Shuffle::make(const std::vector<Expr> &vectors, const std::vector<int> &indices) {
        return Expr();
    }

    Expr Shuffle::make_interleave(const std::vector<Expr> &vectors) {
        return Expr();
    }

    Expr Shuffle::make_concat(const std::vector<Expr> &vectors) {
        return Expr();
    }

    Expr Shuffle::make_slice(Expr vector, int begin, int stride, int size) {
        return Expr();
    }

    Expr Shuffle::make_extract_element(Expr vector, int i) {
        return Expr();
    }

    bool Shuffle::is_interleave() const {
        return false;
    }

    bool Shuffle::is_concat() const {
        return false;
    }

    bool Shuffle::is_extract_element() const {
        return false;
    }

    Stmt Prefetch::make(const std::string &name, const std::vector<Type> &types, const Region &bounds) {
        return Stmt();
    }





    template<> void ExprNode<IntImm>::accept(IRVisitor *v) const { v->visit((const IntImm *)this); }
    template<> void ExprNode<UIntImm>::accept(IRVisitor *v) const { v->visit((const UIntImm *)this); }
    template<> void ExprNode<FloatImm>::accept(IRVisitor *v) const { v->visit((const FloatImm *)this); }
    template<> void ExprNode<StringImm>::accept(IRVisitor *v) const { v->visit((const StringImm *)this); }
    template<> void ExprNode<Cast>::accept(IRVisitor *v) const { v->visit((const Cast *)this); }
    template<> void ExprNode<Variable>::accept(IRVisitor *v) const { v->visit((const Variable *)this); }
    template<> void ExprNode<Add>::accept(IRVisitor *v) const { v->visit((const Add *)this); }
    template<> void ExprNode<Sub>::accept(IRVisitor *v) const { v->visit((const Sub *)this); }
    template<> void ExprNode<Mul>::accept(IRVisitor *v) const { v->visit((const Mul *)this); }
    template<> void ExprNode<Div>::accept(IRVisitor *v) const { v->visit((const Div *)this); }
    template<> void ExprNode<Mod>::accept(IRVisitor *v) const { v->visit((const Mod *)this); }
    template<> void ExprNode<Min>::accept(IRVisitor *v) const { v->visit((const Min *)this); }
    template<> void ExprNode<Max>::accept(IRVisitor *v) const { v->visit((const Max *)this); }
    template<> void ExprNode<EQ>::accept(IRVisitor *v) const { v->visit((const EQ *)this); }
    template<> void ExprNode<NE>::accept(IRVisitor *v) const { v->visit((const NE *)this); }
    template<> void ExprNode<LT>::accept(IRVisitor *v) const { v->visit((const LT *)this); }
    template<> void ExprNode<LE>::accept(IRVisitor *v) const { v->visit((const LE *)this); }
    template<> void ExprNode<GT>::accept(IRVisitor *v) const { v->visit((const GT *)this); }
    template<> void ExprNode<GE>::accept(IRVisitor *v) const { v->visit((const GE *)this); }
    template<> void ExprNode<And>::accept(IRVisitor *v) const { v->visit((const And *)this); }
    template<> void ExprNode<Or>::accept(IRVisitor *v) const { v->visit((const Or *)this); }
    template<> void ExprNode<Not>::accept(IRVisitor *v) const { v->visit((const Not *)this); }
    template<> void ExprNode<Select>::accept(IRVisitor *v) const { v->visit((const Select *)this); }
    template<> void ExprNode<Load>::accept(IRVisitor *v) const { v->visit((const Load *)this); }
    template<> void ExprNode<Ramp>::accept(IRVisitor *v) const { v->visit((const Ramp *)this); }
    template<> void ExprNode<Broadcast>::accept(IRVisitor *v) const { v->visit((const Broadcast *)this); }
//    template<> void ExprNode<Call>::accept(IRVisitor *v) const { v->visit((const Call *)this); }
    template<> void ExprNode<Shuffle>::accept(IRVisitor *v) const { v->visit((const Shuffle *)this); }
    template<> void ExprNode<Let>::accept(IRVisitor *v) const { v->visit((const Let *)this); }
    template<> void StmtNode<LetStmt>::accept(IRVisitor *v) const { v->visit((const LetStmt *)this); }
    template<> void StmtNode<AssertStmt>::accept(IRVisitor *v) const { v->visit((const AssertStmt *)this); }
    template<> void StmtNode<ProducerConsumer>::accept(IRVisitor *v) const { v->visit((const ProducerConsumer *)this); }
    template<> void StmtNode<For>::accept(IRVisitor *v) const { v->visit((const For *)this); }
    template<> void StmtNode<Store>::accept(IRVisitor *v) const { v->visit((const Store *)this); }
    template<> void StmtNode<Provide>::accept(IRVisitor *v) const { v->visit((const Provide *)this); }
    template<> void StmtNode<Allocate>::accept(IRVisitor *v) const { v->visit((const Allocate *)this); }
    template<> void StmtNode<Free>::accept(IRVisitor *v) const { v->visit((const Free *)this); }
    template<> void StmtNode<Realize>::accept(IRVisitor *v) const { v->visit((const Realize *)this); }
    template<> void StmtNode<Block>::accept(IRVisitor *v) const { v->visit((const Block *)this); }
    template<> void StmtNode<IfThenElse>::accept(IRVisitor *v) const { v->visit((const IfThenElse *)this); }
    template<> void StmtNode<Evaluate>::accept(IRVisitor *v) const { v->visit((const Evaluate *)this); }
    template<> void StmtNode<Prefetch>::accept(IRVisitor *v) const { v->visit((const Prefetch *)this); }

    template<> Expr ExprNode<IntImm>::mutate_expr(IRMutator *v) const { return v->visit((const IntImm *)this); }
    template<> Expr ExprNode<UIntImm>::mutate_expr(IRMutator *v) const { return v->visit((const UIntImm *)this); }
    template<> Expr ExprNode<FloatImm>::mutate_expr(IRMutator *v) const { return v->visit((const FloatImm *)this); }
    template<> Expr ExprNode<StringImm>::mutate_expr(IRMutator *v) const { return v->visit((const StringImm *)this); }
    template<> Expr ExprNode<Cast>::mutate_expr(IRMutator *v) const { return v->visit((const Cast *)this); }
    template<> Expr ExprNode<Variable>::mutate_expr(IRMutator *v) const { return v->visit((const Variable *)this); }
    template<> Expr ExprNode<Add>::mutate_expr(IRMutator *v) const { return v->visit((const Add *)this); }
    template<> Expr ExprNode<Sub>::mutate_expr(IRMutator *v) const { return v->visit((const Sub *)this); }
    template<> Expr ExprNode<Mul>::mutate_expr(IRMutator *v) const { return v->visit((const Mul *)this); }
    template<> Expr ExprNode<Div>::mutate_expr(IRMutator *v) const { return v->visit((const Div *)this); }
    template<> Expr ExprNode<Mod>::mutate_expr(IRMutator *v) const { return v->visit((const Mod *)this); }
    template<> Expr ExprNode<Min>::mutate_expr(IRMutator *v) const { return v->visit((const Min *)this); }
    template<> Expr ExprNode<Max>::mutate_expr(IRMutator *v) const { return v->visit((const Max *)this); }
    template<> Expr ExprNode<EQ>::mutate_expr(IRMutator *v) const { return v->visit((const EQ *)this); }
    template<> Expr ExprNode<NE>::mutate_expr(IRMutator *v) const { return v->visit((const NE *)this); }
    template<> Expr ExprNode<LT>::mutate_expr(IRMutator *v) const { return v->visit((const LT *)this); }
    template<> Expr ExprNode<LE>::mutate_expr(IRMutator *v) const { return v->visit((const LE *)this); }
    template<> Expr ExprNode<GT>::mutate_expr(IRMutator *v) const { return v->visit((const GT *)this); }
    template<> Expr ExprNode<GE>::mutate_expr(IRMutator *v) const { return v->visit((const GE *)this); }
    template<> Expr ExprNode<And>::mutate_expr(IRMutator *v) const { return v->visit((const And *)this); }
    template<> Expr ExprNode<Or>::mutate_expr(IRMutator *v) const { return v->visit((const Or *)this); }
    template<> Expr ExprNode<Not>::mutate_expr(IRMutator *v) const { return v->visit((const Not *)this); }
    template<> Expr ExprNode<Select>::mutate_expr(IRMutator *v) const { return v->visit((const Select *)this); }
    template<> Expr ExprNode<Load>::mutate_expr(IRMutator *v) const { return v->visit((const Load *)this); }
    template<> Expr ExprNode<Ramp>::mutate_expr(IRMutator *v) const { return v->visit((const Ramp *)this); }
    template<> Expr ExprNode<Broadcast>::mutate_expr(IRMutator *v) const { return v->visit((const Broadcast *)this); }
//    template<> Expr ExprNode<Call>::mutate_expr(IRMutator *v) const { return v->visit((const Call *)this); }
    template<> Expr ExprNode<Shuffle>::mutate_expr(IRMutator *v) const { return v->visit((const Shuffle *)this); }
    template<> Expr ExprNode<Let>::mutate_expr(IRMutator *v) const { return v->visit((const Let *)this); }

    template<> Stmt StmtNode<LetStmt>::mutate_stmt(IRMutator *v) const { return v->visit((const LetStmt *)this); }
    template<> Stmt StmtNode<AssertStmt>::mutate_stmt(IRMutator *v) const { return v->visit((const AssertStmt *)this); }
    template<> Stmt StmtNode<ProducerConsumer>::mutate_stmt(IRMutator *v) const { return v->visit((const ProducerConsumer *)this); }
    template<> Stmt StmtNode<For>::mutate_stmt(IRMutator *v) const { return v->visit((const For *)this); }
    template<> Stmt StmtNode<Store>::mutate_stmt(IRMutator *v) const { return v->visit((const Store *)this); }
    template<> Stmt StmtNode<Provide>::mutate_stmt(IRMutator *v) const { return v->visit((const Provide *)this); }
    template<> Stmt StmtNode<Allocate>::mutate_stmt(IRMutator *v) const { return v->visit((const Allocate *)this); }
    template<> Stmt StmtNode<Free>::mutate_stmt(IRMutator *v) const { return v->visit((const Free *)this); }
    template<> Stmt StmtNode<Realize>::mutate_stmt(IRMutator *v) const { return v->visit((const Realize *)this); }
    template<> Stmt StmtNode<Block>::mutate_stmt(IRMutator *v) const { return v->visit((const Block *)this); }
    template<> Stmt StmtNode<IfThenElse>::mutate_stmt(IRMutator *v) const { return v->visit((const IfThenElse *)this); }
    template<> Stmt StmtNode<Evaluate>::mutate_stmt(IRMutator *v) const { return v->visit((const Evaluate *)this); }
    template<> Stmt StmtNode<Prefetch>::mutate_stmt(IRMutator *v) const { return v->visit((const Prefetch *)this); }

}

