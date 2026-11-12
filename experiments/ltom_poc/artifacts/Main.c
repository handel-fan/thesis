// Lean compiler output
// Module: experiments.ltom_poc.Main
// Imports: public import Init public meta import Init public import LtomPocSupport
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
float lean_float32_of_nat(lean_object*);
float l_Float32_ofScientific(lean_object*, uint8_t, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_reshape_x21(lean_object*, lean_object*);
extern lean_object* lp_TensorLib_TensorLib_instInhabitedTensor_default;
lean_object* lp_TensorLib_TensorLib_Tensor_Ufunc_matmul(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_get_x21___redArg(lean_object*, lean_object*);
lean_object* lp_TensorLib_TensorLib_Tensor_toFloat32Tree_x21(lean_object*);
uint8_t lean_float32_beq(float, float);
lean_object* l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_matmul2x2(lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* l_matmul2x2(lean_object* v_left_1_, lean_object* v_right_2_){
_start:
{
lean_object* v___x_3_; lean_object* v_tensorResult_4_; lean_object* v_resultTensor_5_; 
v___x_3_ = lp_TensorLib_TensorLib_instInhabitedTensor_default;
v_tensorResult_4_ = lp_TensorLib_TensorLib_Tensor_Ufunc_matmul(v_left_1_, v_right_2_);
v_resultTensor_5_ = lp_TensorLib_TensorLib_get_x21___redArg(v___x_3_, v_tensorResult_4_);
lean_dec_ref(v_tensorResult_4_);
return v_resultTensor_5_;
}
}
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(lean_object* v_x_6_, lean_object* v_x_7_){
_start:
{
if (lean_obj_tag(v_x_6_) == 0)
{
if (lean_obj_tag(v_x_7_) == 0)
{
uint8_t v___x_8_; 
v___x_8_ = 1;
return v___x_8_;
}
else
{
uint8_t v___x_9_; 
v___x_9_ = 0;
return v___x_9_;
}
}
else
{
if (lean_obj_tag(v_x_7_) == 0)
{
uint8_t v___x_10_; 
v___x_10_ = 0;
return v___x_10_;
}
else
{
lean_object* v_head_11_; lean_object* v_tail_12_; lean_object* v_head_13_; lean_object* v_tail_14_; float v___x_15_; float v___x_16_; uint8_t v___x_17_; 
v_head_11_ = lean_ctor_get(v_x_6_, 0);
v_tail_12_ = lean_ctor_get(v_x_6_, 1);
v_head_13_ = lean_ctor_get(v_x_7_, 0);
v_tail_14_ = lean_ctor_get(v_x_7_, 1);
v___x_15_ = lean_unbox_float32(v_head_11_);
v___x_16_ = lean_unbox_float32(v_head_13_);
v___x_17_ = lean_float32_beq(v___x_15_, v___x_16_);
if (v___x_17_ == 0)
{
return v___x_17_;
}
else
{
v_x_6_ = v_tail_12_;
v_x_7_ = v_tail_14_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0___boxed(lean_object* v_x_19_, lean_object* v_x_20_){
_start:
{
uint8_t v_res_21_; lean_object* v_r_22_; 
v_res_21_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(v_x_19_, v_x_20_);
lean_dec(v_x_20_);
lean_dec(v_x_19_);
v_r_22_ = lean_box(v_res_21_);
return v_r_22_;
}
}
LEAN_EXPORT uint8_t l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(lean_object* v_x_23_, lean_object* v_x_24_){
_start:
{
if (lean_obj_tag(v_x_23_) == 0)
{
if (lean_obj_tag(v_x_24_) == 0)
{
uint8_t v___x_25_; 
v___x_25_ = 1;
return v___x_25_;
}
else
{
uint8_t v___x_26_; 
v___x_26_ = 0;
return v___x_26_;
}
}
else
{
if (lean_obj_tag(v_x_24_) == 0)
{
uint8_t v___x_27_; 
v___x_27_ = 0;
return v___x_27_;
}
else
{
lean_object* v_head_28_; lean_object* v_tail_29_; lean_object* v_head_30_; lean_object* v_tail_31_; uint8_t v___x_32_; 
v_head_28_ = lean_ctor_get(v_x_23_, 0);
v_tail_29_ = lean_ctor_get(v_x_23_, 1);
v_head_30_ = lean_ctor_get(v_x_24_, 0);
v_tail_31_ = lean_ctor_get(v_x_24_, 1);
v___x_32_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_head_28_, v_head_30_);
if (v___x_32_ == 0)
{
return v___x_32_;
}
else
{
v_x_23_ = v_tail_29_;
v_x_24_ = v_tail_31_;
goto _start;
}
}
}
}
}
LEAN_EXPORT uint8_t l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(lean_object* v_x_34_, lean_object* v_x_35_){
_start:
{
if (lean_obj_tag(v_x_34_) == 0)
{
if (lean_obj_tag(v_x_35_) == 0)
{
lean_object* v_xs_36_; lean_object* v_xs_37_; uint8_t v___x_38_; 
v_xs_36_ = lean_ctor_get(v_x_34_, 0);
v_xs_37_ = lean_ctor_get(v_x_35_, 0);
v___x_38_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__0(v_xs_36_, v_xs_37_);
return v___x_38_;
}
else
{
uint8_t v___x_39_; 
v___x_39_ = 0;
return v___x_39_;
}
}
else
{
if (lean_obj_tag(v_x_35_) == 1)
{
lean_object* v_xs_40_; lean_object* v_xs_41_; uint8_t v___x_42_; 
v_xs_40_ = lean_ctor_get(v_x_34_, 0);
v_xs_41_ = lean_ctor_get(v_x_35_, 0);
v___x_42_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(v_xs_40_, v_xs_41_);
return v___x_42_;
}
else
{
uint8_t v___x_43_; 
v___x_43_ = 0;
return v___x_43_;
}
}
}
}
LEAN_EXPORT lean_object* l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0___boxed(lean_object* v_x_44_, lean_object* v_x_45_){
_start:
{
uint8_t v_res_46_; lean_object* v_r_47_; 
v_res_46_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_x_44_, v_x_45_);
lean_dec_ref(v_x_45_);
lean_dec_ref(v_x_44_);
v_r_47_ = lean_box(v_res_46_);
return v_r_47_;
}
}
LEAN_EXPORT lean_object* l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1___boxed(lean_object* v_x_48_, lean_object* v_x_49_){
_start:
{
uint8_t v_res_50_; lean_object* v_r_51_; 
v_res_50_ = l_List_beq___at___00TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0_spec__1(v_x_48_, v_x_49_);
lean_dec(v_x_49_);
lean_dec(v_x_48_);
v_r_51_ = lean_box(v_res_50_);
return v_r_51_;
}
}
static float _init_l_main___closed__0(void){
_start:
{
lean_object* v___x_52_; float v___x_53_; 
v___x_52_ = lean_unsigned_to_nat(1u);
v___x_53_ = lean_float32_of_nat(v___x_52_);
return v___x_53_;
}
}
static float _init_l_main___closed__1(void){
_start:
{
lean_object* v___x_54_; float v___x_55_; 
v___x_54_ = lean_unsigned_to_nat(2u);
v___x_55_ = lean_float32_of_nat(v___x_54_);
return v___x_55_;
}
}
static float _init_l_main___closed__2(void){
_start:
{
lean_object* v___x_56_; float v___x_57_; 
v___x_56_ = lean_unsigned_to_nat(3u);
v___x_57_ = lean_float32_of_nat(v___x_56_);
return v___x_57_;
}
}
static float _init_l_main___closed__3(void){
_start:
{
lean_object* v___x_58_; float v___x_59_; 
v___x_58_ = lean_unsigned_to_nat(4u);
v___x_59_ = lean_float32_of_nat(v___x_58_);
return v___x_59_;
}
}
static lean_object* _init_l_main___closed__4___boxed__const__1(void){
_start:
{
float v___x_60_; lean_object* v___x_61_; 
v___x_60_ = lean_float32_once(&l_main___closed__3, &l_main___closed__3_once, _init_l_main___closed__3);
v___x_61_ = lean_box_float32(v___x_60_);
return v___x_61_;
}
}
static lean_object* _init_l_main___closed__4(void){
_start:
{
lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v___x_64_; 
v___x_62_ = lean_box(0);
v___x_63_ = l_main___closed__4___boxed__const__1;
v___x_64_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_64_, 0, v___x_63_);
lean_ctor_set(v___x_64_, 1, v___x_62_);
return v___x_64_;
}
}
static lean_object* _init_l_main___closed__5___boxed__const__1(void){
_start:
{
float v___x_65_; lean_object* v___x_66_; 
v___x_65_ = lean_float32_once(&l_main___closed__2, &l_main___closed__2_once, _init_l_main___closed__2);
v___x_66_ = lean_box_float32(v___x_65_);
return v___x_66_;
}
}
static lean_object* _init_l_main___closed__5(void){
_start:
{
lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; 
v___x_67_ = lean_obj_once(&l_main___closed__4, &l_main___closed__4_once, _init_l_main___closed__4);
v___x_68_ = l_main___closed__5___boxed__const__1;
v___x_69_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_69_, 0, v___x_68_);
lean_ctor_set(v___x_69_, 1, v___x_67_);
return v___x_69_;
}
}
static lean_object* _init_l_main___closed__6___boxed__const__1(void){
_start:
{
float v___x_70_; lean_object* v___x_71_; 
v___x_70_ = lean_float32_once(&l_main___closed__1, &l_main___closed__1_once, _init_l_main___closed__1);
v___x_71_ = lean_box_float32(v___x_70_);
return v___x_71_;
}
}
static lean_object* _init_l_main___closed__6(void){
_start:
{
lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_72_ = lean_obj_once(&l_main___closed__5, &l_main___closed__5_once, _init_l_main___closed__5);
v___x_73_ = l_main___closed__6___boxed__const__1;
v___x_74_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_74_, 0, v___x_73_);
lean_ctor_set(v___x_74_, 1, v___x_72_);
return v___x_74_;
}
}
static lean_object* _init_l_main___closed__7___boxed__const__1(void){
_start:
{
float v___x_75_; lean_object* v___x_76_; 
v___x_75_ = lean_float32_once(&l_main___closed__0, &l_main___closed__0_once, _init_l_main___closed__0);
v___x_76_ = lean_box_float32(v___x_75_);
return v___x_76_;
}
}
static lean_object* _init_l_main___closed__7(void){
_start:
{
lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; 
v___x_77_ = lean_obj_once(&l_main___closed__6, &l_main___closed__6_once, _init_l_main___closed__6);
v___x_78_ = l_main___closed__7___boxed__const__1;
v___x_79_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_79_, 0, v___x_78_);
lean_ctor_set(v___x_79_, 1, v___x_77_);
return v___x_79_;
}
}
static lean_object* _init_l_main___closed__8(void){
_start:
{
lean_object* v___x_80_; lean_object* v_flatLeftTensor_81_; 
v___x_80_ = lean_obj_once(&l_main___closed__7, &l_main___closed__7_once, _init_l_main___closed__7);
v_flatLeftTensor_81_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_80_);
return v_flatLeftTensor_81_;
}
}
static lean_object* _init_l_main___closed__11(void){
_start:
{
lean_object* v___x_88_; lean_object* v_flatLeftTensor_89_; lean_object* v_leftTensor_90_; 
v___x_88_ = ((lean_object*)(l_main___closed__10));
v_flatLeftTensor_89_ = lean_obj_once(&l_main___closed__8, &l_main___closed__8_once, _init_l_main___closed__8);
v_leftTensor_90_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v_flatLeftTensor_89_, v___x_88_);
return v_leftTensor_90_;
}
}
static float _init_l_main___closed__12(void){
_start:
{
lean_object* v___x_91_; float v___x_92_; 
v___x_91_ = lean_unsigned_to_nat(5u);
v___x_92_ = lean_float32_of_nat(v___x_91_);
return v___x_92_;
}
}
static float _init_l_main___closed__13(void){
_start:
{
lean_object* v___x_93_; float v___x_94_; 
v___x_93_ = lean_unsigned_to_nat(6u);
v___x_94_ = lean_float32_of_nat(v___x_93_);
return v___x_94_;
}
}
static float _init_l_main___closed__14(void){
_start:
{
lean_object* v___x_95_; float v___x_96_; 
v___x_95_ = lean_unsigned_to_nat(7u);
v___x_96_ = lean_float32_of_nat(v___x_95_);
return v___x_96_;
}
}
static float _init_l_main___closed__15(void){
_start:
{
lean_object* v___x_97_; float v___x_98_; 
v___x_97_ = lean_unsigned_to_nat(8u);
v___x_98_ = lean_float32_of_nat(v___x_97_);
return v___x_98_;
}
}
static lean_object* _init_l_main___closed__16___boxed__const__1(void){
_start:
{
float v___x_99_; lean_object* v___x_100_; 
v___x_99_ = lean_float32_once(&l_main___closed__15, &l_main___closed__15_once, _init_l_main___closed__15);
v___x_100_ = lean_box_float32(v___x_99_);
return v___x_100_;
}
}
static lean_object* _init_l_main___closed__16(void){
_start:
{
lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v___x_103_; 
v___x_101_ = lean_box(0);
v___x_102_ = l_main___closed__16___boxed__const__1;
v___x_103_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_103_, 0, v___x_102_);
lean_ctor_set(v___x_103_, 1, v___x_101_);
return v___x_103_;
}
}
static lean_object* _init_l_main___closed__17___boxed__const__1(void){
_start:
{
float v___x_104_; lean_object* v___x_105_; 
v___x_104_ = lean_float32_once(&l_main___closed__14, &l_main___closed__14_once, _init_l_main___closed__14);
v___x_105_ = lean_box_float32(v___x_104_);
return v___x_105_;
}
}
static lean_object* _init_l_main___closed__17(void){
_start:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; 
v___x_106_ = lean_obj_once(&l_main___closed__16, &l_main___closed__16_once, _init_l_main___closed__16);
v___x_107_ = l_main___closed__17___boxed__const__1;
v___x_108_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_108_, 0, v___x_107_);
lean_ctor_set(v___x_108_, 1, v___x_106_);
return v___x_108_;
}
}
static lean_object* _init_l_main___closed__18___boxed__const__1(void){
_start:
{
float v___x_109_; lean_object* v___x_110_; 
v___x_109_ = lean_float32_once(&l_main___closed__13, &l_main___closed__13_once, _init_l_main___closed__13);
v___x_110_ = lean_box_float32(v___x_109_);
return v___x_110_;
}
}
static lean_object* _init_l_main___closed__18(void){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_111_ = lean_obj_once(&l_main___closed__17, &l_main___closed__17_once, _init_l_main___closed__17);
v___x_112_ = l_main___closed__18___boxed__const__1;
v___x_113_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_113_, 0, v___x_112_);
lean_ctor_set(v___x_113_, 1, v___x_111_);
return v___x_113_;
}
}
static lean_object* _init_l_main___closed__19___boxed__const__1(void){
_start:
{
float v___x_114_; lean_object* v___x_115_; 
v___x_114_ = lean_float32_once(&l_main___closed__12, &l_main___closed__12_once, _init_l_main___closed__12);
v___x_115_ = lean_box_float32(v___x_114_);
return v___x_115_;
}
}
static lean_object* _init_l_main___closed__19(void){
_start:
{
lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; 
v___x_116_ = lean_obj_once(&l_main___closed__18, &l_main___closed__18_once, _init_l_main___closed__18);
v___x_117_ = l_main___closed__19___boxed__const__1;
v___x_118_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_118_, 0, v___x_117_);
lean_ctor_set(v___x_118_, 1, v___x_116_);
return v___x_118_;
}
}
static lean_object* _init_l_main___closed__20(void){
_start:
{
lean_object* v___x_119_; lean_object* v_flatRightTensor_120_; 
v___x_119_ = lean_obj_once(&l_main___closed__19, &l_main___closed__19_once, _init_l_main___closed__19);
v_flatRightTensor_120_ = lp_TensorLib_TensorLib_Tensor_ofFloat32List_x21(v___x_119_);
return v_flatRightTensor_120_;
}
}
static lean_object* _init_l_main___closed__21(void){
_start:
{
lean_object* v___x_121_; lean_object* v_flatRightTensor_122_; lean_object* v_rightTensor_123_; 
v___x_121_ = ((lean_object*)(l_main___closed__10));
v_flatRightTensor_122_ = lean_obj_once(&l_main___closed__20, &l_main___closed__20_once, _init_l_main___closed__20);
v_rightTensor_123_ = lp_TensorLib_TensorLib_Tensor_reshape_x21(v_flatRightTensor_122_, v___x_121_);
return v_rightTensor_123_;
}
}
static lean_object* _init_l_main___closed__22(void){
_start:
{
lean_object* v_rightTensor_124_; lean_object* v_leftTensor_125_; lean_object* v_result_126_; 
v_rightTensor_124_ = lean_obj_once(&l_main___closed__21, &l_main___closed__21_once, _init_l_main___closed__21);
v_leftTensor_125_ = lean_obj_once(&l_main___closed__11, &l_main___closed__11_once, _init_l_main___closed__11);
v_result_126_ = l_matmul2x2(v_leftTensor_125_, v_rightTensor_124_);
return v_result_126_;
}
}
static float _init_l_main___closed__23(void){
_start:
{
lean_object* v___x_127_; uint8_t v___x_128_; lean_object* v___x_129_; float v___x_130_; 
v___x_127_ = lean_unsigned_to_nat(1u);
v___x_128_ = 1;
v___x_129_ = lean_unsigned_to_nat(190u);
v___x_130_ = l_Float32_ofScientific(v___x_129_, v___x_128_, v___x_127_);
return v___x_130_;
}
}
static float _init_l_main___closed__24(void){
_start:
{
lean_object* v___x_131_; uint8_t v___x_132_; lean_object* v___x_133_; float v___x_134_; 
v___x_131_ = lean_unsigned_to_nat(1u);
v___x_132_ = 1;
v___x_133_ = lean_unsigned_to_nat(220u);
v___x_134_ = l_Float32_ofScientific(v___x_133_, v___x_132_, v___x_131_);
return v___x_134_;
}
}
static lean_object* _init_l_main___closed__25___boxed__const__1(void){
_start:
{
float v___x_135_; lean_object* v___x_136_; 
v___x_135_ = lean_float32_once(&l_main___closed__24, &l_main___closed__24_once, _init_l_main___closed__24);
v___x_136_ = lean_box_float32(v___x_135_);
return v___x_136_;
}
}
static lean_object* _init_l_main___closed__25(void){
_start:
{
lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; 
v___x_137_ = lean_box(0);
v___x_138_ = l_main___closed__25___boxed__const__1;
v___x_139_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_139_, 0, v___x_138_);
lean_ctor_set(v___x_139_, 1, v___x_137_);
return v___x_139_;
}
}
static lean_object* _init_l_main___closed__26___boxed__const__1(void){
_start:
{
float v___x_140_; lean_object* v___x_141_; 
v___x_140_ = lean_float32_once(&l_main___closed__23, &l_main___closed__23_once, _init_l_main___closed__23);
v___x_141_ = lean_box_float32(v___x_140_);
return v___x_141_;
}
}
static lean_object* _init_l_main___closed__26(void){
_start:
{
lean_object* v___x_142_; lean_object* v___x_143_; lean_object* v___x_144_; 
v___x_142_ = lean_obj_once(&l_main___closed__25, &l_main___closed__25_once, _init_l_main___closed__25);
v___x_143_ = l_main___closed__26___boxed__const__1;
v___x_144_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_144_, 0, v___x_143_);
lean_ctor_set(v___x_144_, 1, v___x_142_);
return v___x_144_;
}
}
static lean_object* _init_l_main___closed__27(void){
_start:
{
lean_object* v___x_145_; lean_object* v___x_146_; 
v___x_145_ = lean_obj_once(&l_main___closed__26, &l_main___closed__26_once, _init_l_main___closed__26);
v___x_146_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_146_, 0, v___x_145_);
return v___x_146_;
}
}
static float _init_l_main___closed__28(void){
_start:
{
lean_object* v___x_147_; uint8_t v___x_148_; lean_object* v___x_149_; float v___x_150_; 
v___x_147_ = lean_unsigned_to_nat(1u);
v___x_148_ = 1;
v___x_149_ = lean_unsigned_to_nat(430u);
v___x_150_ = l_Float32_ofScientific(v___x_149_, v___x_148_, v___x_147_);
return v___x_150_;
}
}
static float _init_l_main___closed__29(void){
_start:
{
lean_object* v___x_151_; uint8_t v___x_152_; lean_object* v___x_153_; float v___x_154_; 
v___x_151_ = lean_unsigned_to_nat(1u);
v___x_152_ = 1;
v___x_153_ = lean_unsigned_to_nat(500u);
v___x_154_ = l_Float32_ofScientific(v___x_153_, v___x_152_, v___x_151_);
return v___x_154_;
}
}
static lean_object* _init_l_main___closed__30___boxed__const__1(void){
_start:
{
float v___x_155_; lean_object* v___x_156_; 
v___x_155_ = lean_float32_once(&l_main___closed__29, &l_main___closed__29_once, _init_l_main___closed__29);
v___x_156_ = lean_box_float32(v___x_155_);
return v___x_156_;
}
}
static lean_object* _init_l_main___closed__30(void){
_start:
{
lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; 
v___x_157_ = lean_box(0);
v___x_158_ = l_main___closed__30___boxed__const__1;
v___x_159_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_159_, 0, v___x_158_);
lean_ctor_set(v___x_159_, 1, v___x_157_);
return v___x_159_;
}
}
static lean_object* _init_l_main___closed__31___boxed__const__1(void){
_start:
{
float v___x_160_; lean_object* v___x_161_; 
v___x_160_ = lean_float32_once(&l_main___closed__28, &l_main___closed__28_once, _init_l_main___closed__28);
v___x_161_ = lean_box_float32(v___x_160_);
return v___x_161_;
}
}
static lean_object* _init_l_main___closed__31(void){
_start:
{
lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; 
v___x_162_ = lean_obj_once(&l_main___closed__30, &l_main___closed__30_once, _init_l_main___closed__30);
v___x_163_ = l_main___closed__31___boxed__const__1;
v___x_164_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_164_, 0, v___x_163_);
lean_ctor_set(v___x_164_, 1, v___x_162_);
return v___x_164_;
}
}
static lean_object* _init_l_main___closed__32(void){
_start:
{
lean_object* v___x_165_; lean_object* v___x_166_; 
v___x_165_ = lean_obj_once(&l_main___closed__31, &l_main___closed__31_once, _init_l_main___closed__31);
v___x_166_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_166_, 0, v___x_165_);
return v___x_166_;
}
}
static lean_object* _init_l_main___closed__33(void){
_start:
{
lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; 
v___x_167_ = lean_box(0);
v___x_168_ = lean_obj_once(&l_main___closed__32, &l_main___closed__32_once, _init_l_main___closed__32);
v___x_169_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_169_, 0, v___x_168_);
lean_ctor_set(v___x_169_, 1, v___x_167_);
return v___x_169_;
}
}
static lean_object* _init_l_main___closed__34(void){
_start:
{
lean_object* v___x_170_; lean_object* v___x_171_; lean_object* v___x_172_; 
v___x_170_ = lean_obj_once(&l_main___closed__33, &l_main___closed__33_once, _init_l_main___closed__33);
v___x_171_ = lean_obj_once(&l_main___closed__27, &l_main___closed__27_once, _init_l_main___closed__27);
v___x_172_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_172_, 0, v___x_171_);
lean_ctor_set(v___x_172_, 1, v___x_170_);
return v___x_172_;
}
}
static lean_object* _init_l_main___closed__35(void){
_start:
{
lean_object* v___x_173_; lean_object* v_expected_174_; 
v___x_173_ = lean_obj_once(&l_main___closed__34, &l_main___closed__34_once, _init_l_main___closed__34);
v_expected_174_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_expected_174_, 0, v___x_173_);
return v_expected_174_;
}
}
static lean_object* _init_l_main___closed__36(void){
_start:
{
lean_object* v_result_175_; lean_object* v_actual_176_; 
v_result_175_ = lean_obj_once(&l_main___closed__22, &l_main___closed__22_once, _init_l_main___closed__22);
v_actual_176_ = lp_TensorLib_TensorLib_Tensor_toFloat32Tree_x21(v_result_175_);
return v_actual_176_;
}
}
static uint8_t _init_l_main___closed__37(void){
_start:
{
lean_object* v_expected_177_; lean_object* v_actual_178_; uint8_t v___x_179_; 
v_expected_177_ = lean_obj_once(&l_main___closed__35, &l_main___closed__35_once, _init_l_main___closed__35);
v_actual_178_ = lean_obj_once(&l_main___closed__36, &l_main___closed__36_once, _init_l_main___closed__36);
v___x_179_ = l_TensorLib_Tensor_Format_instBEqTree_beq___at___00main_spec__0(v_actual_178_, v_expected_177_);
return v___x_179_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
uint8_t v___x_185_; 
v___x_185_ = lean_uint8_once(&l_main___closed__37, &l_main___closed__37_once, _init_l_main___closed__37);
if (v___x_185_ == 0)
{
lean_object* v___x_186_; lean_object* v___x_187_; 
v___x_186_ = ((lean_object*)(l_main___closed__39));
v___x_187_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_187_, 0, v___x_186_);
return v___x_187_;
}
else
{
lean_object* v___x_188_; lean_object* v___x_189_; 
v___x_188_ = ((lean_object*)(l_main___closed__40));
v___x_189_ = l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(v___x_188_);
return v___x_189_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_190_){
_start:
{
lean_object* v_res_191_; 
v_res_191_ = _lean_main();
return v_res_191_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LtomPocSupport(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_ltom__poc_Main(uint8_t builtin) {
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
res = initialize_LtomPocSupport(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
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
  res = initialize_experiments_ltom__poc_Main(1 /* builtin */);
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
