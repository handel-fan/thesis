// Lean compiler output
// Module: run_square
// Imports: public import Init public meta import Init
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
lean_object* lean_string_push(lean_object*, uint32_t);
lean_object* lean_get_stdout();
LEAN_EXPORT lean_object* l_square(lean_object*);
LEAN_EXPORT lean_object* l_square___boxed(lean_object*);
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00main_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00main_spec__0_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_IO_println___at___00main_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_IO_println___at___00main_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_square(lean_object* v_x_1_){
_start:
{
lean_object* v___x_2_; 
v___x_2_ = lean_nat_mul(v_x_1_, v_x_1_);
return v___x_2_;
}
}
LEAN_EXPORT lean_object* l_square___boxed(lean_object* v_x_3_){
_start:
{
lean_object* v_res_4_; 
v_res_4_ = l_square(v_x_3_);
lean_dec(v_x_3_);
return v_res_4_;
}
}
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00main_spec__0_spec__0(lean_object* v_s_5_){
_start:
{
lean_object* v___x_7_; lean_object* v_putStr_8_; lean_object* v___x_9_; 
v___x_7_ = lean_get_stdout();
v_putStr_8_ = lean_ctor_get(v___x_7_, 4);
lean_inc_ref(v_putStr_8_);
lean_dec_ref(v___x_7_);
v___x_9_ = lean_apply_2(v_putStr_8_, v_s_5_, lean_box(0));
return v___x_9_;
}
}
LEAN_EXPORT lean_object* l_IO_print___at___00IO_println___at___00main_spec__0_spec__0___boxed(lean_object* v_s_10_, lean_object* v_a_11_){
_start:
{
lean_object* v_res_12_; 
v_res_12_ = l_IO_print___at___00IO_println___at___00main_spec__0_spec__0(v_s_10_);
return v_res_12_;
}
}
LEAN_EXPORT lean_object* l_IO_println___at___00main_spec__0(lean_object* v_s_13_){
_start:
{
lean_object* v___x_15_; uint32_t v___x_16_; lean_object* v___x_17_; lean_object* v___x_18_; 
v___x_15_ = l_Nat_reprFast(v_s_13_);
v___x_16_ = 10;
v___x_17_ = lean_string_push(v___x_15_, v___x_16_);
v___x_18_ = l_IO_print___at___00IO_println___at___00main_spec__0_spec__0(v___x_17_);
return v___x_18_;
}
}
LEAN_EXPORT lean_object* l_IO_println___at___00main_spec__0___boxed(lean_object* v_s_19_, lean_object* v_a_20_){
_start:
{
lean_object* v_res_21_; 
v_res_21_ = l_IO_println___at___00main_spec__0(v_s_19_);
return v_res_21_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_23_; lean_object* v___x_24_; 
v___x_23_ = lean_unsigned_to_nat(25u);
v___x_24_ = l_IO_println___at___00main_spec__0(v___x_23_);
return v___x_24_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_25_){
_start:
{
lean_object* v_res_26_; 
v_res_26_ = _lean_main();
return v_res_26_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_run__square(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
void lean_initialize_runtime_module();
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
  lean_initialize_runtime_module();
  res = initialize_run__square(1 /* builtin */);
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
