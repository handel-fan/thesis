// Lean compiler output
// Module: Main
// Imports: public import Init public meta import Init public import Probe
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
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___redArg(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_matmul(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_matmul___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_work(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_work___boxed(lean_object*, lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "RESULT="};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
static lean_once_cell_t l_main___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__1;
static lean_once_cell_t l_main___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__2;
static lean_once_cell_t l_main___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__3;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_tensorTag___redArg(lean_object* v_x_1_){
_start:
{
lean_inc(v_x_1_);
return v_x_1_;
}
}
LEAN_EXPORT lean_object* l_tensorTag___redArg___boxed(lean_object* v_x_2_){
_start:
{
lean_object* v_res_3_; 
v_res_3_ = l_tensorTag___redArg(v_x_2_);
lean_dec(v_x_2_);
return v_res_3_;
}
}
LEAN_EXPORT lean_object* l_tensorTag(lean_object* v_rows_4_, lean_object* v_cols_5_, lean_object* v_00_u03b1_6_, lean_object* v_x_7_){
_start:
{
lean_object* v___x_8_; 
v___x_8_ = l_tensorTag___redArg(v_x_7_);
return v___x_8_;
}
}
LEAN_EXPORT lean_object* l_tensorTag___boxed(lean_object* v_rows_9_, lean_object* v_cols_10_, lean_object* v_00_u03b1_11_, lean_object* v_x_12_){
_start:
{
lean_object* v_res_13_; 
v_res_13_ = l_tensorTag(v_rows_9_, v_cols_10_, v_00_u03b1_11_, v_x_12_);
lean_dec(v_x_12_);
lean_dec(v_cols_10_);
lean_dec(v_rows_9_);
return v_res_13_;
}
}
LEAN_EXPORT lean_object* l_matmul(lean_object* v_a_14_, lean_object* v_b_15_){
_start:
{
lean_object* v___x_16_; 
v___x_16_ = lean_nat_mul(v_a_14_, v_b_15_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* l_matmul___boxed(lean_object* v_a_17_, lean_object* v_b_18_){
_start:
{
lean_object* v_res_19_; 
v_res_19_ = l_matmul(v_a_17_, v_b_18_);
lean_dec(v_b_18_);
lean_dec(v_a_17_);
return v_res_19_;
}
}
LEAN_EXPORT lean_object* l_work(lean_object* v_x_20_, lean_object* v_y_21_){
_start:
{
lean_object* v_a_22_; lean_object* v_b_23_; lean_object* v_product_24_; lean_object* v___x_25_; 
v_a_22_ = l_tensorTag___redArg(v_x_20_);
v_b_23_ = l_tensorTag___redArg(v_y_21_);
v_product_24_ = l_matmul(v_a_22_, v_b_23_);
lean_dec(v_b_23_);
lean_dec(v_a_22_);
v___x_25_ = l_tensorTag___redArg(v_product_24_);
lean_dec(v_product_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* l_work___boxed(lean_object* v_x_26_, lean_object* v_y_27_){
_start:
{
lean_object* v_res_28_; 
v_res_28_ = l_work(v_x_26_, v_y_27_);
lean_dec(v_y_27_);
lean_dec(v_x_26_);
return v_res_28_;
}
}
static lean_object* _init_l_main___closed__1(void){
_start:
{
lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_30_ = lean_unsigned_to_nat(7u);
v___x_31_ = lean_unsigned_to_nat(3u);
v___x_32_ = l_work(v___x_31_, v___x_30_);
return v___x_32_;
}
}
static lean_object* _init_l_main___closed__2(void){
_start:
{
lean_object* v___x_33_; lean_object* v___x_34_; 
v___x_33_ = lean_obj_once(&l_main___closed__1, &l_main___closed__1_once, _init_l_main___closed__1);
v___x_34_ = l_Nat_reprFast(v___x_33_);
return v___x_34_;
}
}
static lean_object* _init_l_main___closed__3(void){
_start:
{
lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; 
v___x_35_ = lean_obj_once(&l_main___closed__2, &l_main___closed__2_once, _init_l_main___closed__2);
v___x_36_ = ((lean_object*)(l_main___closed__0));
v___x_37_ = lean_string_append(v___x_36_, v___x_35_);
return v___x_37_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; 
v___x_39_ = lean_obj_once(&l_main___closed__3, &l_main___closed__3_once, _init_l_main___closed__3);
v___x_40_ = l_IO_println___at___00__private_Lean_Shell_0__Lean_ShellOptions_process_spec__3(v___x_39_);
return v___x_40_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_41_){
_start:
{
lean_object* v_res_42_; 
v_res_42_ = _lean_main();
return v_res_42_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Probe(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_Main(uint8_t builtin) {
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
  res = initialize_Main(1 /* builtin */);
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
