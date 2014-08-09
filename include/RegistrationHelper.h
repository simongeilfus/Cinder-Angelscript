#pragma once

namespace as {
    
    class RegistrationHelper {
    public:
        
        //Constructors (with up to 5 parameters); Use asCALL_CDECL_OBJLAST
        template<typename T, typename U>
        static U cast(T* ptr) { return static_cast<U>( *ptr ); }
        
        // Class Helpers:
        
        //Constructors (with up to 5 parameters); Use asCALL_CDECL_OBJLAST
        template<typename T>
        static void constructor(T* ptr) { new (ptr) T(); }
        
        //Can also be used as copy constructor
        template<typename T, typename P1>
        static void constructor(P1 p1, T* ptr) { new (ptr) T(p1); }
        
        template<typename T, typename P1, typename P2>
        static void constructor(P1 p1, P2 p2, T* ptr) { new (ptr) T(p1,p2); }
        
        template<typename T, typename P1, typename P2, typename P3>
        static void constructor(P1 p1, P2 p2, P3 p3, T* ptr) { new (ptr) T(p1,p2,p3); }
        
        template<typename T, typename P1, typename P2, typename P3, typename P4>
        static void constructor(P1 p1, P2 p2, P3 p3, P4 p4, T* ptr) { new (ptr) T(p1,p2,p3,p4); }
        
        template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
        static void constructor(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, T* ptr) { new (ptr) T(p1,p2,p3,p4,p5); }
        
        
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename F>
        static void destructor(F* ptr) { ptr->~F(); }
        
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F,typename S>
        static R opAssign(const S rhs, F* ptr) { (*ptr) = rhs; return (*ptr); }
        
        //Comparison operators.
        //Bind as global behaviors; use asCALL_CDECL
        template<typename F,typename S>
        static bool opEquals(const F lhs, const S rhs) { return lhs == rhs; }
        template<typename F,typename S>
        static bool opNotEquals(const F lhs, const S rhs) { return lhs != rhs; }
        template<typename F,typename S>
        static bool opCmp(const F lhs, const S rhs) { return lhs > rhs; }
        template<typename F,typename S>
        static bool opCmpGreaterEquals(const F lhs, const S rhs) { return lhs >= rhs; }
        template<typename F,typename S>
        static bool opCmpLessEqual(const F lhs, const S rhs) { return lhs <= rhs; }
        template<typename F,typename S>
        static bool opCmpGreater(const F lhs, const S rhs) { return lhs > rhs; }
        template<typename F,typename S>
        static bool opCmpLess(const F lhs, const S rhs) { return lhs < rhs; }
        
        //Unary operators.
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F>
        static R Not(F* thisp) { return !(*thisp); }
        template<typename R,typename F>
        static R Negate(F* thisp) { return -(*thisp); }
        template<typename R,typename F>
        static R Positate(F* thisp) { return +(*thisp); }
        template<typename R,typename F>
        static R BinaryComplement(F* thisp) { return ~(*thisp); }
        
        //Binary operators. Operator, Assign variety.
        //Bind operator as global behavior; use asCALL_CDECL
        //Bind assign variety as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F,typename S>
        static R opAdd(const F lhs, const S rhs) { return lhs+rhs; }
        template<typename R,typename F,typename S>
        static R opAddAssign(const S rhs, F* thisp) { return (*thisp) += rhs; }
        
        template<typename R,typename F,typename S>
        static R opSub(const F lhs, const S rhs) { return lhs-rhs; }
        template<typename R,typename F,typename S>
        static R opSubAssign(const S rhs, F* thisp) { return (*thisp) -= rhs; }
        
        template<typename R,typename F,typename S>
        static R opMul(const F lhs, const S rhs) { return lhs*rhs; }
        template<typename R,typename F,typename S>
        static R opMulAssign(const S rhs, F* thisp) { return (*thisp) *= rhs; }
        
        template<typename R,typename F,typename S>
        static R opDiv(const F lhs, const S rhs) { return lhs/rhs; }
        template<typename R,typename F,typename S>
        static R opDivAssign(const S rhs, F* thisp) { return (*thisp) /= rhs; }
        
        template<typename R,typename F,typename S>
        static R opMod(const F lhs, const S rhs) { return lhs%rhs; }
        template<typename R,typename F,typename S>
        static R opModAssign(const S rhs, F* thisp) { return (*thisp) %= rhs; }
        
        template<typename R,typename F,typename S>
        static R opShl(const F lhs, const S rhs) { return lhs << rhs; }
        template<typename R,typename F,typename S>
        static R opShlAssign(const S rhs, F* thisp) { return (*thisp) <<= rhs; }
        
        template<typename R,typename F,typename S>
        static R opShr(const F lhs, const S rhs) { return lhs >> rhs; }
        template<typename R,typename F,typename S>
        static R opShrAssign(const S rhs, F* thisp) { return (*thisp) >>= rhs; }
        
        template<typename R,typename F,typename S>
        static R opAnd(const F lhs, const S rhs) { return lhs & rhs; }
        template<typename R,typename F,typename S>
        static R opAndAssign(const S rhs, F* thisp) { return (*thisp) &= rhs; }
        
        template<typename R,typename F,typename S>
        static R opOr(const F lhs, const S rhs) { return lhs | rhs; }
        template<typename R,typename F,typename S>
        static R opOrAssign(const S rhs, F* thisp) { return (*thisp) |= rhs; }
        
        template<typename R,typename F,typename S>
        static R opXor(const F lhs, const S rhs) { return lhs ^ rhs; }
        template<typename R,typename F,typename S>
        static R opXorAssign(const S rhs, F* thisp) { return (*thisp) ^= rhs; }
        
        //These binary operators do not have an assign variety
        template<typename R,typename F,typename S>
        static R LogicalAndRight(const F lhs, const S rhs) { return lhs && rhs; }
        template<typename R,typename F,typename S>
        static R LogicalOrRight(const F lhs, const S rhs) { return lhs || rhs; }
        
        //Index operator
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F,typename S>
        static R opIndex(const S i, F* thisp) { return (*thisp)[i]; }
        
        //Increment operators (Not supported by AngelScript)
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F>
        static R opPreInc(F* thisp) { return ++(*thisp); }
        template<typename R,typename F>
        static R opPostInc(F* thisp) { return (*thisp)++; }
        template<typename R,typename F>
        static R opPreDec(F* thisp) { return --(*thisp); }
        template<typename R,typename F>
        static R opPostDec(F* thisp) { return (*thisp)--; }
        
        //MemberSelection operator - MAY OR MAY NOT WORK.
        //Bind as type behavior; use asCALL_CDECL_OBJLAST
        template<typename R,typename F>
        static R MemberSelection(F* thisp) { return thisp->operator->(); }
        
    };
    
}
