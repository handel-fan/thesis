// Lean compiler output
// Module: examples.l_to_mlir.ltom_probe
// Imports: public import Init public meta import Init public import LtomProbeSupport public import TensorLib
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
lean_object* lp_TensorLib_Float32_ofLEByteArray(lean_object*);
lean_object* lean_mk_io_user_error(lean_object*);
lean_object* l_Float32_repr(float, lean_object*);
lean_object* lp_batteries_IO_println___at___00Lean_printTraces___at___00Batteries_Tactic_Lint_lintCore_spec__5_spec__10(lean_object*);
lean_object* lp_batteries_IO_println___at___00Batteries_Tactic_Lint_lintCore_spec__4(lean_object*);
float l_Float32_ofScientific(lean_object*, uint8_t, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_reshape_x21(lean_object*, lean_object*);
uint8_t lp_TensorLib_TensorLib_instBEqDtype_beq(uint8_t, uint8_t);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_zeros(uint8_t, lean_object*);
lean_object* lp_TensorLib___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_TensorLib_Ufunc_0__TensorLib_Tensor_Ufunc_matmul2_spec__2___redArg(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_toList(lean_object*);
LEAN_EXPORT lean_object* l___private_examples_l__to__mlir_ltom__probe_0__matmul2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_examples_l__to__mlir_ltom__probe_0__matmul2(lean_object* v_x_1_, lean_object* v_y_2_){
_start:
{
uint8_t v_dtype_6_; lean_object* v_shape_7_; uint8_t v_dtype_8_; lean_object* v_shape_9_; uint8_t v___x_10_; 
v_dtype_6_ = lean_ctor_get_uint8(v_x_1_, sizeof(void*)*4);
v_shape_7_ = lean_ctor_get(v_x_1_, 0);
v_dtype_8_ = lean_ctor_get_uint8(v_y_2_, sizeof(void*)*4);
v_shape_9_ = lean_ctor_get(v_y_2_, 0);
v___x_10_ = lp_TensorLib_TensorLib_instBEqDtype_beq(v_dtype_6_, v_dtype_8_);
if (v___x_10_ == 0)
{
lean_object* v___x_11_; lean_object* v___x_12_; 
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
v___x_11_ = lean_mk_string_unchecked("Expected same dtype", 19, 19);
v___x_12_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_12_, 0, v___x_11_);
return v___x_12_;
}
else
{
if (lean_obj_tag(v_shape_7_) == 1)
{
lean_object* v_tail_13_; 
v_tail_13_ = lean_ctor_get(v_shape_7_, 1);
if (lean_obj_tag(v_tail_13_) == 1)
{
lean_object* v_tail_14_; 
v_tail_14_ = lean_ctor_get(v_tail_13_, 1);
if (lean_obj_tag(v_tail_14_) == 0)
{
if (lean_obj_tag(v_shape_9_) == 1)
{
lean_object* v_tail_15_; 
v_tail_15_ = lean_ctor_get(v_shape_9_, 1);
if (lean_obj_tag(v_tail_15_) == 1)
{
lean_object* v_tail_16_; 
v_tail_16_ = lean_ctor_get(v_tail_15_, 1);
lean_inc(v_tail_16_);
if (lean_obj_tag(v_tail_16_) == 0)
{
lean_object* v_head_17_; lean_object* v_head_18_; lean_object* v_head_19_; lean_object* v_head_20_; uint8_t v___x_21_; 
v_head_17_ = lean_ctor_get(v_shape_7_, 0);
v_head_18_ = lean_ctor_get(v_tail_13_, 0);
lean_inc(v_head_18_);
v_head_19_ = lean_ctor_get(v_shape_9_, 0);
v_head_20_ = lean_ctor_get(v_tail_15_, 0);
lean_inc(v_head_20_);
v___x_21_ = lean_nat_dec_eq(v_head_18_, v_head_19_);
if (v___x_21_ == 0)
{
lean_object* v___x_22_; lean_object* v___x_23_; 
lean_dec(v_head_20_);
lean_dec(v_head_18_);
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
v___x_22_ = lean_mk_string_unchecked("matmul2: reduction dimension mismatch", 37, 37);
v___x_23_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_23_, 0, v___x_22_);
return v___x_23_;
}
else
{
lean_object* v___x_24_; lean_object* v_res_25_; lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; 
lean_inc_ref(v_tail_15_);
lean_inc_n(v_head_17_, 2);
v___x_24_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_24_, 0, v_head_17_);
lean_ctor_set(v___x_24_, 1, v_tail_15_);
v_res_25_ = lp_TensorLib_TensorLib_Tensor_zeros(v_dtype_6_, v___x_24_);
v___x_26_ = lean_unsigned_to_nat(0u);
v___x_27_ = lean_unsigned_to_nat(1u);
v___x_28_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_28_, 0, v___x_26_);
lean_ctor_set(v___x_28_, 1, v_head_17_);
lean_ctor_set(v___x_28_, 2, v___x_27_);
v___x_29_ = lp_TensorLib___private_Init_Data_Range_Basic_0__Std_Legacy_Range_forIn_x27_loop___at___00__private_TensorLib_Ufunc_0__TensorLib_Tensor_Ufunc_matmul2_spec__2___redArg(v_tail_16_, v_x_1_, v_y_2_, v_dtype_6_, v_head_18_, v_head_20_, v___x_28_, v_res_25_, v___x_26_);
lean_dec_ref_known(v___x_28_, 3);
return v___x_29_;
}
}
else
{
lean_dec(v_tail_16_);
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
else
{
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
else
{
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
else
{
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
else
{
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
else
{
lean_dec_ref(v_y_2_);
lean_dec_ref(v_x_1_);
goto v___jp_3_;
}
}
v___jp_3_:
{
lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_4_ = lean_mk_string_unchecked("Expected 2d arrays", 18, 18);
v___x_5_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_5_, 0, v___x_4_);
return v___x_5_;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg(lean_object* v_as_x27_30_, lean_object* v_b_31_){
_start:
{
lean_object* v_a_34_; 
if (lean_obj_tag(v_as_x27_30_) == 0)
{
lean_object* v___x_36_; 
v___x_36_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_36_, 0, v_b_31_);
return v___x_36_;
}
else
{
lean_object* v_head_37_; lean_object* v_tail_38_; lean_object* v___x_39_; 
v_head_37_ = lean_ctor_get(v_as_x27_30_, 0);
v_tail_38_ = lean_ctor_get(v_as_x27_30_, 1);
v___x_39_ = lp_TensorLib_Float32_ofLEByteArray(v_head_37_);
if (lean_obj_tag(v___x_39_) == 0)
{
lean_object* v_a_40_; lean_object* v___x_41_; 
v_a_40_ = lean_ctor_get(v___x_39_, 0);
lean_inc(v_a_40_);
lean_dec_ref_known(v___x_39_, 1);
v___x_41_ = lean_mk_io_user_error(v_a_40_);
v_a_34_ = v___x_41_;
goto v___jp_33_;
}
else
{
lean_object* v_a_42_; lean_object* v___x_43_; float v___x_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
v_a_42_ = lean_ctor_get(v___x_39_, 0);
lean_inc(v_a_42_);
lean_dec_ref_known(v___x_39_, 1);
v___x_43_ = lean_unsigned_to_nat(0u);
v___x_44_ = lean_unbox_float32(v_a_42_);
lean_dec(v_a_42_);
v___x_45_ = l_Float32_repr(v___x_44_, v___x_43_);
v___x_46_ = lp_batteries_IO_println___at___00Lean_printTraces___at___00Batteries_Tactic_Lint_lintCore_spec__5_spec__10(v___x_45_);
if (lean_obj_tag(v___x_46_) == 0)
{
lean_object* v___x_47_; 
lean_dec_ref_known(v___x_46_, 1);
v___x_47_ = lean_box(0);
v_as_x27_30_ = v_tail_38_;
v_b_31_ = v___x_47_;
goto _start;
}
else
{
lean_object* v_a_49_; 
v_a_49_ = lean_ctor_get(v___x_46_, 0);
lean_inc(v_a_49_);
lean_dec_ref_known(v___x_46_, 1);
v_a_34_ = v_a_49_;
goto v___jp_33_;
}
}
}
v___jp_33_:
{
lean_object* v___x_35_; 
v___x_35_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_35_, 0, v_a_34_);
return v___x_35_;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___redArg___boxed(lean_object* v_as_x27_50_, lean_object* v_b_51_, lean_object* v___y_52_){
_start:
{
lean_object* v_res_53_; 
v_res_53_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_as_x27_50_, v_b_51_);
lean_dec(v_as_x27_50_);
return v_res_53_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = lean_mk_string_unchecked("Starting l_to_mlir1.lean", 24, 24);
v___x_56_ = lp_batteries_IO_println___at___00Batteries_Tactic_Lint_lintCore_spec__4(v___x_55_);
if (lean_obj_tag(v___x_56_) == 0)
{
lean_object* v___x_57_; uint8_t v___x_58_; lean_object* v___x_59_; float v___x_60_; lean_object* v___x_61_; float v___x_62_; lean_object* v___x_63_; float v___x_64_; lean_object* v___x_65_; float v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; float v___x_82_; lean_object* v___x_83_; float v___x_84_; lean_object* v___x_85_; float v___x_86_; lean_object* v___x_87_; float v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; 
lean_dec_ref_known(v___x_56_, 1);
v___x_57_ = lean_unsigned_to_nat(10u);
v___x_58_ = 1;
v___x_59_ = lean_unsigned_to_nat(1u);
v___x_60_ = l_Float32_ofScientific(v___x_57_, v___x_58_, v___x_59_);
v___x_61_ = lean_unsigned_to_nat(20u);
v___x_62_ = l_Float32_ofScientific(v___x_61_, v___x_58_, v___x_59_);
v___x_63_ = lean_unsigned_to_nat(30u);
v___x_64_ = l_Float32_ofScientific(v___x_63_, v___x_58_, v___x_59_);
v___x_65_ = lean_unsigned_to_nat(40u);
v___x_66_ = l_Float32_ofScientific(v___x_65_, v___x_58_, v___x_59_);
v___x_67_ = lean_box(0);
v___x_68_ = lean_box_float32(v___x_66_);
v___x_69_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_69_, 0, v___x_68_);
lean_ctor_set(v___x_69_, 1, v___x_67_);
v___x_70_ = lean_box_float32(v___x_64_);
v___x_71_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_71_, 0, v___x_70_);
lean_ctor_set(v___x_71_, 1, v___x_69_);
v___x_72_ = lean_box_float32(v___x_62_);
v___x_73_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_73_, 0, v___x_72_);
lean_ctor_set(v___x_73_, 1, v___x_71_);
v___x_74_ = lean_box_float32(v___x_60_);
v___x_75_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_75_, 0, v___x_74_);
lean_ctor_set(v___x_75_, 1, v___x_73_);
v___x_76_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_75_);
lean_dec_ref_known(v___x_75_, 2);
v___x_77_ = lean_unsigned_to_nat(2u);
v___x_78_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_78_, 0, v___x_77_);
lean_ctor_set(v___x_78_, 1, v___x_67_);
v___x_79_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_79_, 0, v___x_77_);
lean_ctor_set(v___x_79_, 1, v___x_78_);
lean_inc_ref(v___x_79_);
v___x_80_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v___x_76_, v___x_79_);
v___x_81_ = lean_unsigned_to_nat(50u);
v___x_82_ = l_Float32_ofScientific(v___x_81_, v___x_58_, v___x_59_);
v___x_83_ = lean_unsigned_to_nat(60u);
v___x_84_ = l_Float32_ofScientific(v___x_83_, v___x_58_, v___x_59_);
v___x_85_ = lean_unsigned_to_nat(70u);
v___x_86_ = l_Float32_ofScientific(v___x_85_, v___x_58_, v___x_59_);
v___x_87_ = lean_unsigned_to_nat(80u);
v___x_88_ = l_Float32_ofScientific(v___x_87_, v___x_58_, v___x_59_);
v___x_89_ = lean_box_float32(v___x_88_);
v___x_90_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_90_, 0, v___x_89_);
lean_ctor_set(v___x_90_, 1, v___x_67_);
v___x_91_ = lean_box_float32(v___x_86_);
v___x_92_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_92_, 0, v___x_91_);
lean_ctor_set(v___x_92_, 1, v___x_90_);
v___x_93_ = lean_box_float32(v___x_84_);
v___x_94_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_94_, 0, v___x_93_);
lean_ctor_set(v___x_94_, 1, v___x_92_);
v___x_95_ = lean_box_float32(v___x_82_);
v___x_96_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_96_, 0, v___x_95_);
lean_ctor_set(v___x_96_, 1, v___x_94_);
v___x_97_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_96_);
lean_dec_ref_known(v___x_96_, 2);
v___x_98_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v___x_97_, v___x_79_);
v___x_99_ = l___private_examples_l__to__mlir_ltom__probe_0__matmul2(v___x_80_, v___x_98_);
if (lean_obj_tag(v___x_99_) == 0)
{
lean_object* v_a_100_; lean_object* v___x_101_; lean_object* v___x_102_; 
v_a_100_ = lean_ctor_get(v___x_99_, 0);
lean_inc(v_a_100_);
lean_dec_ref_known(v___x_99_, 1);
v___x_101_ = lean_mk_io_user_error(v_a_100_);
v___x_102_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_102_, 0, v___x_101_);
return v___x_102_;
}
else
{
lean_object* v_a_103_; lean_object* v___x_104_; 
v_a_103_ = lean_ctor_get(v___x_99_, 0);
lean_inc(v_a_103_);
lean_dec_ref_known(v___x_99_, 1);
v___x_104_ = lp_TensorLib_TensorLib_Tensor_toList(v_a_103_);
if (lean_obj_tag(v___x_104_) == 0)
{
lean_object* v_a_105_; lean_object* v___x_106_; lean_object* v___x_107_; 
v_a_105_ = lean_ctor_get(v___x_104_, 0);
lean_inc(v_a_105_);
lean_dec_ref_known(v___x_104_, 1);
v___x_106_ = lean_mk_io_user_error(v_a_105_);
v___x_107_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_107_, 0, v___x_106_);
return v___x_107_;
}
else
{
lean_object* v_a_108_; lean_object* v___x_109_; lean_object* v___x_110_; 
v_a_108_ = lean_ctor_get(v___x_104_, 0);
lean_inc(v_a_108_);
lean_dec_ref_known(v___x_104_, 1);
v___x_109_ = lean_box(0);
v___x_110_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_a_108_, v___x_109_);
lean_dec(v_a_108_);
if (lean_obj_tag(v___x_110_) == 0)
{
lean_object* v___x_111_; 
lean_dec_ref_known(v___x_110_, 1);
v___x_111_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_111_, 0, v___x_109_);
return v___x_111_;
}
else
{
return v___x_110_;
}
}
}
}
else
{
return v___x_56_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_112_){
_start:
{
lean_object* v_res_113_; 
v_res_113_ = _lean_main();
return v_res_113_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0(lean_object* v_as_114_, lean_object* v_as_x27_115_, lean_object* v_b_116_, lean_object* v_a_117_){
_start:
{
lean_object* v___x_119_; 
v___x_119_ = l_List_forIn_x27_loop___at___00main_spec__0___redArg(v_as_x27_115_, v_b_116_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00main_spec__0___boxed(lean_object* v_as_120_, lean_object* v_as_x27_121_, lean_object* v_b_122_, lean_object* v_a_123_, lean_object* v___y_124_){
_start:
{
lean_object* v_res_125_; 
v_res_125_ = l_List_forIn_x27_loop___at___00main_spec__0(v_as_120_, v_as_x27_121_, v_b_122_, v_a_123_);
lean_dec(v_as_x27_121_);
lean_dec(v_as_120_);
return v_res_125_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LtomProbeSupport(uint8_t builtin);
lean_object* initialize_TensorLib_TensorLib(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_examples_l__to__mlir_ltom__probe(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LtomProbeSupport(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_TensorLib_TensorLib(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
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
  res = initialize_examples_l__to__mlir_ltom__probe(1 /* builtin */);
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
