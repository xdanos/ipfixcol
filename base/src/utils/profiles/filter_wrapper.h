/**
 * \file profiles/filter_wrapper.c
 * \author Imrich Štoffa <xstoff02@stud.fit.vutbr.cz>
 * \brief Wrapper of future intermediate plugin for IPFIX data filtering
 *
 * Copyright (C) 2015 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */


#ifndef FILTER_H_
#define FILTER_H_

#include <ipfixcol.h>
#include "ffilter.h"
#include <stdint.h>

#define FPAIR ~0LL
/**
 * \brief Profile structure
 * 
 * Each filter string is representing one filter profile
 */
struct filter_profile {
    ff_t* filter;
    void* buffer;
};

typedef struct nff_item_s {
	const char* name;
	uint64_t en_id;
}nff_item_t;


int specify_ipv(uint16_t *i);

/**
 * \brief Match filter with IPFIX record
 * 
 * \param[in] node filter node
 * \param[in] msg IPFIX message (filter may contain field from message header)
 * \param[in] data IPFIX data record
 * \return 1 when node fits, -1 on error
 */
int filter_eval_node(struct filter_profile *pdata, struct ipfix_message *msg, struct ipfix_record *record);

/**
 * \brief Free profile's data
 * 
 * \param[in] profile Profile
 */
void filter_free_profile(struct filter_profile *profile);


#endif /* FILTER_H_ */
