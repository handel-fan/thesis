// Lean compiler output
// Module: experiments.tensor_tag_tensorlib_lcnf_experiment.Main
// Imports: public import Init public meta import Init public import Probe public import TensorLib.Ufunc
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
float lean_float32_of_nat(lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(lean_object*);
extern lean_object* l_TensorTagProbe_tensorTagPass;
lean_object* l_Lean_Compiler_LCNF_PassInstaller_installAtEnd(uint8_t, lean_object*);
extern lean_object* lp_TensorLib_TensorLib_instInhabitedTensor_default;
lean_object* lp_TensorLib_TensorLib_Tensor_Ufunc_matmul(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_get_x21___redArg(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_reshape_x21(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_toFloat32Tree_x21(lean_object*);
uint8_t lean_float32_beq(float, float);
lean_object* l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(lean_object*);
static lean_once_cell_t l_installTensorTagPass___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_installTensorTagPass___closed__0;
LEAN_EXPORT lean_object* l_installTensorTagPass;
LEAN_EXPORT lean_object* l_tensorTag___redArg(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag(lean_object*, lean_object*, uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_matmul2x2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_taggedMatmul(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_taggedMatmul___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1___boxed(lean_object*, lean_object*);
static lean_once_cell_t l_main___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__0;
static lean_once_cell_t l_main___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__1;
static lean_once_cell_t l_main___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__2;
static lean_once_cell_t l_main___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__3;
LEAN_EXPORT lean_object* l_main___closed__4___boxed__const__1;
static lean_once_cell_t l_main___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__4;
LEAN_EXPORT lean_object* l_main___closed__5___boxed__const__1;
static lean_once_cell_t l_main___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__5;
LEAN_EXPORT lean_object* l_main___closed__6___boxed__const__1;
static lean_once_cell_t l_main___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__6;
LEAN_EXPORT lean_object* l_main___closed__7___boxed__const__1;
static lean_once_cell_t l_main___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__7;
static lean_once_cell_t l_main___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__8;
static const lean_ctor_object l_main___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_main___closed__9 = (const lean_object*)&l_main___closed__9_value;
static const lean_ctor_object l_main___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&l_main___closed__9_value)}};
static const lean_object* l_main___closed__10 = (const lean_object*)&l_main___closed__10_value;
static lean_once_cell_t l_main___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__11;
static lean_once_cell_t l_main___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__12;
static lean_once_cell_t l_main___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__13;
static lean_once_cell_t l_main___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__14;
static lean_once_cell_t l_main___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__15;
LEAN_EXPORT lean_object* l_main___closed__16___boxed__const__1;
static lean_once_cell_t l_main___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__16;
LEAN_EXPORT lean_object* l_main___closed__17___boxed__const__1;
static lean_once_cell_t l_main___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__17;
LEAN_EXPORT lean_object* l_main___closed__18___boxed__const__1;
static lean_once_cell_t l_main___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__18;
LEAN_EXPORT lean_object* l_main___closed__19___boxed__const__1;
static lean_once_cell_t l_main___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__19;
static lean_once_cell_t l_main___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__20;
static lean_once_cell_t l_main___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__21;
static lean_once_cell_t l_main___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__22;
static lean_once_cell_t l_main___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__23;
static lean_once_cell_t l_main___closed__24_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__24;
LEAN_EXPORT lean_object* l_main___closed__25___boxed__const__1;
static lean_once_cell_t l_main___closed__25_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__25;
LEAN_EXPORT lean_object* l_main___closed__26___boxed__const__1;
static lean_once_cell_t l_main___closed__26_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__26;
static lean_once_cell_t l_main___closed__27_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__27;
static lean_once_cell_t l_main___closed__28_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__28;
static lean_once_cell_t l_main___closed__29_once = LEAN_ONCE_CELL_INITIALIZER;
static float l_main___closed__29;
LEAN_EXPORT lean_object* l_main___closed__30___boxed__const__1;
static lean_once_cell_t l_main___closed__30_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__30;
LEAN_EXPORT lean_object* l_main___closed__31___boxed__const__1;
static lean_once_cell_t l_main___closed__31_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__31;
static lean_once_cell_t l_main___closed__32_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__32;
static lean_once_cell_t l_main___closed__33_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__33;
static lean_once_cell_t l_main___closed__34_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__34;
static lean_once_cell_t l_main___closed__35_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__35;
static lean_once_cell_t l_main___closed__36_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__36;
static lean_once_cell_t l_main___closed__37_once = LEAN_ONCE_CELL_INITIALIZER;
static uint8_t l_main___closed__37;
static const lean_string_object l_main___closed__38_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "incorrect TensorLib matmul result"};
static const lean_object* l_main___closed__38 = (const lean_object*)&l_main___closed__38_value;
static const lean_ctor_object l_main___closed__39_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_main___closed__38_value)}};
static const lean_object* l_main___closed__39 = (const lean_object*)&l_main___closed__39_value;
static const lean_string_object l_main___closed__40_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "TENSORLIB_OK"};
static const lean_object* l_main___closed__40 = (const lean_object*)&l_main___closed__40_value;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
static lean_object* _init_l_installTensorTagPass___closed__0(void){
_start:
{
lean_object* v___x_1_; uint8_t v___x_2_; lean_object* v___x_3_; 
v___x_1_ = l_TensorTagProbe_tensorTagPass;
v___x_2_ = 0;
v___x_3_ = l_Lean_Compiler_LCNF_PassInstaller_installAtEnd(v___x_2_, v___x_1_);
return v___x_3_;
}
}
static lean_object* _init_l_installTensorTagPass(void){
_start:
{
lean_object* v___x_4_; 
v___x_4_ = lean_obj_once(&l_installTensorTagPass___closed__0, &l_installTensorTagPass___closed__0_once, _init_l_installTensorTagPass___closed__0);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* l_tensorTag___redArg(lean_object* v_value_5_){
_start:
{
lean_inc_ref(v_value_5_);
return v_value_5_;
}
}
LEAN_EXPORT lean_object* l_tensorTag___redArg___boxed(lean_object* v_value_6_){
_start:
{
lean_object* v_res_7_; 
v_res_7_ = l_tensorTag___redArg(v_value_6_);
lean_dec_ref(v_value_6_);
return v_res_7_;
}
}
LEAN_EXPORT lean_object* l_tensorTag(lean_object* v_rows_8_, lean_object* v_cols_9_, uint8_t v_dtype_10_, lean_object* v_value_11_){
_start:
{
lean_object* v___x_12_; 
v___x_12_ = l_tensorTag___redArg(v_value_11_);
return v___x_12_;
}
}
LEAN_EXPORT lean_object* l_tensorTag___boxed(lean_object* v_rows_13_, lean_object* v_cols_14_, lean_object* v_dtype_15_, lean_object* v_value_16_){
_start:
{
uint8_t v_dtype_boxed_17_; lean_object* v_res_18_; 
v_dtype_boxed_17_ = lean_unbox(v_dtype_15_);
v_res_18_ = l_tensorTag(v_rows_13_, v_cols_14_, v_dtype_boxed_17_, v_value_16_);
lean_dec_ref(v_value_16_);
lean_dec(v_cols_14_);
lean_dec(v_rows_13_);
return v_res_18_;
}
}
LEAN_EXPORT lean_object* l_matmul2x2(lean_object* v_left_19_, lean_object* v_right_20_){
_start:
{
lean_object* v___x_21_; lean_object* v___x_22_; lean_object* v___x_23_; 
v___x_21_ = lp_TensorLib_TensorLib_instInhabitedTensor_default;
v___x_22_ = lp_TensorLib_TensorLib_Tensor_Ufunc_matmul(v_left_19_, v_right_20_);
v___x_23_ = lp_TensorLib_TensorLib_get_x21___redArg(v___x_21_, v___x_22_);
lean_dec_ref(v___x_22_);
return v___x_23_;
}
}
LEAN_EXPORT lean_object* l_taggedMatmul(lean_object* v_left_24_, lean_object* v_right_25_){
_start:
{
lean_object* v_a_26_; lean_object* v_b_27_; lean_object* v_product_28_; lean_object* v___x_29_; 
v_a_26_ = l_tensorTag___redArg(v_left_24_);
v_b_27_ = l_tensorTag___redArg(v_right_25_);
v_product_28_ = l_matmul2x2(v_a_26_, v_b_27_);
v___x_29_ = l_tensorTag___redArg(v_product_28_);
lean_dec_ref(v_product_28_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* l_taggedMatmul___boxed(lean_object* v_left_30_, lean_object* v_right_31_){
_start:
{
lean_object* v_res_32_; 
v_res_32_ = l_taggedMatmul(v_left_30_, v_right_31_);
lean_dec_ref(v_right_31_);
lean_dec_ref(v_left_30_);
return v_res_32_;
}
}
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(lean_object* v_x_33_, lean_object* v_x_34_){
_start:
{
if (lean_obj_tag(v_x_33_) == 0)
{
if (lean_obj_tag(v_x_34_) == 0)
{
uint8_t v___x_35_; 
v___x_35_ = 1;
return v___x_35_;
}
else
{
uint8_t v___x_36_; 
v___x_36_ = 0;
return v___x_36_;
}
}
else
{
if (lean_obj_tag(v_x_34_) == 0)
{
uint8_t v___x_37_; 
v___x_37_ = 0;
return v___x_37_;
}
else
{
lean_object* v_head_38_; lean_object* v_tail_39_; lean_object* v_head_40_; lean_object* v_tail_41_; float v___x_42_; float v___x_43_; uint8_t v___x_44_; 
v_head_38_ = lean_ctor_get(v_x_33_, 0);
v_tail_39_ = lean_ctor_get(v_x_33_, 1);
v_head_40_ = lean_ctor_get(v_x_34_, 0);
v_tail_41_ = lean_ctor_get(v_x_34_, 1);
v___x_42_ = lean_unbox_float32(v_head_38_);
v___x_43_ = lean_unbox_float32(v_head_40_);
v___x_44_ = lean_float32_beq(v___x_42_, v___x_43_);
if (v___x_44_ == 0)
{
return v___x_44_;
}
else
{
v_x_33_ = v_tail_39_;
v_x_34_ = v_tail_41_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0___boxed(lean_object* v_x_46_, lean_object* v_x_47_){
_start:
{
uint8_t v_res_48_; lean_object* v_r_49_; 
v_res_48_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(v_x_46_, v_x_47_);
lean_dec(v_x_47_);
lean_dec(v_x_46_);
v_r_49_ = lean_box(v_res_48_);
return v_r_49_;
}
}
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(lean_object* v_x_50_, lean_object* v_x_51_){
_start:
{
if (lean_obj_tag(v_x_50_) == 0)
{
if (lean_obj_tag(v_x_51_) == 0)
{
uint8_t v___x_52_; 
v___x_52_ = 1;
return v___x_52_;
}
else
{
uint8_t v___x_53_; 
v___x_53_ = 0;
return v___x_53_;
}
}
else
{
if (lean_obj_tag(v_x_51_) == 0)
{
uint8_t v___x_54_; 
v___x_54_ = 0;
return v___x_54_;
}
else
{
lean_object* v_head_55_; lean_object* v_tail_56_; lean_object* v_head_57_; lean_object* v_tail_58_; uint8_t v___x_59_; 
v_head_55_ = lean_ctor_get(v_x_50_, 0);
v_tail_56_ = lean_ctor_get(v_x_50_, 1);
v_head_57_ = lean_ctor_get(v_x_51_, 0);
v_tail_58_ = lean_ctor_get(v_x_51_, 1);
v___x_59_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_head_55_, v_head_57_);
if (v___x_59_ == 0)
{
return v___x_59_;
}
else
{
v_x_50_ = v_tail_56_;
v_x_51_ = v_tail_58_;
goto _start;
}
}
}
}
}
LEAN_EXPORT uint8_t l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(lean_object* v_x_61_, lean_object* v_x_62_){
_start:
{
if (lean_obj_tag(v_x_61_) == 0)
{
if (lean_obj_tag(v_x_62_) == 0)
{
lean_object* v_xs_63_; lean_object* v_xs_64_; uint8_t v___x_65_; 
v_xs_63_ = lean_ctor_get(v_x_61_, 0);
v_xs_64_ = lean_ctor_get(v_x_62_, 0);
v___x_65_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(v_xs_63_, v_xs_64_);
return v___x_65_;
}
else
{
uint8_t v___x_66_; 
v___x_66_ = 0;
return v___x_66_;
}
}
else
{
if (lean_obj_tag(v_x_62_) == 1)
{
lean_object* v_xs_67_; lean_object* v_xs_68_; uint8_t v___x_69_; 
v_xs_67_ = lean_ctor_get(v_x_61_, 0);
v_xs_68_ = lean_ctor_get(v_x_62_, 0);
v___x_69_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(v_xs_67_, v_xs_68_);
return v___x_69_;
}
else
{
uint8_t v___x_70_; 
v___x_70_ = 0;
return v___x_70_;
}
}
}
}
LEAN_EXPORT lean_object* l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0___boxed(lean_object* v_x_71_, lean_object* v_x_72_){
_start:
{
uint8_t v_res_73_; lean_object* v_r_74_; 
v_res_73_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_x_71_, v_x_72_);
lean_dec_ref(v_x_72_);
lean_dec_ref(v_x_71_);
v_r_74_ = lean_box(v_res_73_);
return v_r_74_;
}
}
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1___boxed(lean_object* v_x_75_, lean_object* v_x_76_){
_start:
{
uint8_t v_res_77_; lean_object* v_r_78_; 
v_res_77_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(v_x_75_, v_x_76_);
lean_dec(v_x_76_);
lean_dec(v_x_75_);
v_r_78_ = lean_box(v_res_77_);
return v_r_78_;
}
}
static float _init_l_main___closed__0(void){
_start:
{
lean_object* v___x_79_; float v___x_80_; 
v___x_79_ = lean_unsigned_to_nat(1u);
v___x_80_ = lean_float32_of_nat(v___x_79_);
return v___x_80_;
}
}
static float _init_l_main___closed__1(void){
_start:
{
lean_object* v___x_81_; float v___x_82_; 
v___x_81_ = lean_unsigned_to_nat(2u);
v___x_82_ = lean_float32_of_nat(v___x_81_);
return v___x_82_;
}
}
static float _init_l_main___closed__2(void){
_start:
{
lean_object* v___x_83_; float v___x_84_; 
v___x_83_ = lean_unsigned_to_nat(3u);
v___x_84_ = lean_float32_of_nat(v___x_83_);
return v___x_84_;
}
}
static float _init_l_main___closed__3(void){
_start:
{
lean_object* v___x_85_; float v___x_86_; 
v___x_85_ = lean_unsigned_to_nat(4u);
v___x_86_ = lean_float32_of_nat(v___x_85_);
return v___x_86_;
}
}
static lean_object* _init_l_main___closed__4___boxed__const__1(void){
_start:
{
float v___x_87_; lean_object* v___x_88_; 
v___x_87_ = lean_float32_once(&l_main___closed__3, &l_main___closed__3_once, _init_l_main___closed__3);
v___x_88_ = lean_box_float32(v___x_87_);
return v___x_88_;
}
}
static lean_object* _init_l_main___closed__4(void){
_start:
{
lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; 
v___x_89_ = lean_box(0);
v___x_90_ = l_main___closed__4___boxed__const__1;
v___x_91_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_91_, 0, v___x_90_);
lean_ctor_set(v___x_91_, 1, v___x_89_);
return v___x_91_;
}
}
static lean_object* _init_l_main___closed__5___boxed__const__1(void){
_start:
{
float v___x_92_; lean_object* v___x_93_; 
v___x_92_ = lean_float32_once(&l_main___closed__2, &l_main___closed__2_once, _init_l_main___closed__2);
v___x_93_ = lean_box_float32(v___x_92_);
return v___x_93_;
}
}
static lean_object* _init_l_main___closed__5(void){
_start:
{
lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; 
v___x_94_ = lean_obj_once(&l_main___closed__4, &l_main___closed__4_once, _init_l_main___closed__4);
v___x_95_ = l_main___closed__5___boxed__const__1;
v___x_96_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_96_, 0, v___x_95_);
lean_ctor_set(v___x_96_, 1, v___x_94_);
return v___x_96_;
}
}
static lean_object* _init_l_main___closed__6___boxed__const__1(void){
_start:
{
float v___x_97_; lean_object* v___x_98_; 
v___x_97_ = lean_float32_once(&l_main___closed__1, &l_main___closed__1_once, _init_l_main___closed__1);
v___x_98_ = lean_box_float32(v___x_97_);
return v___x_98_;
}
}
static lean_object* _init_l_main___closed__6(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; 
v___x_99_ = lean_obj_once(&l_main___closed__5, &l_main___closed__5_once, _init_l_main___closed__5);
v___x_100_ = l_main___closed__6___boxed__const__1;
v___x_101_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_101_, 0, v___x_100_);
lean_ctor_set(v___x_101_, 1, v___x_99_);
return v___x_101_;
}
}
static lean_object* _init_l_main___closed__7___boxed__const__1(void){
_start:
{
float v___x_102_; lean_object* v___x_103_; 
v___x_102_ = lean_float32_once(&l_main___closed__0, &l_main___closed__0_once, _init_l_main___closed__0);
v___x_103_ = lean_box_float32(v___x_102_);
return v___x_103_;
}
}
static lean_object* _init_l_main___closed__7(void){
_start:
{
lean_object* v___x_104_; lean_object* v___x_105_; lean_object* v___x_106_; 
v___x_104_ = lean_obj_once(&l_main___closed__6, &l_main___closed__6_once, _init_l_main___closed__6);
v___x_105_ = l_main___closed__7___boxed__const__1;
v___x_106_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_106_, 0, v___x_105_);
lean_ctor_set(v___x_106_, 1, v___x_104_);
return v___x_106_;
}
}
static lean_object* _init_l_main___closed__8(void){
_start:
{
lean_object* v___x_107_; lean_object* v_flatLeftTensor_108_; 
v___x_107_ = lean_obj_once(&l_main___closed__7, &l_main___closed__7_once, _init_l_main___closed__7);
v_flatLeftTensor_108_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_107_);
return v_flatLeftTensor_108_;
}
}
static lean_object* _init_l_main___closed__11(void){
_start:
{
lean_object* v___x_115_; lean_object* v_flatLeftTensor_116_; lean_object* v_left_117_; 
v___x_115_ = ((lean_object*)(l_main___closed__10));
v_flatLeftTensor_116_ = lean_obj_once(&l_main___closed__8, &l_main___closed__8_once, _init_l_main___closed__8);
v_left_117_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v_flatLeftTensor_116_, v___x_115_);
return v_left_117_;
}
}
static float _init_l_main___closed__12(void){
_start:
{
lean_object* v___x_118_; float v___x_119_; 
v___x_118_ = lean_unsigned_to_nat(5u);
v___x_119_ = lean_float32_of_nat(v___x_118_);
return v___x_119_;
}
}
static float _init_l_main___closed__13(void){
_start:
{
lean_object* v___x_120_; float v___x_121_; 
v___x_120_ = lean_unsigned_to_nat(6u);
v___x_121_ = lean_float32_of_nat(v___x_120_);
return v___x_121_;
}
}
static float _init_l_main___closed__14(void){
_start:
{
lean_object* v___x_122_; float v___x_123_; 
v___x_122_ = lean_unsigned_to_nat(7u);
v___x_123_ = lean_float32_of_nat(v___x_122_);
return v___x_123_;
}
}
static float _init_l_main___closed__15(void){
_start:
{
lean_object* v___x_124_; float v___x_125_; 
v___x_124_ = lean_unsigned_to_nat(8u);
v___x_125_ = lean_float32_of_nat(v___x_124_);
return v___x_125_;
}
}
static lean_object* _init_l_main___closed__16___boxed__const__1(void){
_start:
{
float v___x_126_; lean_object* v___x_127_; 
v___x_126_ = lean_float32_once(&l_main___closed__15, &l_main___closed__15_once, _init_l_main___closed__15);
v___x_127_ = lean_box_float32(v___x_126_);
return v___x_127_;
}
}
static lean_object* _init_l_main___closed__16(void){
_start:
{
lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; 
v___x_128_ = lean_box(0);
v___x_129_ = l_main___closed__16___boxed__const__1;
v___x_130_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_130_, 0, v___x_129_);
lean_ctor_set(v___x_130_, 1, v___x_128_);
return v___x_130_;
}
}
static lean_object* _init_l_main___closed__17___boxed__const__1(void){
_start:
{
float v___x_131_; lean_object* v___x_132_; 
v___x_131_ = lean_float32_once(&l_main___closed__14, &l_main___closed__14_once, _init_l_main___closed__14);
v___x_132_ = lean_box_float32(v___x_131_);
return v___x_132_;
}
}
static lean_object* _init_l_main___closed__17(void){
_start:
{
lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; 
v___x_133_ = lean_obj_once(&l_main___closed__16, &l_main___closed__16_once, _init_l_main___closed__16);
v___x_134_ = l_main___closed__17___boxed__const__1;
v___x_135_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_135_, 0, v___x_134_);
lean_ctor_set(v___x_135_, 1, v___x_133_);
return v___x_135_;
}
}
static lean_object* _init_l_main___closed__18___boxed__const__1(void){
_start:
{
float v___x_136_; lean_object* v___x_137_; 
v___x_136_ = lean_float32_once(&l_main___closed__13, &l_main___closed__13_once, _init_l_main___closed__13);
v___x_137_ = lean_box_float32(v___x_136_);
return v___x_137_;
}
}
static lean_object* _init_l_main___closed__18(void){
_start:
{
lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; 
v___x_138_ = lean_obj_once(&l_main___closed__17, &l_main___closed__17_once, _init_l_main___closed__17);
v___x_139_ = l_main___closed__18___boxed__const__1;
v___x_140_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_140_, 0, v___x_139_);
lean_ctor_set(v___x_140_, 1, v___x_138_);
return v___x_140_;
}
}
static lean_object* _init_l_main___closed__19___boxed__const__1(void){
_start:
{
float v___x_141_; lean_object* v___x_142_; 
v___x_141_ = lean_float32_once(&l_main___closed__12, &l_main___closed__12_once, _init_l_main___closed__12);
v___x_142_ = lean_box_float32(v___x_141_);
return v___x_142_;
}
}
static lean_object* _init_l_main___closed__19(void){
_start:
{
lean_object* v___x_143_; lean_object* v___x_144_; lean_object* v___x_145_; 
v___x_143_ = lean_obj_once(&l_main___closed__18, &l_main___closed__18_once, _init_l_main___closed__18);
v___x_144_ = l_main___closed__19___boxed__const__1;
v___x_145_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_145_, 0, v___x_144_);
lean_ctor_set(v___x_145_, 1, v___x_143_);
return v___x_145_;
}
}
static lean_object* _init_l_main___closed__20(void){
_start:
{
lean_object* v___x_146_; lean_object* v_flatRightTensor_147_; 
v___x_146_ = lean_obj_once(&l_main___closed__19, &l_main___closed__19_once, _init_l_main___closed__19);
v_flatRightTensor_147_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_146_);
return v_flatRightTensor_147_;
}
}
static lean_object* _init_l_main___closed__21(void){
_start:
{
lean_object* v___x_148_; lean_object* v_flatRightTensor_149_; lean_object* v_right_150_; 
v___x_148_ = ((lean_object*)(l_main___closed__10));
v_flatRightTensor_149_ = lean_obj_once(&l_main___closed__20, &l_main___closed__20_once, _init_l_main___closed__20);
v_right_150_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v_flatRightTensor_149_, v___x_148_);
return v_right_150_;
}
}
static lean_object* _init_l_main___closed__22(void){
_start:
{
lean_object* v_right_151_; lean_object* v_left_152_; lean_object* v_result_153_; 
v_right_151_ = lean_obj_once(&l_main___closed__21, &l_main___closed__21_once, _init_l_main___closed__21);
v_left_152_ = lean_obj_once(&l_main___closed__11, &l_main___closed__11_once, _init_l_main___closed__11);
v_result_153_ = l_taggedMatmul(v_left_152_, v_right_151_);
return v_result_153_;
}
}
static float _init_l_main___closed__23(void){
_start:
{
lean_object* v___x_154_; uint8_t v___x_155_; lean_object* v___x_156_; float v___x_157_; 
v___x_154_ = lean_unsigned_to_nat(1u);
v___x_155_ = 1;
v___x_156_ = lean_unsigned_to_nat(190u);
v___x_157_ = l_Float32_ofScientific(v___x_156_, v___x_155_, v___x_154_);
return v___x_157_;
}
}
static float _init_l_main___closed__24(void){
_start:
{
lean_object* v___x_158_; uint8_t v___x_159_; lean_object* v___x_160_; float v___x_161_; 
v___x_158_ = lean_unsigned_to_nat(1u);
v___x_159_ = 1;
v___x_160_ = lean_unsigned_to_nat(220u);
v___x_161_ = l_Float32_ofScientific(v___x_160_, v___x_159_, v___x_158_);
return v___x_161_;
}
}
static lean_object* _init_l_main___closed__25___boxed__const__1(void){
_start:
{
float v___x_162_; lean_object* v___x_163_; 
v___x_162_ = lean_float32_once(&l_main___closed__24, &l_main___closed__24_once, _init_l_main___closed__24);
v___x_163_ = lean_box_float32(v___x_162_);
return v___x_163_;
}
}
static lean_object* _init_l_main___closed__25(void){
_start:
{
lean_object* v___x_164_; lean_object* v___x_165_; lean_object* v___x_166_; 
v___x_164_ = lean_box(0);
v___x_165_ = l_main___closed__25___boxed__const__1;
v___x_166_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_166_, 0, v___x_165_);
lean_ctor_set(v___x_166_, 1, v___x_164_);
return v___x_166_;
}
}
static lean_object* _init_l_main___closed__26___boxed__const__1(void){
_start:
{
float v___x_167_; lean_object* v___x_168_; 
v___x_167_ = lean_float32_once(&l_main___closed__23, &l_main___closed__23_once, _init_l_main___closed__23);
v___x_168_ = lean_box_float32(v___x_167_);
return v___x_168_;
}
}
static lean_object* _init_l_main___closed__26(void){
_start:
{
lean_object* v___x_169_; lean_object* v___x_170_; lean_object* v___x_171_; 
v___x_169_ = lean_obj_once(&l_main___closed__25, &l_main___closed__25_once, _init_l_main___closed__25);
v___x_170_ = l_main___closed__26___boxed__const__1;
v___x_171_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_171_, 0, v___x_170_);
lean_ctor_set(v___x_171_, 1, v___x_169_);
return v___x_171_;
}
}
static lean_object* _init_l_main___closed__27(void){
_start:
{
lean_object* v___x_172_; lean_object* v___x_173_; 
v___x_172_ = lean_obj_once(&l_main___closed__26, &l_main___closed__26_once, _init_l_main___closed__26);
v___x_173_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_173_, 0, v___x_172_);
return v___x_173_;
}
}
static float _init_l_main___closed__28(void){
_start:
{
lean_object* v___x_174_; uint8_t v___x_175_; lean_object* v___x_176_; float v___x_177_; 
v___x_174_ = lean_unsigned_to_nat(1u);
v___x_175_ = 1;
v___x_176_ = lean_unsigned_to_nat(430u);
v___x_177_ = l_Float32_ofScientific(v___x_176_, v___x_175_, v___x_174_);
return v___x_177_;
}
}
static float _init_l_main___closed__29(void){
_start:
{
lean_object* v___x_178_; uint8_t v___x_179_; lean_object* v___x_180_; float v___x_181_; 
v___x_178_ = lean_unsigned_to_nat(1u);
v___x_179_ = 1;
v___x_180_ = lean_unsigned_to_nat(500u);
v___x_181_ = l_Float32_ofScientific(v___x_180_, v___x_179_, v___x_178_);
return v___x_181_;
}
}
static lean_object* _init_l_main___closed__30___boxed__const__1(void){
_start:
{
float v___x_182_; lean_object* v___x_183_; 
v___x_182_ = lean_float32_once(&l_main___closed__29, &l_main___closed__29_once, _init_l_main___closed__29);
v___x_183_ = lean_box_float32(v___x_182_);
return v___x_183_;
}
}
static lean_object* _init_l_main___closed__30(void){
_start:
{
lean_object* v___x_184_; lean_object* v___x_185_; lean_object* v___x_186_; 
v___x_184_ = lean_box(0);
v___x_185_ = l_main___closed__30___boxed__const__1;
v___x_186_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_186_, 0, v___x_185_);
lean_ctor_set(v___x_186_, 1, v___x_184_);
return v___x_186_;
}
}
static lean_object* _init_l_main___closed__31___boxed__const__1(void){
_start:
{
float v___x_187_; lean_object* v___x_188_; 
v___x_187_ = lean_float32_once(&l_main___closed__28, &l_main___closed__28_once, _init_l_main___closed__28);
v___x_188_ = lean_box_float32(v___x_187_);
return v___x_188_;
}
}
static lean_object* _init_l_main___closed__31(void){
_start:
{
lean_object* v___x_189_; lean_object* v___x_190_; lean_object* v___x_191_; 
v___x_189_ = lean_obj_once(&l_main___closed__30, &l_main___closed__30_once, _init_l_main___closed__30);
v___x_190_ = l_main___closed__31___boxed__const__1;
v___x_191_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_191_, 0, v___x_190_);
lean_ctor_set(v___x_191_, 1, v___x_189_);
return v___x_191_;
}
}
static lean_object* _init_l_main___closed__32(void){
_start:
{
lean_object* v___x_192_; lean_object* v___x_193_; 
v___x_192_ = lean_obj_once(&l_main___closed__31, &l_main___closed__31_once, _init_l_main___closed__31);
v___x_193_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_193_, 0, v___x_192_);
return v___x_193_;
}
}
static lean_object* _init_l_main___closed__33(void){
_start:
{
lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; 
v___x_194_ = lean_box(0);
v___x_195_ = lean_obj_once(&l_main___closed__32, &l_main___closed__32_once, _init_l_main___closed__32);
v___x_196_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_196_, 0, v___x_195_);
lean_ctor_set(v___x_196_, 1, v___x_194_);
return v___x_196_;
}
}
static lean_object* _init_l_main___closed__34(void){
_start:
{
lean_object* v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_197_ = lean_obj_once(&l_main___closed__33, &l_main___closed__33_once, _init_l_main___closed__33);
v___x_198_ = lean_obj_once(&l_main___closed__27, &l_main___closed__27_once, _init_l_main___closed__27);
v___x_199_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_199_, 0, v___x_198_);
lean_ctor_set(v___x_199_, 1, v___x_197_);
return v___x_199_;
}
}
static lean_object* _init_l_main___closed__35(void){
_start:
{
lean_object* v___x_200_; lean_object* v_expected_201_; 
v___x_200_ = lean_obj_once(&l_main___closed__34, &l_main___closed__34_once, _init_l_main___closed__34);
v_expected_201_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_expected_201_, 0, v___x_200_);
return v_expected_201_;
}
}
static lean_object* _init_l_main___closed__36(void){
_start:
{
lean_object* v_result_202_; lean_object* v_actual_203_; 
v_result_202_ = lean_obj_once(&l_main___closed__22, &l_main___closed__22_once, _init_l_main___closed__22);
v_actual_203_ = lp_TensorLib_TensorLib_Tensor_toFloat32Tree_x21(v_result_202_);
return v_actual_203_;
}
}
static uint8_t _init_l_main___closed__37(void){
_start:
{
lean_object* v_expected_204_; lean_object* v_actual_205_; uint8_t v___x_206_; 
v_expected_204_ = lean_obj_once(&l_main___closed__35, &l_main___closed__35_once, _init_l_main___closed__35);
v_actual_205_ = lean_obj_once(&l_main___closed__36, &l_main___closed__36_once, _init_l_main___closed__36);
v___x_206_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_actual_205_, v_expected_204_);
return v___x_206_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
uint8_t v___x_212_; 
v___x_212_ = lean_uint8_once(&l_main___closed__37, &l_main___closed__37_once, _init_l_main___closed__37);
if (v___x_212_ == 0)
{
lean_object* v___x_213_; lean_object* v___x_214_; 
v___x_213_ = ((lean_object*)(l_main___closed__39));
v___x_214_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_214_, 0, v___x_213_);
return v___x_214_;
}
else
{
lean_object* v___x_215_; lean_object* v___x_216_; 
v___x_215_ = ((lean_object*)(l_main___closed__40));
v___x_216_ = l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(v___x_215_);
return v___x_216_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_217_){
_start:
{
lean_object* v_res_218_; 
v_res_218_ = _lean_main();
return v_res_218_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Probe(uint8_t builtin);
lean_object* initialize_TensorLib_TensorLib_Ufunc(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_tensor__tag__tensorlib__lcnf__experiment_Main(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Probe(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_TensorLib_TensorLib_Ufunc(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_installTensorTagPass = _init_l_installTensorTagPass();
lean_mark_persistent(l_installTensorTagPass);
l_main___closed__4___boxed__const__1 = _init_l_main___closed__4___boxed__const__1();
lean_mark_persistent(l_main___closed__4___boxed__const__1);
l_main___closed__5___boxed__const__1 = _init_l_main___closed__5___boxed__const__1();
lean_mark_persistent(l_main___closed__5___boxed__const__1);
l_main___closed__6___boxed__const__1 = _init_l_main___closed__6___boxed__const__1();
lean_mark_persistent(l_main___closed__6___boxed__const__1);
l_main___closed__7___boxed__const__1 = _init_l_main___closed__7___boxed__const__1();
lean_mark_persistent(l_main___closed__7___boxed__const__1);
l_main___closed__16___boxed__const__1 = _init_l_main___closed__16___boxed__const__1();
lean_mark_persistent(l_main___closed__16___boxed__const__1);
l_main___closed__17___boxed__const__1 = _init_l_main___closed__17___boxed__const__1();
lean_mark_persistent(l_main___closed__17___boxed__const__1);
l_main___closed__18___boxed__const__1 = _init_l_main___closed__18___boxed__const__1();
lean_mark_persistent(l_main___closed__18___boxed__const__1);
l_main___closed__19___boxed__const__1 = _init_l_main___closed__19___boxed__const__1();
lean_mark_persistent(l_main___closed__19___boxed__const__1);
l_main___closed__25___boxed__const__1 = _init_l_main___closed__25___boxed__const__1();
lean_mark_persistent(l_main___closed__25___boxed__const__1);
l_main___closed__26___boxed__const__1 = _init_l_main___closed__26___boxed__const__1();
lean_mark_persistent(l_main___closed__26___boxed__const__1);
l_main___closed__30___boxed__const__1 = _init_l_main___closed__30___boxed__const__1();
lean_mark_persistent(l_main___closed__30___boxed__const__1);
l_main___closed__31___boxed__const__1 = _init_l_main___closed__31___boxed__const__1();
lean_mark_persistent(l_main___closed__31___boxed__const__1);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
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
  res = initialize_experiments_tensor__tag__tensorlib__lcnf__experiment_Main(1 /* builtin */);
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
