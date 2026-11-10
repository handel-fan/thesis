// Lean compiler output
// Module: examples.l_to_mlir.l_to_mlir1
// Imports: public import Init public meta import Init public import TensorLib
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
float l_Float32_ofScientific(lean_object*, uint8_t, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_reshape_x21(lean_object*, lean_object*);
uint8_t lp_TensorLib_TensorLib_instBEqDtype_beq(uint8_t, uint8_t);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_zeros(uint8_t, lean_object*);
lean_object* lp_TensorLib___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_TensorLib_Ufunc_0__TensorLib_Tensor_Ufunc_matmul2_spec__2___redArg(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_TensorLib_Float32_ofLEByteArray(lean_object*);
lean_object* l_Float32_repr(float, lean_object*);
lean_object* lp_batteries_IO_println___at___00Lean_printTraces___at___00Batteries_Tactic_Lint_lintCore_spec__5_spec__10(lean_object*);
lean_object* lp_batteries_IO_println___at___00Batteries_Tactic_Lint_lintCore_spec__4(lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_toList(lean_object*);
static const lean_string_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Expected 2d arrays"};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__0 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__0_value;
static const lean_ctor_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__0_value)}};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__1 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__1_value;
static const lean_string_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Expected same dtype"};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__2 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__2_value;
static const lean_ctor_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__2_value)}};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__3 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__3_value;
static const lean_string_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "matmul2: reduction dimension mismatch"};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__4 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__4_value;
static const lean_ctor_object l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__4_value)}};
static const lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__5 = (const lean_object*)&l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__5_value;
LEAN_EXPORT lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Starting l_to_mlir1.lean"};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
static lean_once_cell_t l_main___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__1;
static lean_once_cell_t l_main___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__2;
static lean_once_cell_t l_main___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__3;
static lean_once_cell_t l_main___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__4;
LEAN_EXPORT lean_object* l_main___closed__5___boxed__const__1;
static lean_once_cell_t l_main___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__5;
LEAN_EXPORT lean_object* l_main___closed__6___boxed__const__1;
static lean_once_cell_t l_main___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__6;
LEAN_EXPORT lean_object* l_main___closed__7___boxed__const__1;
static lean_once_cell_t l_main___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__7;
LEAN_EXPORT lean_object* l_main___closed__8___boxed__const__1;
static lean_once_cell_t l_main___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__8;
static lean_once_cell_t l_main___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__9;
static const lean_ctor_object l_main___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_main___closed__10 = (const lean_object*)&l_main___closed__10_value;
static const lean_ctor_object l_main___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&l_main___closed__10_value)}};
static const lean_object* l_main___closed__11 = (const lean_object*)&l_main___closed__11_value;
static lean_once_cell_t l_main___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__12;
static lean_once_cell_t l_main___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__13;
static lean_once_cell_t l_main___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__14;
static lean_once_cell_t l_main___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__15;
static lean_once_cell_t l_main___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__16;
LEAN_EXPORT lean_object* l_main___closed__17___boxed__const__1;
static lean_once_cell_t l_main___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__17;
LEAN_EXPORT lean_object* l_main___closed__18___boxed__const__1;
static lean_once_cell_t l_main___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__18;
LEAN_EXPORT lean_object* l_main___closed__19___boxed__const__1;
static lean_once_cell_t l_main___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__19;
LEAN_EXPORT lean_object* l_main___closed__20___boxed__const__1;
static lean_once_cell_t l_main___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__20;
static lean_once_cell_t l_main___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__21;
static lean_once_cell_t l_main___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__22;
static lean_once_cell_t l_main___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__23;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2(lean_object* v_x_10_, lean_object* v_y_11_){
_start:
{
uint8_t v_dtype_14_; lean_object* v_shape_15_; uint8_t v_dtype_16_; lean_object* v_shape_17_; uint8_t v___x_18_; 
v_dtype_14_ = lean_ctor_get_uint8(v_x_10_, sizeof(void*)*4);
v_shape_15_ = lean_ctor_get(v_x_10_, 0);
v_dtype_16_ = lean_ctor_get_uint8(v_y_11_, sizeof(void*)*4);
v_shape_17_ = lean_ctor_get(v_y_11_, 0);
lean_inc(v_shape_17_);
v___x_18_ = lp_TensorLib_TensorLib_instBEqDtype_beq(v_dtype_14_, v_dtype_16_);
if (v___x_18_ == 0)
{
lean_object* v___x_19_; 
lean_dec(v_shape_17_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
v___x_19_ = ((lean_object*)(l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__3));
return v___x_19_;
}
else
{
if (lean_obj_tag(v_shape_15_) == 1)
{
lean_object* v_tail_20_; 
v_tail_20_ = lean_ctor_get(v_shape_15_, 1);
if (lean_obj_tag(v_tail_20_) == 1)
{
lean_object* v_tail_21_; 
v_tail_21_ = lean_ctor_get(v_tail_20_, 1);
if (lean_obj_tag(v_tail_21_) == 0)
{
if (lean_obj_tag(v_shape_17_) == 1)
{
lean_object* v_tail_22_; 
v_tail_22_ = lean_ctor_get(v_shape_17_, 1);
lean_inc(v_tail_22_);
if (lean_obj_tag(v_tail_22_) == 1)
{
lean_object* v_tail_23_; 
v_tail_23_ = lean_ctor_get(v_tail_22_, 1);
lean_inc(v_tail_23_);
if (lean_obj_tag(v_tail_23_) == 0)
{
lean_object* v_head_24_; lean_object* v_head_25_; lean_object* v_head_26_; lean_object* v___x_28_; uint8_t v_isShared_29_; uint8_t v_isSharedCheck_41_; 
v_head_24_ = lean_ctor_get(v_shape_15_, 0);
v_head_25_ = lean_ctor_get(v_tail_20_, 0);
lean_inc(v_head_25_);
v_head_26_ = lean_ctor_get(v_shape_17_, 0);
v_isSharedCheck_41_ = !lean_is_exclusive(v_shape_17_);
if (v_isSharedCheck_41_ == 0)
{
lean_object* v_unused_42_; 
v_unused_42_ = lean_ctor_get(v_shape_17_, 1);
lean_dec(v_unused_42_);
v___x_28_ = v_shape_17_;
v_isShared_29_ = v_isSharedCheck_41_;
goto v_resetjp_27_;
}
else
{
lean_inc(v_head_26_);
lean_dec(v_shape_17_);
v___x_28_ = lean_box(0);
v_isShared_29_ = v_isSharedCheck_41_;
goto v_resetjp_27_;
}
v_resetjp_27_:
{
lean_object* v_head_30_; uint8_t v___x_31_; 
v_head_30_ = lean_ctor_get(v_tail_22_, 0);
lean_inc(v_head_30_);
v___x_31_ = lean_nat_dec_eq(v_head_25_, v_head_26_);
lean_dec(v_head_26_);
if (v___x_31_ == 0)
{
lean_object* v___x_32_; 
lean_dec(v_head_30_);
lean_del_object(v___x_28_);
lean_dec(v_head_25_);
lean_dec_ref_known(v_tail_22_, 2);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
v___x_32_ = ((lean_object*)(l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__5));
return v___x_32_;
}
else
{
lean_object* v___x_34_; 
lean_inc(v_head_24_);
if (v_isShared_29_ == 0)
{
lean_ctor_set(v___x_28_, 0, v_head_24_);
v___x_34_ = v___x_28_;
goto v_reusejp_33_;
}
else
{
lean_object* v_reuseFailAlloc_40_; 
v_reuseFailAlloc_40_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_40_, 0, v_head_24_);
lean_ctor_set(v_reuseFailAlloc_40_, 1, v_tail_22_);
v___x_34_ = v_reuseFailAlloc_40_;
goto v_reusejp_33_;
}
v_reusejp_33_:
{
lean_object* v_res_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; 
v_res_35_ = lp_TensorLib_TensorLib_Tensor_zeros(v_dtype_14_, v___x_34_);
v___x_36_ = lean_unsigned_to_nat(0u);
v___x_37_ = lean_unsigned_to_nat(1u);
lean_inc(v_head_24_);
v___x_38_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_38_, 0, v___x_36_);
lean_ctor_set(v___x_38_, 1, v_head_24_);
lean_ctor_set(v___x_38_, 2, v___x_37_);
v___x_39_ = lp_TensorLib___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_TensorLib_Ufunc_0__TensorLib_Tensor_Ufunc_matmul2_spec__2___redArg(v_tail_23_, v_x_10_, v_y_11_, v_dtype_14_, v_head_25_, v_head_30_, v___x_38_, v_res_35_, v___x_36_);
lean_dec_ref_known(v___x_38_, 3);
return v___x_39_;
}
}
}
}
else
{
lean_dec(v_tail_23_);
lean_dec_ref_known(v_tail_22_, 2);
lean_dec_ref_known(v_shape_17_, 2);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
else
{
lean_dec_ref_known(v_shape_17_, 2);
lean_dec(v_tail_22_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
else
{
lean_dec(v_shape_17_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
else
{
lean_dec(v_shape_17_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
else
{
lean_dec(v_shape_17_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
else
{
lean_dec(v_shape_17_);
lean_dec_ref(v_y_11_);
lean_dec_ref(v_x_10_);
goto v___jp_12_;
}
}
v___jp_12_:
{
lean_object* v___x_13_; 
v___x_13_ = ((lean_object*)(l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2___closed__1));
return v___x_13_;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object* v_as_x27_43_, lean_object* v_b_44_){
_start:
{
if (lean_obj_tag(v_as_x27_43_) == 0)
{
lean_object* v___x_46_; 
v___x_46_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_46_, 0, v_b_44_);
return v___x_46_;
}
else
{
lean_object* v_head_47_; lean_object* v_tail_48_; lean_object* v___x_49_; 
v_head_47_ = lean_ctor_get(v_as_x27_43_, 0);
v_tail_48_ = lean_ctor_get(v_as_x27_43_, 1);
v___x_49_ = lp_TensorLib_Float32_ofLEByteArray(v_head_47_);
if (lean_obj_tag(v___x_49_) == 0)
{
lean_object* v_a_50_; lean_object* v___x_52_; uint8_t v_isShared_53_; uint8_t v_isSharedCheck_58_; 
v_a_50_ = lean_ctor_get(v___x_49_, 0);
v_isSharedCheck_58_ = !lean_is_exclusive(v___x_49_);
if (v_isSharedCheck_58_ == 0)
{
v___x_52_ = v___x_49_;
v_isShared_53_ = v_isSharedCheck_58_;
goto v_resetjp_51_;
}
else
{
lean_inc(v_a_50_);
lean_dec(v___x_49_);
v___x_52_ = lean_box(0);
v_isShared_53_ = v_isSharedCheck_58_;
goto v_resetjp_51_;
}
v_resetjp_51_:
{
lean_object* v___x_55_; 
if (v_isShared_53_ == 0)
{
lean_ctor_set_tag(v___x_52_, 18);
v___x_55_ = v___x_52_;
goto v_reusejp_54_;
}
else
{
lean_object* v_reuseFailAlloc_57_; 
v_reuseFailAlloc_57_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v_reuseFailAlloc_57_, 0, v_a_50_);
v___x_55_ = v_reuseFailAlloc_57_;
goto v_reusejp_54_;
}
v_reusejp_54_:
{
lean_object* v___x_56_; 
v___x_56_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_56_, 0, v___x_55_);
return v___x_56_;
}
}
}
else
{
lean_object* v_a_59_; lean_object* v___x_60_; float v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; 
v_a_59_ = lean_ctor_get(v___x_49_, 0);
lean_inc(v_a_59_);
lean_dec_ref_known(v___x_49_, 1);
v___x_60_ = lean_unsigned_to_nat(0u);
v___x_61_ = lean_unbox_float32(v_a_59_);
lean_dec(v_a_59_);
v___x_62_ = l_Float32_repr(v___x_61_, v___x_60_);
v___x_63_ = lp_batteries_IO_println___at___00Lean_printTraces___at___00Batteries_Tactic_Lint_lintCore_spec__5_spec__10(v___x_62_);
if (lean_obj_tag(v___x_63_) == 0)
{
lean_object* v___x_64_; 
lean_dec_ref_known(v___x_63_, 1);
v___x_64_ = lean_box(0);
v_as_x27_43_ = v_tail_48_;
v_b_44_ = v___x_64_;
goto _start;
}
else
{
return v___x_63_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object* v_as_x27_66_, lean_object* v_b_67_, lean_object* v___y_68_){
_start:
{
lean_object* v_res_69_; 
v_res_69_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_as_x27_66_, v_b_67_);
lean_dec(v_as_x27_66_);
return v_res_69_;
}
}
static float _init_l_main___closed__1(void){
_start:
{
lean_object* v___x_71_; uint8_t v___x_72_; lean_object* v___x_73_; float v___x_74_; 
v___x_71_ = lean_unsigned_to_nat(1u);
v___x_72_ = 1;
v___x_73_ = lean_unsigned_to_nat(10u);
v___x_74_ = l_Float32_ofScientific(v___x_73_, v___x_72_, v___x_71_);
return v___x_74_;
}
}
static float _init_l_main___closed__2(void){
_start:
{
lean_object* v___x_75_; uint8_t v___x_76_; lean_object* v___x_77_; float v___x_78_; 
v___x_75_ = lean_unsigned_to_nat(1u);
v___x_76_ = 1;
v___x_77_ = lean_unsigned_to_nat(20u);
v___x_78_ = l_Float32_ofScientific(v___x_77_, v___x_76_, v___x_75_);
return v___x_78_;
}
}
static float _init_l_main___closed__3(void){
_start:
{
lean_object* v___x_79_; uint8_t v___x_80_; lean_object* v___x_81_; float v___x_82_; 
v___x_79_ = lean_unsigned_to_nat(1u);
v___x_80_ = 1;
v___x_81_ = lean_unsigned_to_nat(30u);
v___x_82_ = l_Float32_ofScientific(v___x_81_, v___x_80_, v___x_79_);
return v___x_82_;
}
}
static float _init_l_main___closed__4(void){
_start:
{
lean_object* v___x_83_; uint8_t v___x_84_; lean_object* v___x_85_; float v___x_86_; 
v___x_83_ = lean_unsigned_to_nat(1u);
v___x_84_ = 1;
v___x_85_ = lean_unsigned_to_nat(40u);
v___x_86_ = l_Float32_ofScientific(v___x_85_, v___x_84_, v___x_83_);
return v___x_86_;
}
}
static lean_object* _init_l_main___closed__5___boxed__const__1(void){
_start:
{
float v___x_87_; lean_object* v___x_88_; 
v___x_87_ = lean_float32_once(&l_main___closed__4, &l_main___closed__4_once, _init_l_main___closed__4);
v___x_88_ = lean_box_float32(v___x_87_);
return v___x_88_;
}
}
static lean_object* _init_l_main___closed__5(void){
_start:
{
lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; 
v___x_89_ = lean_box(0);
v___x_90_ = l_main___closed__5___boxed__const__1;
v___x_91_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_91_, 0, v___x_90_);
lean_ctor_set(v___x_91_, 1, v___x_89_);
return v___x_91_;
}
}
static lean_object* _init_l_main___closed__6___boxed__const__1(void){
_start:
{
float v___x_92_; lean_object* v___x_93_; 
v___x_92_ = lean_float32_once(&l_main___closed__3, &l_main___closed__3_once, _init_l_main___closed__3);
v___x_93_ = lean_box_float32(v___x_92_);
return v___x_93_;
}
}
static lean_object* _init_l_main___closed__6(void){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; 
v___x_94_ = lean_obj_once(&l_main___closed__5, &l_main___closed__5_once, _init_l_main___closed__5);
v___x_95_ = l_main___closed__6___boxed__const__1;
v___x_96_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_96_, 0, v___x_95_);
lean_ctor_set(v___x_96_, 1, v___x_94_);
return v___x_96_;
}
}
static lean_object* _init_l_main___closed__7___boxed__const__1(void){
_start:
{
float v___x_97_; lean_object* v___x_98_; 
v___x_97_ = lean_float32_once(&l_main___closed__2, &l_main___closed__2_once, _init_l_main___closed__2);
v___x_98_ = lean_box_float32(v___x_97_);
return v___x_98_;
}
}
static lean_object* _init_l_main___closed__7(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; 
v___x_99_ = lean_obj_once(&l_main___closed__6, &l_main___closed__6_once, _init_l_main___closed__6);
v___x_100_ = l_main___closed__7___boxed__const__1;
v___x_101_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_101_, 0, v___x_100_);
lean_ctor_set(v___x_101_, 1, v___x_99_);
return v___x_101_;
}
}
static lean_object* _init_l_main___closed__8___boxed__const__1(void){
_start:
{
float v___x_102_; lean_object* v___x_103_; 
v___x_102_ = lean_float32_once(&l_main___closed__1, &l_main___closed__1_once, _init_l_main___closed__1);
v___x_103_ = lean_box_float32(v___x_102_);
return v___x_103_;
}
}
static lean_object* _init_l_main___closed__8(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; lean_object* v___x_106_; 
v___x_104_ = lean_obj_once(&l_main___closed__7, &l_main___closed__7_once, _init_l_main___closed__7);
v___x_105_ = l_main___closed__8___boxed__const__1;
v___x_106_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_106_, 0, v___x_105_);
lean_ctor_set(v___x_106_, 1, v___x_104_);
return v___x_106_;
}
}
static lean_object* _init_l_main___closed__9(void){
_start:
{
lean_object* v___x_107_; lean_object* v___x_108_; 
v___x_107_ = lean_obj_once(&l_main___closed__8, &l_main___closed__8_once, _init_l_main___closed__8);
v___x_108_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_107_);
return v___x_108_;
}
}
static lean_object* _init_l_main___closed__12(void){
_start:
{
lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; 
v___x_115_ = ((lean_object*)(l_main___closed__11));
v___x_116_ = lean_obj_once(&l_main___closed__9, &l_main___closed__9_once, _init_l_main___closed__9);
v___x_117_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v___x_116_, v___x_115_);
return v___x_117_;
}
}
static float _init_l_main___closed__13(void){
_start:
{
lean_object* v___x_118_; uint8_t v___x_119_; lean_object* v___x_120_; float v___x_121_; 
v___x_118_ = lean_unsigned_to_nat(1u);
v___x_119_ = 1;
v___x_120_ = lean_unsigned_to_nat(50u);
v___x_121_ = l_Float32_ofScientific(v___x_120_, v___x_119_, v___x_118_);
return v___x_121_;
}
}
static float _init_l_main___closed__14(void){
_start:
{
lean_object* v___x_122_; uint8_t v___x_123_; lean_object* v___x_124_; float v___x_125_; 
v___x_122_ = lean_unsigned_to_nat(1u);
v___x_123_ = 1;
v___x_124_ = lean_unsigned_to_nat(60u);
v___x_125_ = l_Float32_ofScientific(v___x_124_, v___x_123_, v___x_122_);
return v___x_125_;
}
}
static float _init_l_main___closed__15(void){
_start:
{
lean_object* v___x_126_; uint8_t v___x_127_; lean_object* v___x_128_; float v___x_129_; 
v___x_126_ = lean_unsigned_to_nat(1u);
v___x_127_ = 1;
v___x_128_ = lean_unsigned_to_nat(70u);
v___x_129_ = l_Float32_ofScientific(v___x_128_, v___x_127_, v___x_126_);
return v___x_129_;
}
}
static float _init_l_main___closed__16(void){
_start:
{
lean_object* v___x_130_; uint8_t v___x_131_; lean_object* v___x_132_; float v___x_133_; 
v___x_130_ = lean_unsigned_to_nat(1u);
v___x_131_ = 1;
v___x_132_ = lean_unsigned_to_nat(80u);
v___x_133_ = l_Float32_ofScientific(v___x_132_, v___x_131_, v___x_130_);
return v___x_133_;
}
}
static lean_object* _init_l_main___closed__17___boxed__const__1(void){
_start:
{
float v___x_134_; lean_object* v___x_135_; 
v___x_134_ = lean_float32_once(&l_main___closed__16, &l_main___closed__16_once, _init_l_main___closed__16);
v___x_135_ = lean_box_float32(v___x_134_);
return v___x_135_;
}
}
static lean_object* _init_l_main___closed__17(void){
_start:
{
lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; 
v___x_136_ = lean_box(0);
v___x_137_ = l_main___closed__17___boxed__const__1;
v___x_138_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_138_, 0, v___x_137_);
lean_ctor_set(v___x_138_, 1, v___x_136_);
return v___x_138_;
}
}
static lean_object* _init_l_main___closed__18___boxed__const__1(void){
_start:
{
float v___x_139_; lean_object* v___x_140_; 
v___x_139_ = lean_float32_once(&l_main___closed__15, &l_main___closed__15_once, _init_l_main___closed__15);
v___x_140_ = lean_box_float32(v___x_139_);
return v___x_140_;
}
}
static lean_object* _init_l_main___closed__18(void){
_start:
{
lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v___x_143_; 
v___x_141_ = lean_obj_once(&l_main___closed__17, &l_main___closed__17_once, _init_l_main___closed__17);
v___x_142_ = l_main___closed__18___boxed__const__1;
v___x_143_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_143_, 0, v___x_142_);
lean_ctor_set(v___x_143_, 1, v___x_141_);
return v___x_143_;
}
}
static lean_object* _init_l_main___closed__19___boxed__const__1(void){
_start:
{
float v___x_144_; lean_object* v___x_145_; 
v___x_144_ = lean_float32_once(&l_main___closed__14, &l_main___closed__14_once, _init_l_main___closed__14);
v___x_145_ = lean_box_float32(v___x_144_);
return v___x_145_;
}
}
static lean_object* _init_l_main___closed__19(void){
_start:
{
lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; 
v___x_146_ = lean_obj_once(&l_main___closed__18, &l_main___closed__18_once, _init_l_main___closed__18);
v___x_147_ = l_main___closed__19___boxed__const__1;
v___x_148_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_148_, 0, v___x_147_);
lean_ctor_set(v___x_148_, 1, v___x_146_);
return v___x_148_;
}
}
static lean_object* _init_l_main___closed__20___boxed__const__1(void){
_start:
{
float v___x_149_; lean_object* v___x_150_; 
v___x_149_ = lean_float32_once(&l_main___closed__13, &l_main___closed__13_once, _init_l_main___closed__13);
v___x_150_ = lean_box_float32(v___x_149_);
return v___x_150_;
}
}
static lean_object* _init_l_main___closed__20(void){
_start:
{
lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; 
v___x_151_ = lean_obj_once(&l_main___closed__19, &l_main___closed__19_once, _init_l_main___closed__19);
v___x_152_ = l_main___closed__20___boxed__const__1;
v___x_153_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_153_, 0, v___x_152_);
lean_ctor_set(v___x_153_, 1, v___x_151_);
return v___x_153_;
}
}
static lean_object* _init_l_main___closed__21(void){
_start:
{
lean_object* v___x_154_; lean_object* v___x_155_; 
v___x_154_ = lean_obj_once(&l_main___closed__20, &l_main___closed__20_once, _init_l_main___closed__20);
v___x_155_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_154_);
return v___x_155_;
}
}
static lean_object* _init_l_main___closed__22(void){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; 
v___x_156_ = ((lean_object*)(l_main___closed__11));
v___x_157_ = lean_obj_once(&l_main___closed__21, &l_main___closed__21_once, _init_l_main___closed__21);
v___x_158_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v___x_157_, v___x_156_);
return v___x_158_;
}
}
static lean_object* _init_l_main___closed__23(void){
_start:
{
lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; 
v___x_159_ = lean_obj_once(&l_main___closed__22, &l_main___closed__22_once, _init_l_main___closed__22);
v___x_160_ = lean_obj_once(&l_main___closed__12, &l_main___closed__12_once, _init_l_main___closed__12);
v___x_161_ = l___private_examples_l__to__mlir_l__to__mlir1_0__matmul2(v___x_160_, v___x_159_);
return v___x_161_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_163_ = ((lean_object*)(l_main___closed__0));
v___x_164_ = lp_batteries_IO_println___at___00Batteries_Tactic_Lint_lintCore_spec__4(v___x_163_);
if (lean_obj_tag(v___x_164_) == 0)
{
lean_object* v___x_166_; uint8_t v_isShared_167_; uint8_t v_isSharedCheck_198_; 
v_isSharedCheck_198_ = !lean_is_exclusive(v___x_164_);
if (v_isSharedCheck_198_ == 0)
{
lean_object* v_unused_199_; 
v_unused_199_ = lean_ctor_get(v___x_164_, 0);
lean_dec(v_unused_199_);
v___x_166_ = v___x_164_;
v_isShared_167_ = v_isSharedCheck_198_;
goto v_resetjp_165_;
}
else
{
lean_dec(v___x_164_);
v___x_166_ = lean_box(0);
v_isShared_167_ = v_isSharedCheck_198_;
goto v_resetjp_165_;
}
v_resetjp_165_:
{
lean_object* v___x_168_; 
v___x_168_ = lean_obj_once(&l_main___closed__23, &l_main___closed__23_once, _init_l_main___closed__23);
if (lean_obj_tag(v___x_168_) == 0)
{
lean_object* v_a_169_; lean_object* v___x_170_; lean_object* v___x_172_; 
v_a_169_ = lean_ctor_get(v___x_168_, 0);
lean_inc(v_a_169_);
v___x_170_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v___x_170_, 0, v_a_169_);
if (v_isShared_167_ == 0)
{
lean_ctor_set_tag(v___x_166_, 1);
lean_ctor_set(v___x_166_, 0, v___x_170_);
v___x_172_ = v___x_166_;
goto v_reusejp_171_;
}
else
{
lean_object* v_reuseFailAlloc_173_; 
v_reuseFailAlloc_173_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_173_, 0, v___x_170_);
v___x_172_ = v_reuseFailAlloc_173_;
goto v_reusejp_171_;
}
v_reusejp_171_:
{
return v___x_172_;
}
}
else
{
lean_object* v_a_174_; lean_object* v___x_175_; 
v_a_174_ = lean_ctor_get(v___x_168_, 0);
lean_inc(v_a_174_);
v___x_175_ = lp_TensorLib_TensorLib_Tensor_toList(v_a_174_);
if (lean_obj_tag(v___x_175_) == 0)
{
lean_object* v_a_176_; lean_object* v___x_178_; uint8_t v_isShared_179_; uint8_t v_isSharedCheck_186_; 
v_a_176_ = lean_ctor_get(v___x_175_, 0);
v_isSharedCheck_186_ = !lean_is_exclusive(v___x_175_);
if (v_isSharedCheck_186_ == 0)
{
v___x_178_ = v___x_175_;
v_isShared_179_ = v_isSharedCheck_186_;
goto v_resetjp_177_;
}
else
{
lean_inc(v_a_176_);
lean_dec(v___x_175_);
v___x_178_ = lean_box(0);
v_isShared_179_ = v_isSharedCheck_186_;
goto v_resetjp_177_;
}
v_resetjp_177_:
{
lean_object* v___x_181_; 
if (v_isShared_179_ == 0)
{
lean_ctor_set_tag(v___x_178_, 18);
v___x_181_ = v___x_178_;
goto v_reusejp_180_;
}
else
{
lean_object* v_reuseFailAlloc_185_; 
v_reuseFailAlloc_185_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v_reuseFailAlloc_185_, 0, v_a_176_);
v___x_181_ = v_reuseFailAlloc_185_;
goto v_reusejp_180_;
}
v_reusejp_180_:
{
lean_object* v___x_183_; 
if (v_isShared_167_ == 0)
{
lean_ctor_set_tag(v___x_166_, 1);
lean_ctor_set(v___x_166_, 0, v___x_181_);
v___x_183_ = v___x_166_;
goto v_reusejp_182_;
}
else
{
lean_object* v_reuseFailAlloc_184_; 
v_reuseFailAlloc_184_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_184_, 0, v___x_181_);
v___x_183_ = v_reuseFailAlloc_184_;
goto v_reusejp_182_;
}
v_reusejp_182_:
{
return v___x_183_;
}
}
}
}
else
{
lean_object* v_a_187_; lean_object* v___x_188_; lean_object* v___x_189_; 
lean_del_object(v___x_166_);
v_a_187_ = lean_ctor_get(v___x_175_, 0);
lean_inc(v_a_187_);
lean_dec_ref_known(v___x_175_, 1);
v___x_188_ = lean_box(0);
v___x_189_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_a_187_, v___x_188_);
lean_dec(v_a_187_);
if (lean_obj_tag(v___x_189_) == 0)
{
lean_object* v___x_191_; uint8_t v_isShared_192_; uint8_t v_isSharedCheck_196_; 
v_isSharedCheck_196_ = !lean_is_exclusive(v___x_189_);
if (v_isSharedCheck_196_ == 0)
{
lean_object* v_unused_197_; 
v_unused_197_ = lean_ctor_get(v___x_189_, 0);
lean_dec(v_unused_197_);
v___x_191_ = v___x_189_;
v_isShared_192_ = v_isSharedCheck_196_;
goto v_resetjp_190_;
}
else
{
lean_dec(v___x_189_);
v___x_191_ = lean_box(0);
v_isShared_192_ = v_isSharedCheck_196_;
goto v_resetjp_190_;
}
v_resetjp_190_:
{
lean_object* v___x_194_; 
if (v_isShared_192_ == 0)
{
lean_ctor_set(v___x_191_, 0, v___x_188_);
v___x_194_ = v___x_191_;
goto v_reusejp_193_;
}
else
{
lean_object* v_reuseFailAlloc_195_; 
v_reuseFailAlloc_195_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_195_, 0, v___x_188_);
v___x_194_ = v_reuseFailAlloc_195_;
goto v_reusejp_193_;
}
v_reusejp_193_:
{
return v___x_194_;
}
}
}
else
{
return v___x_189_;
}
}
}
}
}
else
{
return v___x_164_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_200_){
_start:
{
lean_object* v_res_201_; 
v_res_201_ = _lean_main();
return v_res_201_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0(lean_object* v_as_202_, lean_object* v_as_x27_203_, lean_object* v_b_204_, lean_object* v_a_205_){
_start:
{
lean_object* v___x_207_; 
v___x_207_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_as_x27_203_, v_b_204_);
return v___x_207_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object* v_as_208_, lean_object* v_as_x27_209_, lean_object* v_b_210_, lean_object* v_a_211_, lean_object* v___y_212_){
_start:
{
lean_object* v_res_213_; 
v_res_213_ = l_List_forIn_x27_loop___at___00main_spec__0(v_as_208_, v_as_x27_209_, v_b_210_, v_a_211_);
lean_dec(v_as_x27_209_);
lean_dec(v_as_208_);
return v_res_213_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_TensorLib_TensorLib(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_examples_l__to__mlir_l__to__mlir1(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_TensorLib_TensorLib(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_main___closed__5___boxed__const__1 = _init_l_main___closed__5___boxed__const__1();
lean_mark_persistent(l_main___closed__5___boxed__const__1);
l_main___closed__6___boxed__const__1 = _init_l_main___closed__6___boxed__const__1();
lean_mark_persistent(l_main___closed__6___boxed__const__1);
l_main___closed__7___boxed__const__1 = _init_l_main___closed__7___boxed__const__1();
lean_mark_persistent(l_main___closed__7___boxed__const__1);
l_main___closed__8___boxed__const__1 = _init_l_main___closed__8___boxed__const__1();
lean_mark_persistent(l_main___closed__8___boxed__const__1);
l_main___closed__17___boxed__const__1 = _init_l_main___closed__17___boxed__const__1();
lean_mark_persistent(l_main___closed__17___boxed__const__1);
l_main___closed__18___boxed__const__1 = _init_l_main___closed__18___boxed__const__1();
lean_mark_persistent(l_main___closed__18___boxed__const__1);
l_main___closed__19___boxed__const__1 = _init_l_main___closed__19___boxed__const__1();
lean_mark_persistent(l_main___closed__19___boxed__const__1);
l_main___closed__20___boxed__const__1 = _init_l_main___closed__20___boxed__const__1();
lean_mark_persistent(l_main___closed__20___boxed__const__1);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
void lean_initialize();
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif
lean_object* run_main(int argc, char ** argv) {
    return _lean_main();
}
int main(int argc, char ** argv) {
#if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
#endif
  lean_object* res;
  argv = lean_setup_args(argc, argv);
  lean_initialize();
  res = initialize_examples_l__to__mlir_l__to__mlir1(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = 0;
    lean_dec_ref(res);
    return ret;
  } else {
    lean_io_result_show_error(res);
    lean_dec_ref(res);
    return 1;
  }
}
#ifdef __cplusplus
}
#endif
