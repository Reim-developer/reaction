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

dropbox_t *device_dropbox_new(void);
dropbox_t *list_file_dropbox_new(void);

#endif // DROPBOX_H