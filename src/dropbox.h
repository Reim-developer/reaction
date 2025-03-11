#ifndef DROPBOX_H
#define DROPBOX_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *dropbox;
    GListModel *device_model_list;
    unsigned int width;
    unsigned int height;
    unsigned int grid_column;
    unsigned int grid_row;
    unsigned int grid_width;
    unsigned int grid_height;
} dropbox_t;

dropbox_t *dropbox_set_new(void);

#endif // DROPBOX_H