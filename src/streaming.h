/*
 * Copyright (c) 2010-2011 Luca Abeni
 * Copyright (c) 2010-2011 Csaba Kiraly
 * Copyright (c) 2017 Luca Baldesi
 *
 * This file is part of PeerStreamer.
 *
 * PeerStreamer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * PeerStreamer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with PeerStreamer.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef STREAMING_H
#define STREAMING_H

#include <stdbool.h>
#include <trade_sig_ha.h>
#include <psinstance_internal.h>
#include <input.h>

struct chunk;
struct streaming_context;

void received_chunk(struct streaming_context * strc, struct nodeID *from, const uint8_t *buff, int len);

void send_chunk(struct streaming_context * stc);

struct chunk *generated_chunk(struct streaming_context * strc, suseconds_t *delta);

int add_chunk(struct streaming_context * strc, struct chunk *c);

struct chunkID_set *get_chunks_to_accept(const struct streaming_context * strc, struct nodeID *fromid, const struct chunkID_set *cset_off, int max_deliver, uint16_t trans_id);

void send_offer(struct streaming_context * stc);

void send_accepted_chunks(const struct streaming_context * stc, struct nodeID *to, struct chunkID_set *cset_acc, int max_deliver, uint16_t trans_id);

void send_bmap(const struct streaming_context * strc, const struct nodeID *to);

void log_chunk_error(const struct nodeID *from,const struct nodeID *to,const struct chunk *c,int error);

void log_chunk(const struct nodeID *from,const struct nodeID *to,const struct chunk *c,const char *note);

void log_neighbourhood(const struct streaming_context * stc);

void log_signal(const struct nodeID *fromid,const struct nodeID *toid,const int cidset_size,uint16_t trans_id,enum signaling_type type,const char *flag);

int inject_chunk(struct streaming_context * stc, const struct chunk * target_chunk,const int multiplicity);

struct streaming_context * streaming_create(const struct psinstance * ps, struct input_context * inc, const char * config);

void streaming_destroy(struct streaming_context ** stc);

suseconds_t streaming_offer_interval(const struct streaming_context *stc);

#endif	/* STREAMING_H */
