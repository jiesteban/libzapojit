/*
 * Zapojit - GLib/GObject wrapper for Skydrive and Hotmail
 * Copyright © 2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef ZPJ_SKYDRIVE_H
#define ZPJ_SKYDRIVE_H

#include <glib.h>
#include <glib-object.h>

#include "zpj-authorizer.h"
#include "zpj-skydrive-entry.h"
#include "zpj-skydrive-folder.h"

G_BEGIN_DECLS

#define ZPJ_TYPE_SKYDRIVE (zpj_skydrive_get_type ())

#define ZPJ_SKYDRIVE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   ZPJ_TYPE_SKYDRIVE, ZpjSkydrive))

#define ZPJ_SKYDRIVE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   ZPJ_TYPE_SKYDRIVE, ZpjSkydriveClass))

#define ZPJ_IS_SKYDRIVE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   ZPJ_TYPE_SKYDRIVE))

#define ZPJ_IS_SKYDRIVE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   ZPJ_TYPE_SKYDRIVE))

#define ZPJ_SKYDRIVE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   ZPJ_TYPE_SKYDRIVE, ZpjSkydriveClass))

typedef struct _ZpjSkydrive        ZpjSkydrive;
typedef struct _ZpjSkydriveClass   ZpjSkydriveClass;
typedef struct _ZpjSkydrivePrivate ZpjSkydrivePrivate;

struct _ZpjSkydrive
{
  GObject parent_instance;
  ZpjSkydrivePrivate *priv;
};

struct _ZpjSkydriveClass
{
  GObjectClass parent_class;
};

GType               zpj_skydrive_get_type                    (void) G_GNUC_CONST;

ZpjSkydrive        *zpj_skydrive_new                         (ZpjAuthorizer *authorizer);

gboolean            zpj_skydrive_create_folder               (ZpjSkydrive *self,
                                                              ZpjSkydriveFolder *folder,
                                                              GCancellable *cancellable,
                                                              GError **error);

gboolean            zpj_skydrive_create_folder_from_name     (ZpjSkydrive *self,
                                                              const gchar *name,
                                                              const gchar *parent_id,
                                                              GCancellable *cancellable,
                                                              GError **error);

GList              *zpj_skydrive_list_folder                 (ZpjSkydrive *self,
                                                              ZpjSkydriveFolder *folder,
                                                              GCancellable *cancellable,
                                                              GError **error);

GList              *zpj_skydrive_list_folder_id              (ZpjSkydrive *self,
                                                              const gchar *folder_id,
                                                              GCancellable *cancellable,
                                                              GError **error);

ZpjAuthorizer      *zpj_skydrive_get_authorizer              (ZpjSkydrive *self);

ZpjSkydriveEntry   *zpj_skydrive_query_info_from_id          (ZpjSkydrive *self,
                                                              const gchar *id,
                                                              GCancellable *cancellable,
                                                              GError **error);

void                zpj_skydrive_set_authorizer              (ZpjSkydrive *self, ZpjAuthorizer *authorizer);

gboolean            zpj_skydrive_upload_path_to_folder       (ZpjSkydrive *self,
                                                              const gchar *path,
                                                              ZpjSkydriveFolder *folder,
                                                              GCancellable *cancellable,
                                                              GError **error);

gboolean            zpj_skydrive_upload_path_to_folder_id    (ZpjSkydrive *self,
                                                              const gchar *path,
                                                              const gchar *folder_id,
                                                              GCancellable *cancellable,
                                                              GError **error);

G_END_DECLS

#endif /* ZPJ_SKYDRIVE_H */
