#include "dropbox.h"

dropbox_t *device_dropbox_new(void) {
    dropbox_t *dropbox_device_t = g_new(dropbox_t, 1);
    GListModel *device_list = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
        "No USB found", NULL
    }));
    dropbox_device_t->device_model_list = device_list;
    dropbox_device_t->dropbox = gtk_drop_down_new(dropbox_device_t->device_model_list, NULL);

    dropbox_device_t->grid_column = 4;
    dropbox_device_t->grid_row = 4;

    dropbox_device_t->grid_height = 1;
    dropbox_device_t->grid_width = 10;

    dropbox_device_t->width = 10;
    dropbox_device_t->height = 20;

    gtk_widget_set_size_request(GTK_WIDGET(dropbox_device_t->dropbox),
        dropbox_device_t->width, dropbox_device_t->height
    );

    return dropbox_device_t;
}

dropbox_t *list_file_dropbox_new() {
    dropbox_t *list_file_dropbox_t = g_new(dropbox_t, 1);
    GListModel *list_file_model_t = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
    "No ISO/Image file found", NULL
    }));

    list_file_dropbox_t->device_model_list = list_file_model_t;
    list_file_dropbox_t->dropbox = gtk_drop_down_new(list_file_dropbox_t->device_model_list, NULL);

    list_file_dropbox_t->height = 1;
    list_file_dropbox_t->width = 20;
    
    list_file_dropbox_t->grid_width = 100;
    list_file_dropbox_t->grid_height = 1;

    list_file_dropbox_t->grid_row = 4;
    list_file_dropbox_t->grid_column = 15;

    gtk_widget_set_size_request(GTK_WIDGET(list_file_dropbox_t->dropbox), list_file_dropbox_t->width, list_file_dropbox_t->height);

    return list_file_dropbox_t;
}