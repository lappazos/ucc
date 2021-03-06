/**
 * Copyright (C) Mellanox Technologies Ltd. 2021.  ALL RIGHTS RESERVED.
 * See file LICENSE for terms.
 */

#ifndef UCC_PROC_INFO_H_
#define UCC_PROC_INFO_H_

#include "config.h"
#include "ucc/api/ucc.h"
#include <unistd.h>
#include <stdint.h>
typedef uint32_t ucc_host_id_t;
typedef uint32_t ucc_socket_id_t;

typedef struct ucc_proc_info {
    ucc_host_id_t   host_id;
    ucc_socket_id_t socket_id;
} ucc_proc_info_t;

extern ucc_proc_info_t ucc_local_proc;
extern char ucc_local_hostname[128];

ucc_status_t ucc_local_proc_info_init();

static inline const char*  ucc_hostname() {
    return ucc_local_hostname;
}
#endif
