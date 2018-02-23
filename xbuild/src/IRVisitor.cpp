//
// Created by Jarlene on 2018/2/8.
//

#include "xbuild/include/IRVisitor.h"

namespace xbuild {
    IRVisitor::IRVisitor() {

    }

    IRVisitor::~IRVisitor() {

    }

    void IRVisitor::visit(const IntImm *) {

    }

    void IRVisitor::visit(const UIntImm *) {

    }

    void IRVisitor::visit(const FloatImm *) {

    }

    void IRVisitor::visit(const StringImm *) {

    }

    void IRVisitor::visit(const Cast * op) {
        op->accept(this);
    }

    void IRVisitor::visit(const Variable *) {

    }

    void IRVisitor::visit(const Add * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Sub * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Mul * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Div *op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Mod * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Min * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Max * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const EQ * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const NE * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const LT * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const LE * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const GT * op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const GE *op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const And *op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Or *op) {
        op->a.accept(this);
        op->b.accept(this);
    }

    void IRVisitor::visit(const Not * op) {
        op->a.accept(this);
    }

    void IRVisitor::visit(const Select *op) {
        op->condition.accept(this);
        op->true_value.accept(this);
        op->false_value.accept(this);
    }

    void IRVisitor::visit(const Load * op) {
        op->predicate.accept(this);
        op->index.accept(this);
    }

    void IRVisitor::visit(const Ramp * op) {
        op->base.accept(this);
        op->stride.accept(this);
    }

    void IRVisitor::visit(const Broadcast * op) {
        op->value.accept(this);
    }

    void IRVisitor::visit(const Let *) {

    }

    void IRVisitor::visit(const LetStmt *) {

    }

    void IRVisitor::visit(const AssertStmt *) {

    }

    void IRVisitor::visit(const ProducerConsumer *) {

    }

    void IRVisitor::visit(const For *) {

    }

    void IRVisitor::visit(const Store *) {

    }

    void IRVisitor::visit(const Provide *) {

    }

    void IRVisitor::visit(const Allocate *) {

    }

    void IRVisitor::visit(const Free *) {

    }

    void IRVisitor::visit(const Realize *) {

    }

    void IRVisitor::visit(const Block *) {

    }

    void IRVisitor::visit(const IfThenElse *) {

    }

    void IRVisitor::visit(const Evaluate *) {

    }

    void IRVisitor::visit(const Shuffle *) {

    }

    void IRVisitor::visit(const Prefetch *) {

    }
}