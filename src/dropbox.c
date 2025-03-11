#include "dropbox.h"

dropbox_t *dropbox_set_new(void) {
    dropbox_t *dropbox_device_t = g_new(dropbox_t, 1);
    GListModel *device_list = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
        "Option 1", "Option 2"
    }));
    dropbox_device_t->device_model_list = device_list;
    dropbox_device_t->dropbox = gtk_drop_down_new(dropbox_device_t->device_model_list, NULL);

    return dropbox_device_t;
}