/**
 * Copyright (C) Mellanox Technologies Ltd. 2020.  ALL RIGHTS RESERVED.
 * See file LICENSE for terms.
 */

#include "config.h"
#include "ucc_progress_queue.h"

ucc_status_t ucc_pq_st_init(ucc_progress_queue_t **pq);
ucc_status_t ucc_pq_mt_init(ucc_progress_queue_t **pq);

ucc_status_t ucc_progress_queue_init(ucc_progress_queue_t **pq,
                                     ucc_thread_mode_t      tm)
{
    if(tm == UCC_THREAD_SINGLE){
        return ucc_pq_st_init(pq);
    } else { // todo - also for UCC_THREAD_FUNNELED ?
        return ucc_pq_mt_init(pq);
    }
}

void ucc_progress_queue_finalize(ucc_progress_queue_t *pq)
{
    return pq->finalize(pq);
}
