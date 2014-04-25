/* GStreamer Streaming Server
 * Copyright (C) 2009-2012 Entropy Wave Inc <info@entropywave.com>
 * Copyright (C) 2009-2012 David Schleef <ds@schleef.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */


#ifndef _GSS_METRICS_H
#define _GSS_METRICS_H

#include "gss-config.h"
#include "gss-types.h"

G_BEGIN_DECLS

struct _GssMetrics {
  int n_clients;
  int max_clients;
  gint64 bitrate;
  gint64 max_bitrate;
};

GssMetrics * gss_metrics_new (void);
void gss_metrics_free (GssMetrics * metrics);
void gss_metrics_add_client (GssMetrics * metrics, int bitrate);
void gss_metrics_remove_client (GssMetrics * metrics, int bitrate);

G_END_DECLS

#endif

