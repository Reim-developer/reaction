#ifndef DROPBOX_H
#define DROPBOX_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *dropbox;
    GListModel *device_model_list;
    int width;
    int height;
    int grid_column;
    int grid_row;
    int grid_width;
    int grid_height;
} dropbox_t;

dropbox_t *device_dropbox_new(void);
dropbox_t *list_file_dropbox_new(void);

#endif // DROPBOX_H
