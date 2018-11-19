#include "eapp_utils.h"
#include "string.h"
#include "syscall.h"
#include "edge_wrapper.h"

void edge_init(){
  /* Nothing for now, will probably register buffers/callsites
     later */
}

#define OCALL_PRINT_BUFFER 1
#define OCALL_PRINT_VALUE 2
#define OCALL_WAIT_FOR_MESSAGE 4
#define OCALL_SEND_REPLY 5

void ocall_print_value(unsigned long val){

  unsigned long val_ = val;
  ocall(OCALL_PRINT_VALUE, &val_, sizeof(unsigned long), 0, 0);

  return;
}

unsigned long ocall_print_buffer(char* data, size_t data_len){

  unsigned long retval;
  ocall(OCALL_PRINT_BUFFER, data, data_len, &retval ,sizeof(unsigned long));

  return retval;
}

edge_data_t ocall_wait_for_message(){

  edge_data_t msg;
  ocall(OCALL_WAIT_FOR_MESSAGE, NULL, 0, &msg, sizeof(edge_data_t));

  return msg;
}