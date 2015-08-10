/* Copyright (c) 2014, Nokia
 * Copyright (c) 2014, ENEA Software AB
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef __OFPI_HOOK_H__
#define __OFPI_HOOK_H__

#include "api/ofp_types.h"
#include "api/ofp_hook.h"

#define OFP_HOOK(_hook_id_, _pkt_, _arg_, _pres_) { \
	ofp_pkt_hook *_pkt_hook_ = ofp_get_packet_hooks(); \
	if (_pkt_hook_ && _pkt_hook_[_hook_id_]) \
		*_pres_ = _pkt_hook_[_hook_id_](_pkt_, _arg_); \
	else \
		*_pres_ = OFP_PKT_CONTINUE; \
}

ofp_pkt_hook *ofp_get_packet_hooks(void);
void ofp_hook_alloc_shared_memory(ofp_pkt_hook *pkt_hook_init);
void ofp_hook_lookup_shared_memory(void);

#endif /* __OFPI_HOOK_H__ */